#pragma once

#include "globalIncludes.hpp"
#include "scene.hpp"

using namespace std;

class ErrorScene : public Scene
{
public:
    ErrorScene();

    void RegisterException(const exception &ex);
    void Render() override;

protected:
    string _message;
};
