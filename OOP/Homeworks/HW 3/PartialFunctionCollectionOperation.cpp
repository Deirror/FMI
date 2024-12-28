#include "PartialFunctionCollectionOperation.h"

PartialFunctionCollectionOperation::PartialFunctionCollectionOperation(PartialFunction** data, size_t size)
	: container(data, size)
{
}

PartialFunctionCollectionOperation::PartialFunctionCollectionOperation(const PartialFunctionContainer& _container)
	: container(_container)
{
}

bool PartialFunctionCollectionOperation::isDefinedAt(int32_t x) const
{
	for (int i = 0; i < container.size; i++)
	{
		if (!(container.data[i]->isDefinedAt(x)))
			return false;
	}

	return true;
}
