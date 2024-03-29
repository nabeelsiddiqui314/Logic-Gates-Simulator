#include "Wire.h"
#include "../Pins/IPin.h"

Wire::~Wire() {
	disconnectCompletely();
}

bool Wire::connect(IPin* pin) {
	return pin->onConnect(shared_from_this());
}

void Wire::disconnect(IPin* pin) {
	pin->onDisconnect(shared_from_this());
}

void Wire::disconnectCompletely() {
	if (m_sourcePin) {
		m_sourcePin->onDisconnect(shared_from_this());
	}
	if (m_destinationPin) {
		m_destinationPin->onDisconnect(shared_from_this());
	}
}

void Wire::transmitSignal(const Signal& signal) {
	m_destinationPin->receiveSignal(signal);
}

bool Wire::setSource(IPin* pin) {
	if (!m_sourcePin) {
		m_sourcePin = pin;
		return true;
	}
	return false;
}

bool Wire::setDestination(IPin* pin) {
	if (!m_destinationPin) {
		m_destinationPin = pin;
		return true;
	}
	return false;
}

void Wire::removeSource() {
	m_sourcePin = nullptr;
}

void Wire::removeDestination() {
	m_destinationPin = nullptr;
}