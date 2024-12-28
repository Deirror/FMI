#include "MinimumPartialFunction.h"
#include <stdexcept>

MinimumPartialFunction::MinimumPartialFunction(PartialFunction** data, size_t size)
	:PartialFunctionCollectionOperation(data,size)
{
}

MinimumPartialFunction::MinimumPartialFunction(const PartialFunctionContainer& _container)
	: PartialFunctionCollectionOperation(_container)
{
}

PartialFunction* MinimumPartialFunction::clone() const
{
	return new MinimumPartialFunction(*this);
}

int32_t MinimumPartialFunction::operator()(int32_t x) const
{
	if (!isDefinedAt(x))
		throw std::invalid_argument("Undefined");

	int32_t min = ~(1 << 31);

	int32_t res = 0;

	for (int i = 0; i < container.size; i++)
	{
		res = container.data[i]->operator()(x);

		if (res < min)
			min = res;
	}

	return min;
}
