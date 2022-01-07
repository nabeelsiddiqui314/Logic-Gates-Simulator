#include "CompositeGraphicalComponent.h"

void CompositeGraphicalComponent::addChild(const GraphicalComponentPtr& child) {
	m_children.emplace_back(child);
	child->setParent(weak_from_this());
}

std::vector<GraphicalComponentPtr> CompositeGraphicalComponent::getChildren() const {
	return m_children;
}
