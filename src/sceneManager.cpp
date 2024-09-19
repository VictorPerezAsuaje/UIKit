#include "globalIncludes.hpp"

#include "sceneManager.hpp"
#include "scenes/menuScene.hpp"
#include "scenes/playScene.hpp"
#include "scenes/exitScene.hpp"

using namespace std;

template <IsScene T>
void SceneManager::AddScene(shared_ptr<T> scene)
{
    if (Scenes.contains(typeid(T)) == 1)
    {
        throw invalid_argument(format("Scene {} is duplicated.", typeid(T).name()));
    }

    Scenes[typeid(T)] = scene;
}

void SceneManager::RenderCurrentScene()
{
    GetCurrentScene()->Render();
}

shared_ptr<Scene> SceneManager::GetCurrentScene()
{
    return Scenes[CurrentScene];
}

template <IsScene T>
void SceneManager::SetCurrentScene()
{
    if (Scenes.contains(typeid(T)) == 0)
    {
        throw invalid_argument(format("Scene {} not found.", typeid(T).name()));
    }

    CurrentScene = typeid(T);
}

template <IsScene T>
shared_ptr<T> SceneManager::GetScene()
{
    if (Scenes.contains(typeid(T)) == 0)
    {
        throw invalid_argument(format("Scene {} not found.", typeid(T).name()));
    }

    return Scenes[typeid(T)];
}

bool SceneManager::ShouldExitGame()
{
    return CurrentScene == typeid(ExitScene);
}