#pragma once

#include "globalIncludes.hpp"
#include "ui/uiButton.hpp"
#include "scenes/scene.hpp"

class SceneManager;

using namespace std;

class MenuScene : public Scene
{
public:
    MenuScene();

    void Render() override;

protected:
    vector<UIButton> MenuButtons = {};

    template <IsScene T>
    void ChangeToScene();
    void LoadMenuButtons();
};
