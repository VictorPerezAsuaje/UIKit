#include <iostream>
#include <vector>
#include <functional>

#include "game.hpp"
#include "ui/uiButton.hpp"

using namespace std;

void UIButton::Draw()
{
    Update();

    // Change color on hover
    Color currentColor = IsHovered ? HoverColor : BaseColor;
    DrawRectangleV(Position, Size, currentColor);
    DrawText(Text.c_str(), Position.x + Game::FontPadding / 2, Position.y + Game::FontPadding / 2, Game::FontSize, WHITE);
}

void UIButton::Update()
{
    IsHovered = IsMouseOver();
    if (IsHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        OnClick();
    }
}