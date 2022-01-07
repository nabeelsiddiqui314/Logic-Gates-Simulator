#pragma once
#include <memory>

namespace sf {
	class RenderWindow;
}

class IPositionable;

typedef std::weak_ptr<IPositionable> ParentPtr;

class IGraphicsComponent {
public:
	IGraphicsComponent() = default;
	virtual ~IGraphicsComponent() = default;
public:
	virtual void setParent(const ParentPtr& parent) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};