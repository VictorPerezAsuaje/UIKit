#pragma once

#include "globalIncludes.hpp"
#include "ui/uiPanel.hpp"
#include "scenes/scene.hpp"

using namespace std;

class UIButton;

class ConfigurationScene : public Scene
{
public:
    static const string DefaultName;
    ConfigurationScene();

    void Init() override;
    void Load() override;
    void Update() override;
    void Render() override;
    void Unload() override;

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
