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
    _name = DefaultName;
}

void ExitScene::Init()
{
    cout << "ExitScene: Init" << endl;
    // Initialize scene variables
    initialized = true;
}

void ExitScene::Load()
{
    cout << "ExitScene: Load" << endl;
    // Load menu-specific resources (e.g., textures, sounds)
}

void ExitScene::Render()
{
    
}

void ExitScene::Update()
{
}

void ExitScene::Unload()
{
    cout << "ExitScene: Unload" << endl;
    // Unload any resources that need to be freed
}
