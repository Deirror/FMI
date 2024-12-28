#pragma once
#include "MyFunction.h"

class CustomDefinedFunctionOutOfSubmittedArguments : public MyFunction
{
private:
	int32_t excludedPoints[LIMIT]{};
	size_t size = 0;

public:
	CustomDefinedFunctionOutOfSubmittedArguments() = default;

	CustomDefinedFunctionOutOfSubmittedArguments(const int32_t* _excludedPoints, size_t _size);

	MyFunction* clone() const override;

	Pair<bool, int32_t> operator()(int32_t x) const override;

private:
	void setExcludedPoints(const int32_t* _excludedPoints, size_t _size);
};

