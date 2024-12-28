#pragma once
#include "MyFunction.h"
#include "Pair.hpp"

class CustomDefinedFunctionInSubmittedArguments : public MyFunction
{
private:
	Pair<int32_t, int32_t> pairs[LIMIT]{};
	size_t size = 0;

public:
	CustomDefinedFunctionInSubmittedArguments() = default;

	CustomDefinedFunctionInSubmittedArguments(const int32_t* domainArr, const int32_t* rangeArr, size_t _size);

	MyFunction* clone() const override;

	Pair<bool, int32_t> operator()(int32_t x) const override;

private:
	void setPairs(const int32_t* domainArr, const int32_t* rangeArr, size_t _size);
};

