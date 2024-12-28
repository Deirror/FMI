#pragma once
#include "PartialFunctionCollectionOperation.h"

class MinimumPartialFunction : public PartialFunctionCollectionOperation
{
public:
	MinimumPartialFunction(PartialFunction** data, size_t size);

	MinimumPartialFunction(const PartialFunctionContainer& _container);

	PartialFunction* clone() const override;

	int32_t operator()(int32_t x) const override;
};

