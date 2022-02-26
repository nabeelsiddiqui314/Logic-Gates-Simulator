#include "GraphicsComponent.h"
#include <SFML/Window/Event.hpp>

namespace UI {

void GraphicsComponent::setParent(const std::weak_ptr<GraphicsComponent>& parent) {
    m_parentPtr = parent;
}

void GraphicsComponent::setPosition(const sf::Vector2f& position) {
    m_position = position;
}

sf::Vector2f GraphicsComponent::getPosition() const {
    sf::Vector2f parentPosition = { 0.0f, 0.0f };

    if (auto parent = m_parentPtr.lock()) {
        parentPosition = parent->getPosition();
    }

    return m_position + parentPosition;
}

bool GraphicsComponent::handleEvent(const sf::Event& event) {
    switch (event.type) {
    case sf::Event::MouseMoved:
        break;
    case sf::Event::MouseButtonPressed:
        
        break;
    }

    return false;
}

}