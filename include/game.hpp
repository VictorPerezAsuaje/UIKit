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
    ServiceCollection serviceCollection;

public:
    static const int Width;
    static const int Height;
    static const int FontSize;
    static const int FontSpacing;
    static const int FontPadding;
    static const string Title;

    template <typename T>
    void AddSingleton()
    {
        serviceCollection.AddSingleton<T>();
    }

    template <typename T>
    void AddTransient()
    {
        serviceCollection.AddTransient<T>();
    }

    template <typename T>
    void AddScoped()
    {
        serviceCollection.AddScoped<T>();
    }

    void Run()
    {
        InitWindow(Width, Height, Title.c_str());
        SetTargetFPS(60);
        shared_ptr<SceneManager> sceneManager = serviceCollection.GetService<SceneManager>();

        while (!WindowShouldClose())
        {
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
