#pragma once

#include <iostream>
#include "scenes/scene.hpp"

class Scene;

template <class T>
concept IsScene = std::is_base_of_v<Scene, T>;