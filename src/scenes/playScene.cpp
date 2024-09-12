#include <iostream>
#include <vector>
#include <format>

#include "game.hpp"
#include "scenes/playScene.hpp"
#include "sceneManager.hpp"

using namespace std;

const string PlayScene::DefaultName = "Play";

PlayScene::PlayScene() : Scene()
{
    Name = DefaultName;
}

void PlayScene::Render()
{
    DrawText("You are playing", (float)MeasureTextEx(GetFontDefault(), "You are playing", Game::FontSize, 0).x, (float)MeasureTextEx(GetFontDefault(), "You are playing", Game::FontSize, 0).y, Game::FontSize, WHITE);

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        _manager->SetCurrentScene(MenuScene::DefaultName);
    }
}