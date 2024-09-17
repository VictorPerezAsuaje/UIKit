#pragma once

#include "globalIncludes.hpp"

using namespace std;

class UIElement
{
public:
    string id = "";   
    
    UIElement* Parent = nullptr;
    Color BaseColor = GRAY;

    UIElement(int x = 0, int y = 0, float width = 0, float height = 0)
    {
        _x = x;
        _y = y;
        _width = width;
        _height = height;
    }

    virtual bool IsMouseOver()
    {
        Vector2 mousePos = GetMousePosition();
        return (mousePos.x >= _x && mousePos.x <= _x + _width &&
                mousePos.y >= _y && mousePos.y <= _y + _height);
    }

    Rectangle GetPosition(){
        // If we have a parent, the position must be relative to it
        if (Parent != nullptr){
            Rectangle parentRect = Parent->GetPosition();
            return {parentRect.x + _x, parentRect.y + _y, _width, _height};
        }

        return {(float)_x, (float)_y, _width, _height};
    }

    virtual void MoveTo(int x, int y){
        _x = x;
        _y = y;
    }

    virtual void Scale(float width, float height){
        _width = width;
        _height = height;
    }

    virtual void Update() = 0;
    virtual void Draw() = 0;    

protected:
    int _x = 0;
    int _y = 0;
    float _width = 0;
    float _height = 0;
};