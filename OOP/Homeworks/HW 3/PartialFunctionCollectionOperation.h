#pragma once
#include "PartialFunctionContainer.h"

class PartialFunctionCollectionOperation : public PartialFunction
{
protected:
	PartialFunctionContainer container;

public:
	PartialFunctionCollectionOperation(PartialFunction** data, size_t size);

	PartialFunctionCollectionOperation(const PartialFunctionContainer& _container);

	bool isDefinedAt(int32_t x) const override;

};