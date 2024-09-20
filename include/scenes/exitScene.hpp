#pragma once

#include "globalIncludes.hpp"
#include "scenes/scene.hpp"

using namespace std;

class ExitScene : public Scene
{
public:
    static const string DefaultName;
    ExitScene();

    void Init() override;
    void Load() override;
    void Update() override;
    void Render() override;
    void Unload() override;
};
