#pragma once
#include <memory>
#include "Signal.h"

class IPin;

class Wire : private std::enable_shared_from_this<Wire> {
public:
	Wire() = default;
	~Wire();
public:
	bool connect(IPin* pin);
	void disconnect(IPin* pin);
	void disconnectCompletely();

	void transmitSignal(const Signal& signal);

	bool setSource(IPin* pin);
	bool setDestination(IPin* pin);

	void removeSource();
	void removeDestination();
private:
	IPin* m_sourcePin = nullptr;
	IPin* m_destinationPin = nullptr;
};