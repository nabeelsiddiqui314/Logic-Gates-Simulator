#include "CompositeGraphicalComponent.h"

namespace UI {

void CompositeGraphicalComponent::addChild(const GraphicalComponentPtr& child) {
	child->setParent(weak_from_this());
	m_children.emplace_back(child);
}

bool CompositeGraphicalComponent::handleEvent(const sf::Event& event) {
	for (auto child : m_children) {
		if (child->handleEvent(event)) {
			return true;
		}
	}

	return false;
}

void CompositeGraphicalComponent::draw(sf::RenderWindow& window) {
	for (auto child : m_children) {
		child->draw(window);
	}
}

}