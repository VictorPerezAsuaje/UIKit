#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <raylib.h>

#include "scene.hpp"
#include "sceneManager.hpp"
#include "ui/uiElement.hpp"

using namespace std;

class MenuScene : public Scene
{
public:
    static const string DefaultName;

    MenuScene();
    void Render(SceneManager &manager) override;

protected:
    vector<string> Options = {};
    vector<shared_ptr<UIElement>> GUIElements = {};
    void ChangeToScene(SceneManager &manager, string sceneName);
};
