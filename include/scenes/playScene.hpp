#pragma once

#include <iostream>
#include <vector>

#include "scene.hpp"

using namespace std;

class PlayScene : public Scene
{
public:
    PlayScene();
    void Render() override;
};
