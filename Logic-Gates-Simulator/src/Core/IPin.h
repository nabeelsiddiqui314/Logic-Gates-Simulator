#pragma once
#include "Signal.h"

class IPin {
public:
	IPin() = default;
	virtual ~IPin() = default;
public:
	virtual void receiveSignal(const Signal& signal) = 0;
};