#include "InputPin.h"
#include "../Connection/Wire.h"
#include "../Gates/IGate.h"

InputPin::InputPin() 
	: m_parentGate(nullptr) {}

InputPin::InputPin(IGate* parentGate) 
	: m_parentGate(parentGate) {}

InputPin::~InputPin() {
	if (m_connectedWire) {
		m_connectedWire->disconnectCompletely();
	}
}

void InputPin::receiveSignal(const Signal& signal) {
	if (m_parentGate) {
		m_parentGate->process();
	}
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