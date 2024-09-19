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
    SceneManager(){}

    template <IsScene T>
    void AddScene(shared_ptr<T> scene);

    template <IsScene T>
    shared_ptr<T> GetScene();

    shared_ptr<Scene> GetCurrentScene();

    template <IsScene T>
    void SetCurrentScene();

    void RenderCurrentScene();
    bool ShouldExitGame();

private:
    unordered_map<type_index, shared_ptr<Scene>> Scenes = {};
    type_index CurrentScene = typeid(MenuScene);
};
