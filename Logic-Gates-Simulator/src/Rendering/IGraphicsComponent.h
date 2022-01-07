#pragma once
#include <memory>

namespace sf {
	class RenderWindow;
}

class IPositionable;

class IGraphicsComponent {
private:
	typedef std::weak_ptr<IPositionable> ParentPtr;
public:
	IGraphicsComponent() = default;
	virtual ~IGraphicsComponent() = default;
public:
	virtual void setParent(const ParentPtr& parent) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};