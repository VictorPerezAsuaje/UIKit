#pragma once

#include "globalIncludes.hpp"
#include "ui/uiPanel.hpp"
#include "scenes/scene.hpp"

using namespace std;

class UIButton;

class ConfigurationScene : public Scene
{
public:
    ConfigurationScene();

    void Render() override;

protected:
    UIPanel _tabButtonArea = UIPanel();
    UIPanel _tabConfigArea = UIPanel();    

    vector<UIButton> TabButtons = {};
    string _selectedTab = "Display";

    void AddTabButton(string id, string text, function<void()> callback);
    void LoadTabButtons();
    void SelectTab(string tabId);

    void ShowDisplayOptions();
    void ShowSoundOptions();
    void BackToMenu();
};
