#include "readerOf16BitsNumbers.h"

Pair<uint16_t, uint16_t> read16BitsNumbers(std::ifstream& ifs)
{
	uint16_t count = 0;
	uint16_t functionType = 0;

	ifs.read((char*)(&count), sizeof(uint16_t));
	ifs.read((char*)(&functionType), sizeof(uint16_t));

	if (count == 0)
		throw std::invalid_argument("No files for reading or no values in the given file");

	if (count > 32 || functionType > 4)
		throw std::invalid_argument("Invalid value");

	return Pair<uint16_t, uint16_t>(count, functionType);
}