#include <iostream>
#include <vector>
#include <format>
#include <memory>
#include <raylib.h>

#include "game.hpp"
#include "scenes/menuScene.hpp"
#include "scenes/playScene.hpp"
#include "scenes/exitScene.hpp"
#include "ui/uiButton.hpp"

using namespace std;

const string MenuScene::DefaultName = "Menu";

MenuScene::MenuScene()
{
    Name = MenuScene::DefaultName;
    Options.insert(Options.end(), PlayScene::DefaultName);
    Options.insert(Options.end(), ExitScene::DefaultName);
}

void MenuScene::ChangeToScene(SceneManager &manager, string sceneName) { manager.SetCurrentScene(sceneName); }
void MenuScene::Render(SceneManager &manager)
{
    int i = 0;
    for (string optionName : Options)
    {
        int spacing = i * Game::FontSpacing;

        Vector2 textAxis = MeasureTextEx(GetFontDefault(), optionName.c_str(), Game::FontSize, 0);

        float x = (Game::Width - textAxis.x) / 2;
        float y = (Game::Height - textAxis.y) / 2 + spacing * 2;

        float width = (float)MeasureText(optionName.c_str(), Game::FontSize) + Game::FontPadding;
        float height = (float)Game::FontSize + Game::FontPadding;

        UIButton button = UIButton(Vector2(x, y), Vector2(width, height), GRAY, optionName, BLUE);
        button.OnClickFunc = [this, &manager = manager, optionName = optionName]()
        {
            this->ChangeToScene(manager, optionName);
        };

        button.Draw();
        i++;
    }
}