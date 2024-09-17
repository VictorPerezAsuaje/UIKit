#include "globalIncludes.hpp"

#include "serviceCollection.hpp"
#include "game.hpp"

#include "sceneManager.hpp"
#include "scenes/errorScene.hpp"

using namespace std;

#pragma region PRIVATE_PROPS
int Game::width = 1280;
int Game::height = 720;
int Game::fontSize = 20;
int Game::fontSpacing = 32;
int Game::fontPadding = 16;
string Game::title = "Scene Manager Test";
map<int, Texture2D> Game::_resources = {};

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

void Game::AddResource(int position, string resource)
{
    if (_resources.count(position) == 1)
    {
        throw invalid_argument("The position " + to_string(position) + " already contains a resource.");
    }

    _resources[position] = LoadTexture(resource.c_str());
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

void Game::LoadResources()
{
    AddResource(0, "resources/ui-menu-bg.png");
}

void Game::UnloadResources()
{
    for (auto resource : _resources)
    {
        UnloadTexture(resource.second);
    }
}

Texture2D Game::GetResource(int position)
{
    if (_resources.count(position) == 0)
    {
        throw invalid_argument("The position " + to_string(position) + " does not exist nor contain a resource.");
    }

    return _resources[position];
}

float Game::GetScreenWidthRatio(float width)
{
    return (float)((float)Game::width / width);
}

float Game::GetScreenHeightRatio(float height)
{
    return (float)((float)Game::height / height);
}

float Game::GetProportionalWidthToScreen(float width)
{
    return width * (float)((float)Game::width / width);
}

float Game::GetProportionalHeightToScreen(float height)
{
    return height * (float)((float)Game::height / height);
}

void Game::Run()
{
    InitWindow(width, height, title.c_str());

    LoadResources();
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
            cerr << "Exception caught: " << e.what() << endl;
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

    UnloadResources();
    CloseWindow();
}

#pragma endregion PUBLIC_METHODS