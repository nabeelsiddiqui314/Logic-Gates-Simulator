#include "Wire.h"
#include "IPin.h"

Wire::~Wire() {
	if (m_sourcePin) {
		m_sourcePin->onDisconnect(shared_from_this());
	}
	if (m_destinationPin) {
		m_destinationPin->onDisconnect(shared_from_this());
	}
}

bool Wire::connect(const PinPtr& pin) {
	return pin->onConnect(shared_from_this());
}

void Wire::disconnect(const PinPtr& pin) {
	pin->onDisconnect(shared_from_this());
}

bool Wire::setSource(const PinPtr& pin) {
	if (!m_sourcePin) {
		m_sourcePin = pin;
		return true;
	}
	return false;
}

bool Wire::setDestination(const PinPtr& pin) {
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