#include "Core/Engine.hpp"

int main() {
    auto& engine = Engine::getInstance();
    engine.initialize();
    engine.start();
    engine.shutdown();
    return 0;
}