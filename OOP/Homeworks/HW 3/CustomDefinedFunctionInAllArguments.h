#pragma once
#include "MyFunction.h"

class CustomDefinedFunctionInAllArguments : public MyFunction
{
private:
	int32_t specialPoints[LIMIT]{};
	size_t size = 0;

public:
	CustomDefinedFunctionInAllArguments() = default;

	CustomDefinedFunctionInAllArguments(const int32_t* _specialPoints, size_t _size);

	MyFunction* clone() const override;

	Pair<bool, int32_t> operator()(int32_t x) const override;

private:
	void setSpecialPoints(const int32_t* _specialPoints, size_t _size);
};

