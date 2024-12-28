#pragma once
#include "PartialFunction.h"
#include <stdexcept>

template <class T>
class PartialFunctionByCriteria : public PartialFunction
{
private:
	T func;

public:
	PartialFunctionByCriteria(const T& _func);

	PartialFunction* clone() const override;
	bool isDefinedAt(int32_t x) const override;
	int32_t operator()(int32_t x) const override;
};

template<class T>
PartialFunctionByCriteria<T>::PartialFunctionByCriteria(const T& _func)
{
	func = _func;
}

template<class T>
PartialFunction* PartialFunctionByCriteria<T>::clone() const
{
	return new PartialFunctionByCriteria<T>(*this);
}

template<class T>
bool PartialFunctionByCriteria<T>::isDefinedAt(int32_t x) const
{
	return func(x).getLhs();
}

template<class T>
int32_t PartialFunctionByCriteria<T>::operator()(int32_t x) const
{
	if (!isDefinedAt(x))
		throw std::invalid_argument("Undefined");

	return func(x).getRhs();
}