#pragma once
#include <vector>
#include "IPin.h"

class OutputPin : public IPin {
public:
	OutputPin() = default;
	~OutputPin();
public:
	void receiveSignal(const Signal& signal) override;
	bool onConnect(const WirePtr& wire) override;
	void onDisconnect(const WirePtr& wire) override;
private:
	std::vector<WirePtr> m_connectedWires;
};