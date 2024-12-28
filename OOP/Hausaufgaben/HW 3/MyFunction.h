#pragma once
#include "Pair.hpp"
#include <cstdint>
#define LIMIT 32

class MyFunction
{
public:
	virtual Pair<bool, int32_t> operator()(int32_t x) const = 0;

	virtual MyFunction* clone() const = 0;

	virtual ~MyFunction() = default;
};

