#pragma once

#include "globalIncludes.hpp"

class Scene;
class SceneManager;
class ServiceCollection;

using namespace std;

class Game
{
private:
    static unique_ptr<ServiceCollection> _serviceCollection;
    
    static map<int, Texture2D> _resources;

    bool _showMetadata = true;

    void ResetScopedServices();
    void AddResource(int position, string resource);
    void UnloadResources();

    void Maximize();
    void Minimize();

public:
    static int width;
    static int height;
    static int fontSize;
    static int fontSpacing;
    static int fontPadding;
    static string title;

    static unique_ptr<SceneManager> _sceneManager;

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

    void LoadResources();
    static Texture2D GetResource(int position);

    static float GetScreenWidthRatio(float width);
    static float GetScreenHeightRatio(float height);

    static float GetProportionalWidthToScreen(float width);
    static float GetProportionalHeightToScreen(float height);
};
