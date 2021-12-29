#pragma once
#include "IPin.h"

class IGate;

class InputPin : public IPin {
public:
	InputPin();
	InputPin(IGate* parentGate);
	~InputPin();
public:
	void receiveSignal(const Signal& signal) override;
	bool onConnect(const WirePtr& wire) override;
	void onDisconnect(const WirePtr& wire) override;
private:
	WirePtr m_connectedWire;
	IGate* m_parentGate;
};