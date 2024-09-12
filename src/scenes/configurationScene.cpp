#include <iostream>
#include <vector>
#include <format>
#include <memory>
#include <raylib.h>

#include "game.hpp"
#include "scenes/configurationScene.hpp"
#include "ui/uiButton.hpp"

using namespace std;

const string ConfigurationScene::DefaultName = "Configuration";

void ConfigurationScene::AddTabButton(string text, function<void()> callback)
{
    int spacing = TabButtons.size() * Game::fontSpacing;

    Vector2 textAxis = MeasureTextEx(GetFontDefault(), text.c_str(), Game::fontSize, 0);

    float x = (Game::width - textAxis.x) / 2;
    float y = (Game::height - textAxis.y) / 2 + spacing * 2;

    float width = (float)MeasureText(text.c_str(), Game::fontSize) + Game::fontPadding;
    float height = (float)Game::fontSize + Game::fontPadding;

    UIButton button = UIButton();
    button.Position = Vector2(x, y);
    button.Size = Vector2(width, height);
    button.Text = text;
    button.OnClickFunc = callback;
}

void ConfigurationScene::LoadTabButtons()
{
    AddTabButton("DISPLAY", []()
                 { cout << "Here there from DISPLAY!" << endl; });

    AddTabButton("SOUND", []()
                 { cout << "Here there from SOUND!" << endl; });
}

#pragma endregion PRIVATE_METHODS

ConfigurationScene::ConfigurationScene() : Scene()
{
    Name = MenuScene::DefaultName;
}

void ConfigurationScene::Render()
{
    if (TabButtons.size() == 0)
    {
        LoadTabButtons();
    }

    for (UIButton button : TabButtons)
    {
        button.Update();
    }
}