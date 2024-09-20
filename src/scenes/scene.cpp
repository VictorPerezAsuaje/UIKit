#include <iostream>
#include <vector>
#include <format>

#include "scenes/scene.hpp"
#include "game.hpp"

using namespace std;

Scene::Scene() : initialized(false)
{
    
}

string Scene::GetName()
{
    return _name;
}

bool Scene::IsInitialized()
{
    return initialized;
}
