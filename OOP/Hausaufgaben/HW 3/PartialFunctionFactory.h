#pragma once
#include "PartialFunction.h"
#include "Pair.hpp"
#include <fstream>
#include <sstream>

class PartialFunctionFactory
{
public:
	static PartialFunction* customDefinedFunctionFactory(const Pair<uint16_t, uint16_t>& fileNumbers, std::ifstream& ifs);

	static PartialFunction* maxMinFunctionFactory(const Pair<uint16_t, uint16_t>& fileNumbers, std::ifstream& ifs);
};

