#pragma once

#include "globalIncludes.hpp"
#include "ui/uiElement.hpp"

using namespace std;

class UIContainer : public UIElement
{
public:
    UIContainer(int x = 0, int y = 0, float width = 0, float height = 0) : UIElement(x, y, width, height) {}
    
    void Draw() override;
    void Update() override;

    void AddChild(shared_ptr<UIElement> element) { Children.push_back(element); }
    
    vector<shared_ptr<UIElement>> Children = {};
};