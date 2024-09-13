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
    if (Scenes.count(scene->GetName()) == 1)
    {
        throw invalid_argument("Scene " + scene->GetName() + " is duplicated.");
    }

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
    if (Scenes.count(sceneName) == 0)
    {
        throw invalid_argument("Scene " + sceneName + " not found ");
    }

    CurrentScene = sceneName;
}

shared_ptr<Scene> SceneManager::GetSceneByName(string sceneName)
{
    if (Scenes.count(sceneName) == 0)
    {
        throw invalid_argument("Scene " + sceneName + " not found ");
    }

    return Scenes[sceneName];
}

bool SceneManager::ShouldExitGame()
{
    return CurrentScene == ExitScene::DefaultName;
}