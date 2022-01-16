#pragma once
#include <SFML/System/Vector2.hpp>

class IPositionable {
public:
	IPositionable() = default;
	virtual ~IPositionable() = default;
public:
	virtual sf::Vector2f getPosition() = 0;
};