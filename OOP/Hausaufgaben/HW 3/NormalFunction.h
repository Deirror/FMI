#pragma once
#include "MyFunction.h"

using FunctInt32 = int32_t(*)(int32_t x);

class NormalFunction : public MyFunction
{
private:
	FunctInt32 func = nullptr;

public:
	NormalFunction() = default;

	NormalFunction(FunctInt32 _func);

	MyFunction* clone() const override;

	Pair<bool, int32_t> operator()(int32_t x) const override;
};

