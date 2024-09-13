#pragma once

#include "globalIncludes.hpp"

using namespace std;

class SceneManager;

class Scene
{
public:
    string GetName();
    virtual void Render() = 0;
    Scene();

protected:
    string Name;
    shared_ptr<SceneManager> _manager;
};
