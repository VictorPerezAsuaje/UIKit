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

    bool _showMetadata = true;

    void ResetScopedServices();
    void Maximize();
    void Minimize();

public:
    static int width;
    static int height;
    static int fontSize;
    static int fontSpacing;
    static int fontPadding;
    static string title;

    Game();

    void AddScene(shared_ptr<Scene> scene);
    void Run();

    template <typename T>
    static shared_ptr<T> GetService();

    template <typename T>
    void AddSingleton();

    template <typename T>
    void AddTransient();

    template <typename T>
    void AddScoped();
};
