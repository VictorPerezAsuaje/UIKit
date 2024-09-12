#include <iostream>
#include <vector>
#include <functional>

#include "game.hpp"
#include "ui/uiButton.hpp"

using namespace std;

void UIButton::Draw()
{
    DrawRectangleV(Position, Size, IsMouseOver() ? HoverColor : BaseColor);
    DrawText(Text.c_str(), Position.x + Game::fontPadding / 2, Position.y + Game::fontPadding / 2, Game::fontSize, WHITE);
}

void UIButton::Update()
{
    if (IsMouseOver() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        OnClick();
    }

    Draw();
}