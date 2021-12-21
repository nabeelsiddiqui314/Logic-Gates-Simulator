#pragma once
#include <memory>
#include "Signal.h"

class Wire;

class IPin {
	typedef std::shared_ptr<Wire> WirePtr;
public:
	IPin() = default;
	virtual ~IPin() = default;
public:
	virtual void receiveSignal(const Signal& signal) = 0;
	virtual void onConnect(const WirePtr& wire) = 0;
	virtual void onDisconnect(const WirePtr& wire) = 0;
};