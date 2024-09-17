#include "globalIncludes.hpp"
#include "ui/uiPanel.hpp"


void UIPanel::Draw()
{
    Rectangle rect = this->GetPosition();
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, BaseColor);
}

void UIPanel::Update()
{
    Draw();
    UIContainer::Update();
}