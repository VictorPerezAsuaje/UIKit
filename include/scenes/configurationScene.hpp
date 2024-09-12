#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <raylib.h>

#include "scene.hpp"
#include "sceneManager.hpp"
#include "ui/uiButton.hpp"

using namespace std;

class ConfigurationScene : public Scene
{
public:
    static const string DefaultName;

    ConfigurationScene();

    void Render() override;

protected:
    vector<UIButton> TabButtons = {};

    void AddTabButton(string text, function<void()> callback);
    void LoadTabButtons();
};
