#include "MaximumPartialFunction.h"
#include <stdexcept>

MaximumPartialFunction::MaximumPartialFunction(PartialFunction** data, size_t size)
	: PartialFunctionCollectionOperation(data, size)
{
}

MaximumPartialFunction::MaximumPartialFunction(const PartialFunctionContainer& _container)
	: PartialFunctionCollectionOperation(_container)
{
}

PartialFunction* MaximumPartialFunction::clone() const
{
	return new MaximumPartialFunction(*this);
}

int32_t MaximumPartialFunction::operator()(int32_t x) const
{
	if (!isDefinedAt(x))
		throw std::invalid_argument("Undefined");

	int32_t max = (1 << 31);

	int32_t res = 0;

	for (int i = 0; i < container.size; i++)
	{
		res = container.data[i]->operator()(x);

		if (res > max)
			max = res;
	}

	return max;
}
