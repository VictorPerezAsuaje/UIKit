#pragma once

#include "globalIncludes.hpp"
#include "scenes/scene.hpp"

using namespace std;

class UIButton;

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
