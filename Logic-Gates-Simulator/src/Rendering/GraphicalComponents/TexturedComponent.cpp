#include "TexturedComponent.h"
#include <SFML/Graphics/RenderWindow.hpp>

TexturedComponent::TexturedComponent(const std::string& texturePath) : m_position({200, 200}) {
    m_texture.loadFromFile(texturePath);
    m_body.setTexture(m_texture);
}

void TexturedComponent::setParent(const ParentPtr& parent) {
    m_parentPtr = parent;
}

Position TexturedComponent::getPosition() {
    if (auto parentPtr = m_parentPtr.lock()) {
        // get parent position
    }

    return m_position;
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
    Position position = getPosition();

    m_body.setPosition({ (float)position.x, (float)position.y });

    for (auto& child : getChildren()) {
        child->draw(window);
    }

    window.draw(m_body);
}