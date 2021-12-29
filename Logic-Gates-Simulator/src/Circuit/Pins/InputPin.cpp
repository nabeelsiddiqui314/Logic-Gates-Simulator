#include "InputPin.h"
#include "../Connection/Wire.h"

InputPin::~InputPin() {
	if (m_connectedWire) {
		m_connectedWire->disconnectCompletely();
	}
}

void InputPin::receiveSignal(const Signal& signal) {
	
}

bool InputPin::onConnect(const WirePtr& wire) {
	if (!m_connectedWire && wire->setDestination(this)) {
		m_connectedWire = wire;
		return true;
	}
	return false;
}

void InputPin::onDisconnect(const WirePtr& wire) {
	if (m_connectedWire == wire) {
		wire->removeDestination();
		m_connectedWire.reset();
	}
}