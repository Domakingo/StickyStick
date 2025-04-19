#include "Core/Engine.hpp"
#include <stdexcept>

Engine& Engine::getInstance() {
    static Engine instance;
    return instance;
}

void Engine::initialize() {
    m_window.create(800, 600, "Sticky Stick");
    m_running = true;
}

void Engine::start() {
    gameLoop();
}

void Engine::shutdown() {
    m_running = false;
}

void Engine::gameLoop() {
    sf::Clock clock;
    while (m_running && m_window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        
        m_inputHandler.handleEvents(m_window.getSFMLWindow());
        m_game.processInput();
        m_game.update(deltaTime);
        m_game.render(m_window);
    }
}

Window& Engine::getWindow() { return m_window; }
InputHandler& Engine::getInputHandler() { return m_inputHandler; }
Game& Engine::getGame() { return m_game; }