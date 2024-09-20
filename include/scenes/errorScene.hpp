#pragma once

#include "globalIncludes.hpp"
#include "scene.hpp"

using namespace std;

class ErrorScene : public Scene
{
public:
    static const string DefaultName;
    ErrorScene();
    
    void Init() override;
    void Load() override;
    void Update() override;
    void Render() override;
    void Unload() override;

    void RegisterException(const exception &ex);

protected:
    string _message;
};
