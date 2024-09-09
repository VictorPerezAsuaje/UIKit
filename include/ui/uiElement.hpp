#pragma once

#include <iostream>
#include <vector>
#include <raylib.h>

using namespace std;

class UIElement
{
public:
    UIElement(Vector2 position, Vector2 size, Color color) : Position(position), Size(size), BaseColor(color) {}
    virtual void Draw() = 0;

    virtual bool IsMouseOver()
    {
        Vector2 mousePos = GetMousePosition();
        return (mousePos.x >= Position.x && mousePos.x <= Position.x + Size.x &&
                mousePos.y >= Position.y && mousePos.y <= Position.y + Size.y);
    }

    virtual void Update() = 0;

protected:
    Vector2 Position;
    Vector2 Size;
    Color BaseColor;
};