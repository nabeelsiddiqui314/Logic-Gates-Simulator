#pragma once
#include <memory>
#include <SFML/System/Vector2.hpp>

namespace sf {
	class RenderWindow;
	class Event;
}

namespace UI {

class GraphicsComponent {
public:
	GraphicsComponent() = default;
	virtual ~GraphicsComponent() = default;
public:
	void setParent(const std::weak_ptr<GraphicsComponent>& parent);

	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPosition() const;

	virtual bool handleEvent(const sf::Event& event);
	virtual void draw(sf::RenderWindow& window) = 0;
private:
	std::weak_ptr<GraphicsComponent> m_parentPtr;
	sf::Vector2f m_position;
};

}