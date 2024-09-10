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
    game.AddSingleton<SceneManager>();
    game.Run();
    return 0;
}