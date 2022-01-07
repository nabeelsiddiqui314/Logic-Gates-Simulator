#pragma once
#include "Position.h"

class IPositionable {
public:
	IPositionable() = default;
	virtual ~IPositionable() = default;
public:
	virtual Position getPosition() = 0;
};