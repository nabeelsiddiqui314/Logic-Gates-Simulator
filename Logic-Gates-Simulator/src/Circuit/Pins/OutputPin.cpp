#include "OutputPin.h"
#include "../Connection/Wire.h"

OutputPin::~OutputPin() {
	for (auto& wire : m_connectedWires) {
		wire->disconnectCompletely();
	}
}

void OutputPin::receiveSignal(const Signal& signal) {
	for (auto& wire : m_connectedWires) {
		wire->transmitSignal(signal);
	}
}

bool OutputPin::onConnect(const WirePtr& wire) {
	// if the wire isnt already connected
	if (std::find(m_connectedWires.begin(), m_connectedWires.end(), wire) == m_connectedWires.end()) {
		if (wire->setSource(this)) {
			m_connectedWires.push_back(wire);
			return true;
		}
	}
	return false;
}

void OutputPin::onDisconnect(const WirePtr& wire) {
	auto wireIterator = std::find(m_connectedWires.begin(), m_connectedWires.end(), wire);
	if (wireIterator != m_connectedWires.end()) {
		(*wireIterator)->removeSource();
		m_connectedWires.erase(wireIterator);
	}
	
}