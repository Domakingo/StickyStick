#include <iostream>

#include "Core/Engine.hpp"
#include "RegistryInit.hpp"

int main() {
    registerGameObjects();

    std::cout << "Avvio gioco..." << std::endl;
    auto& engine = Engine::getInstance();
    engine.initialize();
    engine.start();
    engine.shutdown();
    std::cout << "Gioco terminato" << std::endl;
    return 0;
}