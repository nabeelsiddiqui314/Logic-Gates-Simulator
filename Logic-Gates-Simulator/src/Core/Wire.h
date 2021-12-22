#pragma once
#include <memory>
#include "Signal.h"

class IPin;

class Wire : private std::enable_shared_from_this<Wire> {
	typedef std::shared_ptr<IPin> PinPtr;
public:
	Wire() = default;
	~Wire();
public:
	bool connect(const PinPtr& pin);
	void disconnect(const PinPtr& pin);

	void transmitSignal(const Signal& signal);

	bool setSource(const PinPtr& pin);
	bool setDestination(const PinPtr& pin);

	void removeSource();
	void removeDestination();
private:
	PinPtr m_sourcePin;
	PinPtr m_destinationPin;
};