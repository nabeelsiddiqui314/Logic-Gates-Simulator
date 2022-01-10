#pragma once
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "CompositeGraphicalComponent.h"

class TexturedComponent : public CompositeGraphicalComponent {
public:
	TexturedComponent(const std::string& texturePath);
	~TexturedComponent() = default;
public:
	void setParent(const ParentPtr& parent) override;
	Position getPosition() override;

	bool handleEvent(const sf::Event& event) override;
	void draw(sf::RenderWindow& window) override;
private:
	sf::Sprite m_body;
	sf::Texture m_texture;

	Position m_position;
	ParentPtr m_parentPtr;
};