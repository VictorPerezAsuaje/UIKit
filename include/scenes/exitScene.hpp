#pragma once

#include "globalIncludes.hpp"
#include "scenes/scene.hpp"

using namespace std;

class ExitScene : public Scene
{
public:
    static const string DefaultName;

    ExitScene();
    void Render() override;

protected:
};
