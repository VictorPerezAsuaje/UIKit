#pragma once

#include <iostream>
#include <vector>

#include "scene.hpp"

using namespace std;

class PlayScene : public Scene
{
public:
    static const string DefaultName;
    PlayScene();

    void Init() override;
    void Load() override;
    void Update() override;
    void Render() override;
    void Unload() override;
};
