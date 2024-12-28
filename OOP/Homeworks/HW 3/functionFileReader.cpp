#include "functionFileReader.h"
#include "PartialFunctionFactory.h"
#include "readerOf16BitsNumbers.h"
#include <sstream>
#include <fstream>
#include <stdexcept>

PartialFunction* functionFileReader(const char* mainFileName)
{
	if (!mainFileName)
		throw std::invalid_argument("Nullptr");

	std::ifstream ifs(mainFileName, std::ios::binary);

	if (!ifs.is_open())
		throw std::runtime_error("Not opened");

	Pair<uint16_t, uint16_t> fileNumbers = read16BitsNumbers(ifs);	

	switch (fileNumbers.getRhs())
	{
	case 0:
	case 1:
	case 2:
	{
		return PartialFunctionFactory::customDefinedFunctionFactory(fileNumbers, ifs);
	}
	case 3:
	case 4:
	{		
		return PartialFunctionFactory::maxMinFunctionFactory(fileNumbers, ifs);
	}
	}

	ifs.close();

	return nullptr;
}