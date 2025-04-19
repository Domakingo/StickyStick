#include <SFML/Graphics/Texture.hpp>
#include <iostream>

#include "GameObjects/Player.hpp"
#include "Core/InputHandler.hpp"
#include "Core/Engine.hpp"

Player::Player() {
    if(!m_texture.loadFromFile("assets/player.png")) {
        std::cerr << "Texture non caricata! Uso fallback" << std::endl;
        createFallbackTexture();
    }
    
    m_sprite.setTexture(m_texture);
    m_sprite.setOrigin(m_texture.getSize().x/2.0f, m_texture.getSize().y/2.0f);
}

void Player::createFallbackTexture() {
    // Crea una texture 50x50 rossa
    sf::Image fallbackImage;
    fallbackImage.create(50, 50, sf::Color::Red);
    
    // Aggiungi bordo bianco
    for(unsigned x = 0; x < 50; x++) {
        for(unsigned y = 0; y < 50; y++) {
            if(x < 2 || x > 47 || y < 2 || y > 47) {
                fallbackImage.setPixel(x, y, sf::Color::White);
            }
        }
    }
    
    m_texture.loadFromImage(fallbackImage);
    m_texture.setSmooth(false);
}

void Player::update(float deltaTime) {
    auto& input = Engine::getInstance().getInputHandler();
    
    // Movimento istantaneo
    m_velocity.x = 0.0f;
    
    if(input.isKeyPressed(sf::Keyboard::A) || input.isKeyPressed(sf::Keyboard::Left)) {
        m_velocity.x = -MOVE_SPEED;
    }
    if(input.isKeyPressed(sf::Keyboard::D) || input.isKeyPressed(sf::Keyboard::Right)) {
        m_velocity.x = MOVE_SPEED;
    }

    m_sprite.move(m_velocity * deltaTime);

    // Mantieni nei bordi con padding
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    float windowWidth = Engine::getInstance().getWindow().getSFMLWindow().getSize().x;
    
    if(bounds.left < WINDOW_PADDING) {
        m_sprite.setPosition(WINDOW_PADDING + bounds.width/2, m_sprite.getPosition().y);
    }
    else if(bounds.left + bounds.width > windowWidth - WINDOW_PADDING) {
        m_sprite.setPosition(windowWidth - WINDOW_PADDING - bounds.width/2, m_sprite.getPosition().y);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}

std::unique_ptr<GameObject> Player::clone() const {
    return std::make_unique<Player>(*this);
}

// Implementazioni aggiuntive
void Player::setPosition(const sf::Vector2f& position) {
    m_sprite.setPosition(position);
}

sf::Vector2f Player::getPosition() const {
    return m_sprite.getPosition();
}

sf::FloatRect Player::getGlobalBounds() const {
    return m_sprite.getGlobalBounds();
}