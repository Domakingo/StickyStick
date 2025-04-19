#include <iostream>

#include "Core/Registry.hpp"
#include "GameObjects/Player.hpp"

void registerGameObjects() {
    Registry::registerType<Player>("Player");
}