#pragma once
#include <memory>
#include <vector>
#include "IGraphicsComponent.h"
#include "../IPositionable.h"

typedef std::shared_ptr<IGraphicsComponent> GraphicalComponentPtr;

class CompositeGraphicalComponent 
	: public IGraphicsComponent, public IPositionable, private std::enable_shared_from_this<CompositeGraphicalComponent> {
public:
	CompositeGraphicalComponent() = default;
	~CompositeGraphicalComponent() = default;
public:
	void addChild(const GraphicalComponentPtr& child);
protected:
	std::vector<GraphicalComponentPtr> getChildren() const;
private:
	std::vector<GraphicalComponentPtr> m_children;
};