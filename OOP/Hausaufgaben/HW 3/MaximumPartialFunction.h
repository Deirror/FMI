#pragma once
#include "PartialFunctionCollectionOperation.h"

class MaximumPartialFunction : public PartialFunctionCollectionOperation
{
public:
	MaximumPartialFunction(PartialFunction** data, size_t size);

	MaximumPartialFunction(const PartialFunctionContainer& _container);

	PartialFunction* clone() const override;

	int32_t operator()(int32_t x) const override;
};

