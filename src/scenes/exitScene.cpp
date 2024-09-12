#include <iostream>
#include <vector>
#include <format>
#include <raylib.h>

#include "scenes/exitScene.hpp"
#include "sceneManager.hpp"

using namespace std;

const string ExitScene::DefaultName = "Exit";

ExitScene::ExitScene() : Scene()
{
    Name = DefaultName;
}

void ExitScene::Render()
{
}