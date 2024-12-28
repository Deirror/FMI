#pragma once
#include <cstdint>

class PartialFunction
{
public:
	virtual PartialFunction* clone() const = 0;
	virtual bool isDefinedAt(int32_t x) const = 0;
	virtual int32_t operator()(int32_t x) const = 0;

	virtual ~PartialFunction() = default;
};

