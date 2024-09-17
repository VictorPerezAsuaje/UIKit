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
    Rectangle _tabButtonArea = {0,0,0,0};
    Rectangle _tabConfigArea = {0,0,0,0};

    vector<UIButton> TabButtons = {};
    int _selectedTab;

    void AddTabButton(string text, function<void()> callback);
    void LoadTabButtons();

    void ShowDisplayOptions();
    void ShowSoundOptions();
    void BackToMenu();
};
