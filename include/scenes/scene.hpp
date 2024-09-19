#pragma once

#include "globalIncludes.hpp"

using namespace std;

class SceneManager;

class Scene
{
public:
    virtual void Render() = 0;
    Scene();

protected:
    shared_ptr<SceneManager> _manager;
};
