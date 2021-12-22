#pragma once
#include <memory>

class IPin;

class Wire : private std::enable_shared_from_this<Wire> {
	typedef std::shared_ptr<IPin> PinPtr;
public:
	Wire() = default;
	~Wire();
public:
	void connect(const PinPtr& pin);
	void disconnect(const PinPtr& pin);

	void setSource(const PinPtr& pin);
	void setDestination(const PinPtr& pin);

	void removeSource();
	void removeDestination();
private:
	PinPtr m_sourcePin;
	PinPtr m_destinationPin;
};