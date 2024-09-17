#pragma once

#include "globalIncludes.hpp"
#include "uiContainer.hpp"

using namespace std;

class UIPanel : public UIContainer
{
    public:
        UIPanel(int x = 0, int y = 0, float width = 0, float height = 0) : UIContainer(x, y, width, height) {}

        void Update() override;
        void Draw() override;
};