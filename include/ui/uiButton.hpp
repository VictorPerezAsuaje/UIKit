#pragma once

#include <iostream>
#include <vector>
#include <functional>

#include "uiElement.hpp"

using namespace std;

class UIButton : public UIElement
{
public:
    string Text = "";
    Color HoverColor = BLUE;
    Rectangle Container = {0,0,0,0};
    function<void()> OnClickFunc;

    void Update() override;
    void Draw() override;

    void OnClick()
    {
        if (!OnClickFunc)
        {
            return;
        }

        OnClickFunc();
    }
};