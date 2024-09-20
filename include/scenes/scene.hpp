#pragma once

#include "globalIncludes.hpp"

using namespace std;

class SceneManager;

class Scene
{
public:
    Scene();

    // Initializes scene variables, and it's only called once when the scene is first loaded.
    virtual void Init() = 0;

    // Handles loading of textures, sounds, and other resources.
    virtual void Load() = 0;

    // Logic/Behavior that updates the scene every frame.
    virtual void Update() = 0;

    // Renders the scene every frame.
    virtual void Render() = 0;

    // Frees any resources (textures, etc.) when the scene is switched or removed.
    virtual void Unload() = 0;

    string GetName();
    bool IsInitialized();
protected:
    string _name;
    bool initialized = false; 
};
