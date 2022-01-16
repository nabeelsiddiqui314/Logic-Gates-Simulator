#include "TexturedComponent.h"
#include <SFML/Graphics/RenderWindow.hpp>

TexturedComponent::TexturedComponent(const std::string& texturePath) {
    m_texture.loadFromFile(texturePath);
    m_body.setTexture(m_texture);
}

void TexturedComponent::setParent(const ParentPtr& parent) {
    m_parentPtr = parent;
}

sf::Vector2f TexturedComponent::getPosition() {
    sf::Vector2f offset = { 0.0f, 0.0f };

    if (auto parent = m_parentPtr.lock()) {
        offset = parent->getPosition();
    }

    return m_position + offset;
}

bool TexturedComponent::handleEvent(const sf::Event& event) {
    for (auto& child : getChildren()) {
        if (child->handleEvent(event)) {
            return true;
        }
    }
    return false;
}

void TexturedComponent::draw(sf::RenderWindow& window) {
    m_body.setPosition(getPosition());

    for (auto& child : getChildren()) {
        child->draw(window);
    }

    window.draw(m_body);
}