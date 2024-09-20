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
    _name = DefaultName;
}

#pragma region LIFECYCLE

void PlayScene::Init()
{
    cout << "PlayScene: Init" << endl;
    // Initialize scene variables
    initialized = true;
}

void PlayScene::Load()
{
    cout << "PlayScene: Load" << endl;
    // Load menu-specific resources (e.g., textures, sounds)
}

void PlayScene::Update()
{
}

void PlayScene::Render()
{
    DrawText("You are playing", (float)MeasureTextEx(GetFontDefault(), "You are playing", Game::fontSize, 0).x, (float)MeasureTextEx(GetFontDefault(), "You are playing", Game::fontSize, 0).y, Game::fontSize, WHITE);

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        Game::_sceneManager->SetCurrentScene(MenuScene::DefaultName);
    }
}

void PlayScene::Unload()
{
    cout << "PlayScene: Unload" << endl;
    // Unload any resources that need to be freed
}

#pragma endregion LIFECYCLE

