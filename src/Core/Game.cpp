#include "Core/Game.hpp"
#include "Core/Window.hpp"
#include "GameObjects/GameObject.hpp"

void Game::processInput() {
    // Input handling specific to game logic
}

void Game::update(float deltaTime) {
    for (auto& obj : m_gameObjects) {
        obj->update(deltaTime);
    }
}

void Game::render(Window& window) {
    window.clear();
    for (auto& obj : m_gameObjects) {
        obj->draw(window.getSFMLWindow());
    }
    window.display();
}

void Game::addObject(std::unique_ptr<GameObject> object) {
    m_gameObjects.push_back(std::move(object));
}