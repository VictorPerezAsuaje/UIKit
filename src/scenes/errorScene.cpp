#include <iostream>
#include <vector>
#include <format>
#include <memory>
#include <raylib.h>

#include "scenes/errorScene.hpp"
#include "sceneManager.hpp"

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
    cout << "This is the message: " + _message << endl;
    // DrawText(Text.c_str(), Position.x + Game::fontPadding / 2, Position.y + Game::fontPadding / 2, Game::fontSize, WHITE);
}