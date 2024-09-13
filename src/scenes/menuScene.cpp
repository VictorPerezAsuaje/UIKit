#include "globalIncludes.hpp"

#include "game.hpp"

#include "sceneManager.hpp"
#include "scenes/scene.hpp"
#include "scenes/menuScene.hpp"
#include "scenes/playScene.hpp"
#include "scenes/exitScene.hpp"
#include "scenes/configurationScene.hpp"
#include "ui/uiButton.hpp"

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

        Vector2 textAxis = MeasureTextEx(GetFontDefault(), optionName.c_str(), Game::fontSize, 0);

        float x = (Game::width - textAxis.x) / 2;
        float y = (Game::height - textAxis.y) / 2 + spacing * 2;

        float width = (float)MeasureText(optionName.c_str(), Game::fontSize) + Game::fontPadding;
        float height = (float)Game::fontSize + Game::fontPadding;

        UIButton button = UIButton();
        button.Position = Vector2(x, y);
        button.Size = Vector2(width, height);
        button.Text = optionName;
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

    for (UIButton button : MenuButtons)
    {
        button.Update();
    }
}