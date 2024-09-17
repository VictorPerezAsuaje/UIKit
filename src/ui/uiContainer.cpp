#include "globalIncludes.hpp"

#include "game.hpp"
#include "ui/uiContainer.hpp"

using namespace std;

void UIContainer::Draw()
{
    for(auto child : Children){
        // child->MoveTo(thisx, this.y);
        // child->x = this->x;
        // child->y = this->y;
        // child->width = this->width;
        // child->height = this->height;

        child->Draw();
    }
}

void UIContainer::Update()
{
    Draw();

    for(auto child : Children){
        child->Update();
    }
}
