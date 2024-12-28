#include "PartialFunctionContainer.h"
#include <utility>
#include <stdexcept>
#pragma warning(disable : 6386)//For overrun buffer in copyFrom

PartialFunctionContainer::PartialFunctionContainer(size_t _capacity) 
	: capacity(_capacity), size(0)
{
	data = new PartialFunction * [capacity];
}

PartialFunctionContainer::PartialFunctionContainer(PartialFunction** _data, size_t _size)
	: size(_size)
{
	capacity = size;

	data = new PartialFunction * [capacity];

	for (int i = 0; i < _size; i++)
	{
		data[i] = _data[i];
	}
}

PartialFunctionContainer::PartialFunctionContainer(const PartialFunctionContainer& other)
{
	copyFrom(other);
}

PartialFunctionContainer& PartialFunctionContainer::operator=(const PartialFunctionContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

PartialFunctionContainer::PartialFunctionContainer(PartialFunctionContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

PartialFunctionContainer& PartialFunctionContainer::operator=(PartialFunctionContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

PartialFunctionContainer::~PartialFunctionContainer()
{
	free();
}

void PartialFunctionContainer::addFunction(PartialFunction* func)
{
	if (size == capacity)
		throw std::out_of_range("Full container");

	if (func == nullptr)
		throw std::invalid_argument("Cannot add nullptr");	

	data[size++] = func;
}

void PartialFunctionContainer::free()
{
	for (int i = 0; i < size; i++)
	{
		delete data[i];
		data[i] = nullptr;
	}

	delete[] data;
	data = nullptr;

	size = 0;
	capacity = 0;
}

void PartialFunctionContainer::copyFrom(const PartialFunctionContainer& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new PartialFunction * [capacity];

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void PartialFunctionContainer::moveFrom(PartialFunctionContainer&& other)
{
	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;

	data = other.data;
	other.data = nullptr;
}
