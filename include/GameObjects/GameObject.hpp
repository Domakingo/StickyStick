#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class GameObject {
public:
    virtual ~GameObject() = default;

    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual std::unique_ptr<GameObject> clone() const = 0;

    virtual void setPosition(const sf::Vector2f& position) = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
};