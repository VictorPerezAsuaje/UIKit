#include "globalIncludes.hpp"

#include "game.hpp"
#include "sceneManager.hpp"
#include "ui/uiButton.hpp"

#include "scenes/menuScene.hpp"
#include "scenes/configurationScene.hpp"

using namespace std;

const string ConfigurationScene::DefaultName = "Configuration";

ConfigurationScene::ConfigurationScene() : Scene()
{
    Name = ConfigurationScene::DefaultName;
    _tabButtonArea = {0, 0, (float)(Game::width * 0.2), (float)Game::height};

    int spacing = Game::fontSpacing * 2;
    _tabConfigArea = {_tabButtonArea.width + spacing, (float)spacing, Game::width - _tabButtonArea.width - 2 * spacing, (float)Game::height - 2 * spacing};
}

void ConfigurationScene::Render()
{
    if (TabButtons.size() == 0)
    {
        LoadTabButtons();
    }

    Texture2D bg = Game::GetResource(0);
    DrawTextureEx(bg, (Vector2){0, 0}, 0, Game::GetScreenWidthRatio(bg.width), WHITE);
    DrawRectangle(0, 0, Game::width, Game::height, Color(0, 0, 0, 128));

    DrawRectangle(_tabConfigArea.x, _tabConfigArea.y, _tabConfigArea.width, _tabConfigArea.height, Color(0, 0, 0, 64));

    for (int i = 0; i < (int)TabButtons.size(); i++)
    {
        UIButton button = TabButtons[i];
        button.BaseColor = _selectedTab == i ? BLUE : GRAY;
        button.Update();
    }

    switch (_selectedTab)
    {
    case 0:
    default:
        ShowDisplayOptions();
        break;
    case 1:
        ShowSoundOptions();
        break;
    }
}

#pragma region PRIVATE_METHODS

void ConfigurationScene::AddTabButton(string text, function<void()> callback)
{
    float x = Game::fontSpacing;
    float y = (TabButtons.size() + 1) * Game::fontSpacing;

    UIButton button = UIButton();
    button.Position = Vector2(x, 2 * y);
    button.Size = Vector2(_tabButtonArea.width, (float)Game::fontSize + Game::fontPadding);
    button.Text = text;
    button.Container = _tabButtonArea;
    button.OnClickFunc = callback;

    TabButtons.insert(TabButtons.end(), button);    
}

void ConfigurationScene::LoadTabButtons()
{
    AddTabButton("DISPLAY", [this]() { _selectedTab = 0; });

    AddTabButton("SOUND", [this]() { _selectedTab = 1; });

    AddTabButton("BACK TO MENU", [this]() { this->BackToMenu(); });
}

void ConfigurationScene::ShowDisplayOptions()
{
    cout << "Here there from DISPLAY!" << endl;
    DrawText("Display label option 1:", (int)_tabConfigArea.x, (int)_tabConfigArea.y, Game::fontSize, WHITE);
}

void ConfigurationScene::ShowSoundOptions()
{
    cout << "Here there from SOUND!" << endl;
}

void ConfigurationScene::BackToMenu()
{
    _selectedTab = 0;
    _manager->SetCurrentScene(MenuScene::DefaultName);
}

#pragma endregion PRIVATE_METHODS
