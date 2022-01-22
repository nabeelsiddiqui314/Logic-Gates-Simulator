#pragma once
#include <memory>
#include <SFML/System/Vector2.hpp>

namespace sf {
	class RenderWindow;
	class Event;
}

class IGraphicsComponent {
public:
	IGraphicsComponent() = default;
	virtual ~IGraphicsComponent() = default;
public:
	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPosition() const;

	void setParent(const std::weak_ptr<IGraphicsComponent>& parent);

	virtual bool handleEvent(const sf::Event& event) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
private:
	std::weak_ptr<IGraphicsComponent> m_parentPtr;
	sf::Vector2f m_position;
};