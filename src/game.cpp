#include <iostream>
#include <vector>
#include <format>

#include "game.hpp"

using namespace std;

const int Game::Width = 1280;
const int Game::Height = 720;
const int Game::FontSize = 24;
const int Game::FontSpacing = 32;
const int Game::FontPadding = 16;
const string Game::Title = "Scene Manager Test";

unique_ptr<ServiceCollection> Game::_serviceCollection;