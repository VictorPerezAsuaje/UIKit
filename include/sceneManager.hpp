#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "scenes/scene.hpp"
#include "scenes/playScene.hpp"
#include "scenes/exitScene.hpp"
#include "scenes/menuScene.hpp"

using namespace std;

class SceneManager
{
public:
    SceneManager();

    void RenderCurrentScene();

    shared_ptr<Scene> GetCurrentScene();
    void SetCurrentScene(string sceneName);

    shared_ptr<Scene> GetSceneByName(string sceneName);
    bool ShouldExitGame();

private:
    map<string, shared_ptr<Scene>> Scenes = {};
    string CurrentScene;
};
