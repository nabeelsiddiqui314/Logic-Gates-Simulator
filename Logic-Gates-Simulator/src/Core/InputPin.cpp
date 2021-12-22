#include "InputPin.h"
#include "Wire.h"

InputPin::~InputPin() {
	if (m_connectedWire) {
		m_connectedWire->removeDestination();
	}
}

void InputPin::receiveSignal(const Signal& signal) {
	
}

void InputPin::onConnect(const WirePtr& wire) {
	if (!m_connectedWire) {
		wire->setDestination(shared_from_this());
		m_connectedWire = wire;
	}
}

void InputPin::onDisconnect(const WirePtr& wire) {
	if (m_connectedWire == wire) {
		wire->removeDestination();
	}
}