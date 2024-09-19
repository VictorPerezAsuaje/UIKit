#pragma once

#include "globalIncludes.hpp"
#include "scenes/scene.hpp"

using namespace std;

class ExitScene : public Scene
{
public:
    ExitScene();
    void Render() override;

protected:
};
