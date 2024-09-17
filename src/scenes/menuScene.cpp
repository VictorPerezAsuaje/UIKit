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
    Name = MenuScene::DefaultName;
    Options = {PlayScene::DefaultName, ConfigurationScene::DefaultName, ExitScene::DefaultName};
}

void MenuScene::ChangeToScene(string sceneName)
{
    _manager->SetCurrentScene(sceneName);
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

        UIButton button = UIButton();
        button.Position = Vector2(x, y);
        button.Size = Vector2(width, height);
        button.Text = uppercased;
        button.OnClickFunc = [this, optionName = optionName]()
        {
            this->ChangeToScene(optionName);
        };

        MenuButtons.insert(MenuButtons.end(), button);
        i++;
    }
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