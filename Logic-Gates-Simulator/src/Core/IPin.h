#pragma once
#include <memory>
#include "Signal.h"

class Wire;

class IPin : protected std::enable_shared_from_this<IPin> {
protected:
	typedef std::shared_ptr<Wire> WirePtr;
public:
	IPin() = default;
	virtual ~IPin() = default;
public:
	virtual void receiveSignal(const Signal& signal) = 0;
	virtual bool onConnect(const WirePtr& wire) = 0;
	virtual void onDisconnect(const WirePtr& wire) = 0;
};