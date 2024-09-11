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

    void Run()
    {
        InitWindow(Width, Height, Title.c_str());
        SetTargetFPS(60);
        shared_ptr<SceneManager> sceneManager = GetService<SceneManager>();

        while (!WindowShouldClose())
        {
            // We clear scoped services on a per-frame basis
            ResetScopedServices();

            BeginDrawing();

            // You need to clear background, otherwise it keeps "drawing" the circle each iteration without removing the last
            ClearBackground(BLACK);

            sceneManager->RenderCurrentScene();

            if (sceneManager->ShouldExitGame())
            {
                break;
            }

            EndDrawing();
        }

        CloseWindow();
    }
};
