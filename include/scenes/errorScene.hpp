#pragma once

#include <iostream>
#include <vector>

#include "scene.hpp"

using namespace std;

class ErrorScene : public Scene
{
public:
    static const string DefaultName;

    ErrorScene();

    void RegisterException(const exception &ex);
    void Render() override;

protected:
    string _message;
};
