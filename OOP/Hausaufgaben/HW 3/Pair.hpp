#pragma once

template <class T, class D>
class Pair
{
private:
	T lhs;
	D rhs;

public:
	Pair() = default;

	Pair(const T& lhs, const D& rhs);

	void setLhs(const T& lhs);
	void setRhs(const D& rhs);

	const T& getLhs() const;
	const D& getRhs() const;
};

template<class T, class D>
Pair<T, D>::Pair(const T& lhs, const D& rhs) : lhs(lhs), rhs(rhs) {}

template<class T, class D>
void Pair<T, D>::setRhs(const D& rhs)
{
	this->rhs = rhs;
}

template<class T, class D>
void Pair<T, D>::setLhs(const T& lhs)
{
	this->lhs = lhs;
}

template<class T, class D>
const D& Pair<T, D>::getRhs() const {
	return rhs;
}

template<class T, class D>
const T& Pair<T, D>::getLhs() const {
	return lhs;
}