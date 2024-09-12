#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <raylib.h>

#include "scene.hpp"
#include "sceneManager.hpp"
#include "ui/uiButton.hpp"

using namespace std;

class MenuScene : public Scene
{
public:
    static const string DefaultName;

    MenuScene();

    void Render() override;

protected:
    vector<string> Options = {};
    vector<UIButton> MenuButtons = {};

    void ChangeToScene(string sceneName);
    void LoadMenuButtons();
};
