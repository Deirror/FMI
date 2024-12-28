#include "CustomDefinedFunctionOutOfSubmittedArguments.h"
#include <stdexcept>

CustomDefinedFunctionOutOfSubmittedArguments::CustomDefinedFunctionOutOfSubmittedArguments(const int32_t* _excludedPoints, size_t _size)
	: size(_size)
{
	setExcludedPoints(_excludedPoints, _size);
}

MyFunction* CustomDefinedFunctionOutOfSubmittedArguments::clone() const
{
	return new CustomDefinedFunctionOutOfSubmittedArguments(*this);
}

Pair<bool, int32_t> CustomDefinedFunctionOutOfSubmittedArguments::operator()(int32_t x) const
{
	for (int i = 0; i < size; i++)
	{
		if (excludedPoints[i] == x)
			return Pair<bool, int32_t>(false, -1);
	}

	return Pair<bool, int32_t>(true, x);
}


void CustomDefinedFunctionOutOfSubmittedArguments::setExcludedPoints(const int32_t* _excludedPoints, size_t _size)
{
	if (!_excludedPoints)
		throw std::invalid_argument("Nullptr");

	size = _size;

	for (int i = 0; i < _size; i++)
	{
		excludedPoints[i] = _excludedPoints[i];
	}
}
