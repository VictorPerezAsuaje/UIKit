#pragma once

#include "globalIncludes.hpp"
#include "scenes/scene.hpp"
#include "scenes/menuScene.hpp"

class PlayScene;
class ConfigurationScene;
class ErrorScene;
class ExitScene;
class MenuScene;

using namespace std;

class SceneManager
{
public:
    void AddScene(shared_ptr<Scene> scene);
    shared_ptr<Scene> GetSceneByName(string sceneName);

    void SetCurrentScene(string sceneName);
    void RenderCurrentScene();
    shared_ptr<Scene> GetCurrentScene();

    bool ShouldExitGame();

private:
    map<string, shared_ptr<Scene>> Scenes = {};
    string CurrentScene = MenuScene::DefaultName;
};
