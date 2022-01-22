#pragma once
#include <memory>
#include <vector>
#include "IGraphicsComponent.h"

typedef std::shared_ptr<IGraphicsComponent> GraphicalComponentPtr;

class CompositeGraphicalComponent : public IGraphicsComponent, private std::enable_shared_from_this<CompositeGraphicalComponent> {
public:
	CompositeGraphicalComponent() = default;
	~CompositeGraphicalComponent() = default;
public:
	void addChild(const GraphicalComponentPtr& child);

	virtual bool handleEvent(const sf::Event& event) override;
	virtual void draw(sf::RenderWindow& window) override;
private:
	std::vector<GraphicalComponentPtr> m_children;
};