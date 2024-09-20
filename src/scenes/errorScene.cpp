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
    _name = DefaultName;
}

void ErrorScene::Init()
{
    cout << "ErrorScene: Init" << endl;
    // Initialize scene variables
    initialized = true;
}

void ErrorScene::Load()
{
    cout << "ErrorScene: Load" << endl;
    // Load menu-specific resources (e.g., textures, sounds)
}

void ErrorScene::Render()
{
    int x = MeasureText(_message.c_str(), Game::fontSize) / 2;
    DrawText(_message.c_str(), Game::width / 2 - x, Game::height / 2, Game::fontSize, WHITE);

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        Game::_sceneManager->SetCurrentScene(MenuScene::DefaultName);
    }
}

void ErrorScene::Update()
{
}

void ErrorScene::Unload()
{
    cout << "ErrorScene: Unload" << endl;
    // Unload any resources that need to be freed
}

void ErrorScene::RegisterException(const exception &ex)
{
    _message = ex.what();
}
