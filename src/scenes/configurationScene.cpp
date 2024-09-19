#include "globalIncludes.hpp"

#include "game.hpp"
#include "sceneManager.hpp"
#include "ui/uiButton.hpp"

#include "scenes/menuScene.hpp"
#include "scenes/configurationScene.hpp"

using namespace std;

ConfigurationScene::ConfigurationScene() : Scene()
{
    _tabButtonArea = UIPanel(0, 0, Game::width * 0.2, Game::height);
    _tabButtonArea.BaseColor = Color(0, 0, 0, 0);

    int spacing = Game::fontSpacing * 2;

    Rectangle buttonRect = _tabButtonArea.GetPosition();
    _tabConfigArea = UIPanel(buttonRect.width + spacing, spacing, Game::width - buttonRect.width - 2 * spacing, (float)Game::height - 2 * spacing);

    _tabConfigArea.BaseColor = Color(0, 0, 0, 64);
}

void ConfigurationScene::Render()
{
    if (_tabButtonArea.Children.size() == 0)
    {
        LoadTabButtons();
    }

    Texture2D bg = Game::GetResource(0);
    DrawTextureEx(bg, (Vector2){0, 0}, 0, Game::GetScreenWidthRatio(bg.width), WHITE);
    DrawRectangle(0, 0, Game::width, Game::height, Color(0, 0, 0, 128));

    _tabConfigArea.Update();
    _tabButtonArea.Update();

    if(_selectedTab == "Display"){
        ShowDisplayOptions();
    }
    else if(_selectedTab == "Sound"){
        ShowSoundOptions();
    }
}

#pragma region PRIVATE_METHODS

void ConfigurationScene::AddTabButton(string id, string text, function<void()> callback)
{
    float y = (_tabButtonArea.Children.size() + 1) * Game::fontSpacing;

    Rectangle areaRect = _tabButtonArea.GetPosition();
    UIButton btn = UIButton(0, y * 2, areaRect.width, (float)Game::fontSize + Game::fontPadding);

    shared_ptr<UIButton> button = make_shared<UIButton>(btn);
    button->id = id;
    button->Text = text;
    button->Parent = &_tabButtonArea;
    button->OnClickFunc = callback;

    _tabButtonArea.AddChild(button);
}

void ConfigurationScene::SelectTab(string tabId){
    _selectedTab = tabId;
    for(auto btn : _tabButtonArea.Children){
        if(btn->id == _selectedTab){
            btn->BaseColor = BLUE;
            continue;
        }

        btn->BaseColor = GRAY;
    }
}

void ConfigurationScene::LoadTabButtons()
{
    AddTabButton("Display", "DISPLAY", [this](){ SelectTab("Display"); });

    AddTabButton("Sound", "SOUND", [this](){ SelectTab("Sound"); });

    AddTabButton("", "BACK TO MENU", [this](){ this->BackToMenu(); });
}

void ConfigurationScene::ShowDisplayOptions()
{
    Rectangle rect = _tabConfigArea.GetPosition();
    DrawText("Display label option 1:", rect.x, rect.y, Game::fontSize, WHITE);
}

void ConfigurationScene::ShowSoundOptions()
{
    Rectangle rect = _tabConfigArea.GetPosition();
    DrawText("Sound label option 1:", rect.x, rect.y, Game::fontSize, WHITE);
}

void ConfigurationScene::BackToMenu()
{
    _selectedTab = "Display";
    _manager->SetCurrentScene<MenuScene>();
}

#pragma endregion PRIVATE_METHODS
