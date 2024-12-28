#include "CustomDefinedFunctionInSubmittedArguments.h"
#include <stdexcept>

CustomDefinedFunctionInSubmittedArguments::CustomDefinedFunctionInSubmittedArguments(const int32_t* domainArr, const int32_t* rangeArr, size_t _size)
    : size(_size)
{
    setPairs(domainArr, rangeArr, _size);
}

MyFunction* CustomDefinedFunctionInSubmittedArguments::clone() const
{
    return new CustomDefinedFunctionInSubmittedArguments(*this);
}

Pair<bool, int32_t> CustomDefinedFunctionInSubmittedArguments::operator()(int32_t x) const
{
    for (int i = 0; i < size; i++)
    {
        if (pairs[i].getLhs() == x)
            return Pair<bool, int32_t>(true, pairs[i].getRhs());
    }

    return Pair<bool, int32_t>(false, -1);
}


void CustomDefinedFunctionInSubmittedArguments::setPairs(const int32_t* domainArr, const int32_t* rangeArr, size_t _size)
{
    if (!domainArr || !rangeArr)
        throw std::invalid_argument("Nullptr");

    size = _size;

    for (int i = 0; i < size; i++)
    {
        pairs[i].setLhs(domainArr[i]);
        pairs[i].setRhs(rangeArr[i]);
    }
}
