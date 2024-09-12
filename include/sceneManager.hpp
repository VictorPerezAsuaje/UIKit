#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "scenes/scene.hpp"
#include "scenes/playScene.hpp"
#include "scenes/configurationScene.hpp"
#include "scenes/errorScene.hpp"
#include "scenes/exitScene.hpp"
#include "scenes/menuScene.hpp"

using namespace std;

class SceneManager
{
public:
    void AddScene(shared_ptr<Scene> scene);
    shared_ptr<Scene> GetSceneByName(string sceneName);

    shared_ptr<Scene> GetCurrentScene();
    void SetCurrentScene(string sceneName);
    void RenderCurrentScene();

    bool ShouldExitGame();

private:
    map<string, shared_ptr<Scene>> Scenes = {};
    string CurrentScene = MenuScene::DefaultName;
};
