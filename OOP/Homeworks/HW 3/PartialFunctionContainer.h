#pragma once
#include "PartialFunction.h"

class MaximumPartialFunction;
class MinimumPartialFunction;
class PartialFunctionCollectionOperation;

class PartialFunctionContainer
{
private:
	PartialFunction** data = nullptr;
	size_t capacity = 0;
	size_t size = 0;

public:
	PartialFunctionContainer() = delete;

	PartialFunctionContainer(size_t _capacity);
	PartialFunctionContainer(PartialFunction** _data, size_t _size);

	PartialFunctionContainer(const PartialFunctionContainer& other);
	PartialFunctionContainer& operator=(const PartialFunctionContainer& other);

	PartialFunctionContainer(PartialFunctionContainer&& other) noexcept;
	PartialFunctionContainer& operator=(PartialFunctionContainer&& other) noexcept;

	~PartialFunctionContainer();

	void addFunction(PartialFunction* func);

	friend PartialFunctionCollectionOperation;
	friend MaximumPartialFunction;
	friend MinimumPartialFunction;

private:
	void free();
	void copyFrom(const PartialFunctionContainer& other);
	void moveFrom(PartialFunctionContainer&& other);
};

