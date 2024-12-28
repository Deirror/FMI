#pragma once
#include "PartialFunction.h"
#include "UniquePointer.hpp"

class FunctionDebugger
{
public:
	static void debug(const UniquePointer<PartialFunction>& _function);

private:
	FunctionDebugger(const UniquePointer<PartialFunction>& _function);

	void printInInterval(int start, int end) const;

	void generateNextValuesRegime(int choice) const;

	void printNextDefinedValues(int32_t x, int diff) const;

	const UniquePointer<PartialFunction>& function;
};

