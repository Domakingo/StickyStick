#include <iostream>

#include "Core/Engine.hpp"
#include "Core/Game.hpp"
#include "Core/Window.hpp"
#include "Core/Registry.hpp"
#include "GameObjects/GameObject.hpp"
#include "GameObjects/Player.hpp"

Game::Game() {
    spawnPlayer();
}

void Game::processInput() {
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

void Game::spawnPlayer() {
    auto player = Registry::create("Player");

    if(player) {
        player->setPosition(sf::Vector2f(100, 500));
        m_gameObjects.push_back(std::move(player));
        
        std::cout << "Numero oggetti: " << m_gameObjects.size() << std::endl;
    } else {
        std::cerr << "Errore nella creazione del player" << std::endl;
    }
}