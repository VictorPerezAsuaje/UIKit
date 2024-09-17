#pragma once

#include "globalIncludes.hpp"

#include "game.hpp"
#include "uiElement.hpp"
#include "uiContainer.hpp"

using namespace std;

class UIButton : public UIContainer
{
public:
    string Text = "";
    Color HoverColor = BLUE;
    function<void()> OnClickFunc;

    UIButton(int x = 0, int y = 0, float width = 0, float height = 0) : UIContainer(x, y, width, height) {}

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