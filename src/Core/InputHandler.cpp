#include <SFML/Graphics.hpp>

#include "Core/InputHandler.hpp"
#include "Core/Engine.hpp"

void InputHandler::handleEvents(sf::RenderWindow& window) {
    m_pressedKeys.clear();
    while (window.pollEvent(m_event)) {
        if (m_event.type == sf::Event::Closed) {
            window.close();
        }

        if (m_event.type == sf::Event::KeyPressed) {
            m_pressedKeys.insert(m_event.key.code);
        }

        if (m_event.type == sf::Event::KeyReleased) {
            m_pressedKeys.erase(m_event.key.code);
        }
    }
}

bool InputHandler::isKeyPressed(sf::Keyboard::Key key) const {
    return m_pressedKeys.count(key) > 0;
}