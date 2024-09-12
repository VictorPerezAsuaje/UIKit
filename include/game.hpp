#pragma once

#include <iostream>
#include <vector>
#include <raylib.h>

#include "sceneManager.hpp"
#include "serviceCollection.hpp"

using namespace std;

class Game
{
private:
    static unique_ptr<ServiceCollection> _serviceCollection;
    shared_ptr<SceneManager> _sceneManager;

    void ResetScopedServices()
    {
        vector<shared_ptr<ServiceDescriptor>> scoped = _serviceCollection->GetScopedServices();
        for (auto service : scoped)
        {
            service->ResetScopedInstance();
        }
    }

public:
    static const int Width;
    static const int Height;
    static const int FontSize;
    static const int FontSpacing;
    static const int FontPadding;
    static const string Title;

    Game()
    {
        _serviceCollection = make_unique<ServiceCollection>(ServiceCollection());
        _serviceCollection->AddSingleton<SceneManager>();
        _sceneManager = GetService<SceneManager>();
    }

    template <typename T>
    static shared_ptr<T> GetService()
    {
        auto descriptor = _serviceCollection->GetServiceDescriptor(typeid(T));
        return static_pointer_cast<T>(descriptor->CreateInstance());
    }

    template <typename T>
    void AddSingleton()
    {
        _serviceCollection->AddSingleton<T>();
    }

    template <typename T>
    void AddTransient()
    {
        _serviceCollection->AddTransient<T>();
    }

    template <typename T>
    void AddScoped()
    {
        _serviceCollection->AddScoped<T>();
    }

    void AddScene(shared_ptr<Scene> scene)
    {
        _sceneManager->AddScene(scene);
    }

    void Run()
    {
        InitWindow(Width, Height, Title.c_str());
        SetTargetFPS(60);

        while (!WindowShouldClose())
        {
            // We clear scoped services on a per-frame basis
            ResetScopedServices();

            BeginDrawing();

            // You need to clear background, otherwise it keeps "drawing" the circle each iteration without removing the last
            ClearBackground(BLACK);

            _sceneManager->RenderCurrentScene();

            if (_sceneManager->ShouldExitGame())
            {
                break;
            }

            EndDrawing();
        }

        CloseWindow();
    }
};
