#include "globalIncludes.hpp"

#include "game.hpp"

#include "ui/uiButton.hpp"

#include "sceneManager.hpp"
#include "scenes/scene.hpp"
#include "scenes/menuScene.hpp"
#include "scenes/playScene.hpp"
#include "scenes/exitScene.hpp"
#include "scenes/configurationScene.hpp"

using namespace std;

const string MenuScene::DefaultName = "Menu";

MenuScene::MenuScene() : Scene()
{
    _name = MenuScene::DefaultName;
    Options = {PlayScene::DefaultName, ConfigurationScene::DefaultName, ExitScene::DefaultName};
}

#pragma region LIFECYCLE

void MenuScene::Init()
{
    cout << "MenuScene: Init" << endl;
    // Initialize scene variables
    initialized = true;
}

void MenuScene::Load()
{
    cout << "MenuScene: Load" << endl;
    // Load menu-specific resources (e.g., textures, sounds)
}

void MenuScene::Update()
{
    
}

void MenuScene::Render()
{
    if (MenuButtons.size() == 0)
    {
        LoadMenuButtons();
    }

    Texture2D bg = Game::GetResource(0);
    DrawTextureEx(bg, (Vector2){0, 0}, 0, Game::GetScreenWidthRatio(bg.width), WHITE);
    DrawRectangle(0, 0, Game::width, Game::height, Color(0, 0, 0, 128));

    for (UIButton button : MenuButtons)
    {
        button.Update();
    }
}

void MenuScene::Unload()
{
    cout << "MenuScene: Unload" << endl;
    // Unload any resources that need to be freed
}

#pragma endregion LIFECYCLE


void MenuScene::ChangeToScene(string sceneName)
{
    Game::_sceneManager->SetCurrentScene(sceneName);
}

void MenuScene::LoadMenuButtons()
{
    int i = 0;
    for (string optionName : Options)
    {
        int spacing = i * Game::fontSpacing;
        auto uppercased = TextToUpper(optionName.c_str());
        Vector2 textAxis = MeasureTextEx(GetFontDefault(), uppercased, Game::fontSize, 0);

        float x = (Game::width - textAxis.x) / 2;
        float y = (Game::height - textAxis.y) / 2 + spacing * 2;

        float width = (float)MeasureText(uppercased, Game::fontSize) + Game::fontPadding;
        float height = (float)Game::fontSize + Game::fontPadding;

        UIButton button = UIButton((int)x, (int)y, width, height);
        button.Text = uppercased;
        button.OnClickFunc = [this, optionName = optionName]()
        {
            this->ChangeToScene(optionName);
        };

        MenuButtons.push_back(button);
        i++;
    }
}

