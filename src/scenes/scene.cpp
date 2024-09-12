#include <iostream>
#include <vector>
#include <format>

#include "scenes/scene.hpp"
#include "game.hpp"

using namespace std;

Scene::Scene()
{
    _manager = Game::GetService<SceneManager>();
}

string Scene::GetName()
{
    return Name;
}
