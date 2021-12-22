#pragma once
#include "IPin.h"

class InputPin : public IPin {
public:
	InputPin() = default;
	~InputPin();
public:
	void receiveSignal(const Signal& signal) override;
	void onConnect(const WirePtr& wire) override;
	void onDisconnect(const WirePtr& wire) override;
private:
	WirePtr m_connectedWire;
};