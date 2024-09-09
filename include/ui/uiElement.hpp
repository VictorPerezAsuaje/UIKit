#pragma once

#include <iostream>
#include <vector>
#include <raylib.h>

using namespace std;

class UIElement
{
public:
    Vector2 Position;
    Vector2 Size;
    Color BaseColor = GRAY;

    virtual bool IsMouseOver()
    {
        Vector2 mousePos = GetMousePosition();
        return (mousePos.x >= Position.x && mousePos.x <= Position.x + Size.x &&
                mousePos.y >= Position.y && mousePos.y <= Position.y + Size.y);
    }

    virtual void Update() = 0;

protected:
    virtual void Draw() = 0;
};