#include <iostream>
#include <vector>
#include <format>
#include <memory>

#include "sceneManager.hpp"
#include "scenes/menuScene.hpp"
#include "scenes/playScene.hpp"
#include "scenes/exitScene.hpp"

using namespace std;

void SceneManager::AddScene(shared_ptr<Scene> scene)
{
    Scenes[scene->GetName()] = scene;
}

void SceneManager::RenderCurrentScene()
{
    GetCurrentScene()->Render();
}

shared_ptr<Scene> SceneManager::GetCurrentScene()
{
    return Scenes[CurrentScene];
}

void SceneManager::SetCurrentScene(string sceneName)
{
    if (Scenes.find(sceneName) != Scenes.end())
    {
        CurrentScene = sceneName;
    }
}

shared_ptr<Scene> SceneManager::GetSceneByName(string sceneName)
{
    return Scenes[sceneName];
}

bool SceneManager::ShouldExitGame()
{
    return CurrentScene == ExitScene::DefaultName;
}