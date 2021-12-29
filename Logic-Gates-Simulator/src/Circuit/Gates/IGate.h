#pragma once

class IGate {
public:
	IGate() = default;
	~IGate() = default;
public:
	virtual void process() = 0;
};