#include <iostream>
#include <cstring>
#include <raylib.h>
#include <string.h>
#include <vector>
#include <format>

#include "game.hpp"
#include "sceneManager.hpp"
#include "scenes/scene.hpp"
#include "scenes/playScene.hpp"
#include "scenes/configurationScene.hpp"
#include "scenes/errorScene.hpp"
#include "scenes/exitScene.hpp"

using namespace std;

int main()
{
    Game game = Game();

    // Service registration

    // Scenes (UI)
    game.AddScene(make_shared<MenuScene>());
    game.AddScene(make_shared<PlayScene>());
    game.AddScene(make_shared<ConfigurationScene>());
    game.AddScene(make_shared<ErrorScene>());
    game.AddScene(make_shared<ExitScene>());
    game.Run();

    return 0;
}