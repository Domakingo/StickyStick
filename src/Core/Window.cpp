#include "Core/Window.hpp"

void Window::create(int width, int height, const std::string& title) {
    m_window.create(sf::VideoMode(width, height), title);
}

void Window::clear() { m_window.clear(); }
void Window::display() { m_window.display(); }
bool Window::isOpen() const { return m_window.isOpen(); }
sf::RenderWindow& Window::getSFMLWindow() { return m_window; }