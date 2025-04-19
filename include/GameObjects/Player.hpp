#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "GameObjects/GameObject.hpp"

class Player : public GameObject {
public:
    Player();
    
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    std::unique_ptr<GameObject> clone() const override;

    void setPosition(const sf::Vector2f& position) override;
    sf::Vector2f getPosition() const override;
    sf::FloatRect getGlobalBounds() const override;

private:
    void createFallbackTexture();

    sf::Sprite m_sprite;
    sf::Vector2f m_velocity;
    sf::Texture m_texture;

    const float MOVE_SPEED = 8000.0f;
    const float WINDOW_PADDING = 10.0f;
};