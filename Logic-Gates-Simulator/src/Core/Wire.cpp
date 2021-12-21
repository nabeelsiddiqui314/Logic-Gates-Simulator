#include "Wire.h"
#include "IPin.h"

void Wire::connect(const PinPtr& pin) {
	pin->onConnect(shared_from_this());
}

void Wire::disconnect(const PinPtr& pin) {
	pin->onDisconnect(shared_from_this());
}
