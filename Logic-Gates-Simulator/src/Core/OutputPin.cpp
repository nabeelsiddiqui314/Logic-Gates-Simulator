#include "OutputPin.h"
#include "Wire.h"

OutputPin::~OutputPin() {
	for (auto& wire : m_connectedWires) {
		wire->removeDestination();
	}
}

void OutputPin::receiveSignal(const Signal& signal) {
	
}

bool OutputPin::onConnect(const WirePtr& wire) {
	// if the wire isnt already connected
	if (std::find(m_connectedWires.begin(), m_connectedWires.end(), wire) == m_connectedWires.end()) {
		if (wire->setSource(shared_from_this())) {
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