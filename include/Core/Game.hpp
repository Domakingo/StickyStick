#pragma once
#include <vector>
#include <memory>

#include "Core/Window.hpp"
#include "GameObjects/GameObject.hpp"

class Game {
public:
    void processInput();
    void update(float deltaTime);
    void render(Window& window);
    
    void addObject(std::unique_ptr<GameObject> object);

private:
    std::vector<std::unique_ptr<GameObject>> m_gameObjects;
};