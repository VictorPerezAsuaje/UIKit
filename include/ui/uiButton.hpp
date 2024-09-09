#pragma once

#include <iostream>
#include <vector>
#include <functional>

#include "uiElement.hpp"

using namespace std;

class UIButton : public UIElement
{
protected:
    string Text;
    Color HoverColor;
    bool IsHovered;

public:
    function<void()> OnClickFunc;

    UIButton(Vector2 position, Vector2 size, Color color, string text, Color hoverColor = LIGHTGRAY) : UIElement(position, size, color), Text(text), HoverColor(hoverColor), IsHovered(false) {}

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