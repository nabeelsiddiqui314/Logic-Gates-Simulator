#pragma once

namespace sf {
	class RenderWindow;
}

class IGraphicsComponent {
public:
	IGraphicsComponent() = default;
	virtual ~IGraphicsComponent() = default;
public:
	virtual void draw(sf::RenderWindow& window) = 0;
};