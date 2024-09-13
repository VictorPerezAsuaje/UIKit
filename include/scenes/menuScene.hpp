#pragma once

#include "globalIncludes.hpp"
#include "ui/uiButton.hpp"
#include "scenes/scene.hpp"

class SceneManager;

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
