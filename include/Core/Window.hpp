#pragma once
#include <SFML/Graphics.hpp>

class Window {
public:
    void create(int width, int height, const std::string& title);
    void clear();
    void display();
    bool isOpen() const;
    sf::RenderWindow& getSFMLWindow();

private:
    sf::RenderWindow m_window;
};