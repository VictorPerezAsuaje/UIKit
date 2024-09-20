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

    void Init() override;
    void Load() override;
    void Update() override;
    void Render() override;
    void Unload() override;

protected:
    vector<string> Options = {};
    vector<UIButton> MenuButtons = {};

    void ChangeToScene(string sceneName);
    void LoadMenuButtons();
};
