#pragma once
#include <memory>

class IPin;

class Wire : private std::enable_shared_from_this<Wire> {
	typedef std::shared_ptr<IPin> PinPtr;
public:
	Wire() = default;
	~Wire() = default;
public:
	void connect(const PinPtr& pin);
	void disconnect(const PinPtr& pin);
};