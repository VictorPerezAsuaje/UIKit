#include <iostream>
#include <vector>
#include <format>
#include <memory>
#include <raylib.h>

#include "scenes/errorScene.hpp"
#include "sceneManager.hpp"
#include "game.hpp"

using namespace std;

const string ErrorScene::DefaultName = "Error";

ErrorScene::ErrorScene() : Scene()
{
    Name = DefaultName;
}

void ErrorScene::RegisterException(const exception &ex)
{
    _message = ex.what();
}

void ErrorScene::Render()
{
    int x = MeasureText(_message.c_str(), Game::fontSize) / 2;
    DrawText(_message.c_str(), Game::width / 2 - x, Game::height / 2, Game::fontSize, WHITE);

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        _manager->SetCurrentScene(MenuScene::DefaultName);
    }
}