#include <iostream>
#include <cstring>
#include <raylib.h>
#include <string.h>
#include <vector>
#include <format>

#include "game.hpp"
#include "sceneManager.hpp"

using namespace std;

int main()
{
    Game game = Game();

    // Service registration

    // Scenes (UI)
    game.AddScene(make_shared<MenuScene>());
    game.AddScene(make_shared<PlayScene>());
    game.AddScene(make_shared<ExitScene>());
    game.Run();
    return 0;
}