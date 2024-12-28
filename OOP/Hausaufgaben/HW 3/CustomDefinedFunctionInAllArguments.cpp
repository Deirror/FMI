#include "CustomDefinedFunctionInAllArguments.h"
#include <stdexcept>

CustomDefinedFunctionInAllArguments::CustomDefinedFunctionInAllArguments(const int32_t* _specialPoints, size_t _size)
	: size(_size)
{
	setSpecialPoints(_specialPoints, _size);
}

MyFunction* CustomDefinedFunctionInAllArguments::clone() const
{
	return new CustomDefinedFunctionInAllArguments(*this);
}

Pair<bool, int32_t> CustomDefinedFunctionInAllArguments::operator()(int32_t x) const
{
	for (int i = 0; i < size; i++)
	{
		if (specialPoints[i] == x)
			return Pair<bool, int32_t>(true, 1);
	}

	return Pair<bool, int32_t>(true, 0);
}

void CustomDefinedFunctionInAllArguments::setSpecialPoints(const int32_t* _specialPoints, size_t _size)
{
	if (!_specialPoints)
		throw std::invalid_argument("Nullptr");

	size = _size;

	for (int i = 0; i < _size; i++)
	{
		specialPoints[i] = _specialPoints[i];
	}
}
