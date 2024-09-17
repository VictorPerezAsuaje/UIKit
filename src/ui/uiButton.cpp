#include "globalIncludes.hpp"

#include "game.hpp"
#include "ui/uiButton.hpp"

using namespace std;

void UIButton::Draw()
{
    Rectangle rect = this->GetPosition();
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, IsMouseOver() ? HoverColor : BaseColor);

    DrawText(Text.c_str(), rect.x + Game::fontPadding / 2, rect.y + Game::fontPadding / 2, Game::fontSize, WHITE);
}

void UIButton::Update()
{
    if (IsMouseOver() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        OnClick();
    }

    Draw();
}