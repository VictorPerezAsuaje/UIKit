#include <iostream>
#include <vector>
#include <format>

#include "game.hpp"
#include "scenes/errorScene.hpp"

using namespace std;

#pragma region PRIVATE_PROPS
int Game::width = 1280;
int Game::height = 720;
int Game::fontSize = 24;
int Game::fontSpacing = 32;
int Game::fontPadding = 16;
string Game::title = "Scene Manager Test";

unique_ptr<ServiceCollection> Game::_serviceCollection;

#pragma endregion PRIVATE_PROPS

#pragma region PRIVATE_METHODS

Game::Game()
{
    _serviceCollection = make_unique<ServiceCollection>(ServiceCollection());
    _serviceCollection->AddSingleton<SceneManager>();
    _sceneManager = GetService<SceneManager>();
}

void Game::ResetScopedServices()
{
    vector<shared_ptr<ServiceDescriptor>> scoped = _serviceCollection->GetScopedServices();
    for (auto service : scoped)
    {
        service->ResetScopedInstance();
    }
}

void Game::Maximize()
{
}

void Game::Minimize()
{
}

#pragma endregion PRIVATE_METHODS

#pragma region PUBLIC_METHODS

template <typename T>
shared_ptr<T> Game::GetService()
{
    auto descriptor = _serviceCollection->GetServiceDescriptor(typeid(T));
    return static_pointer_cast<T>(descriptor->CreateInstance());
}

template <typename T>
void Game::AddSingleton()
{
    _serviceCollection->AddSingleton<T>();
}

template <typename T>
void Game::AddTransient()
{
    _serviceCollection->AddTransient<T>();
}

template <typename T>
void Game::AddScoped()
{
    _serviceCollection->AddScoped<T>();
}

void Game::AddScene(shared_ptr<Scene> scene)
{
    _sceneManager->AddScene(scene);
}

void Game::Run()
{
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // We clear scoped services on a per-frame basis
        ResetScopedServices();

        BeginDrawing();
        ClearBackground(BLACK);

        try
        {
            _sceneManager->RenderCurrentScene();

            if (_sceneManager->ShouldExitGame())
            {
                break;
            }

            if (IsKeyPressed(KEY_F2))
            {
                _showMetadata = !_showMetadata;
            }

            if (_showMetadata)
            {
                DrawFPS(10, 10);
            }
        }
        catch (const exception &e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
            if (_sceneManager == nullptr)
            {
                EndDrawing();
                continue;
            }

            static_pointer_cast<ErrorScene>(_sceneManager->GetSceneByName(ErrorScene::DefaultName))
                ->RegisterException(e);

            _sceneManager->SetCurrentScene(ErrorScene::DefaultName);
        }

        EndDrawing();
    }

    CloseWindow();
}

#pragma endregion PUBLIC_METHODS