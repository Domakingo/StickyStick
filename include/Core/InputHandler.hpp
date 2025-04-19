#pragma once
#include <SFML/Window.hpp>
#include <unordered_set>

class InputHandler {
public:
    void handleEvents(sf::RenderWindow& window);
    bool isKeyPressed(sf::Keyboard::Key key) const;
    
private:
    std::unordered_set<sf::Keyboard::Key> m_pressedKeys;
    sf::Event m_event{};
};