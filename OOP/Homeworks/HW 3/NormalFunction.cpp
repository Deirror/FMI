#include "NormalFunction.h"

NormalFunction::NormalFunction(FunctInt32 _func) : func(_func)
{
}

MyFunction* NormalFunction::clone() const
{
	return new NormalFunction(*this);
}

Pair<bool, int32_t> NormalFunction::operator()(int32_t x) const
{
	return Pair<bool, int32_t>(true, func(x));
}
