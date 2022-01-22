#include "IGraphicsComponent.h"

void IGraphicsComponent::setPosition(const sf::Vector2f& position) {
    m_position = position;
}

sf::Vector2f IGraphicsComponent::getPosition() const {
    sf::Vector2f parentPosition = { 0.0f, 0.0f };

    if (auto parent = m_parentPtr.lock()) {
        parentPosition = parent->getPosition();
    }

    return m_position + parentPosition;
}

void IGraphicsComponent::setParent(const std::weak_ptr<IGraphicsComponent>& parent) {
    m_parentPtr = parent;
}
