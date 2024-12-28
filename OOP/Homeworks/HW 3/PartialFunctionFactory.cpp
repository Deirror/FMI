#include "CustomDefinedFunctionOutOfSubmittedArguments.h"
#include "CustomDefinedFunctionInSubmittedArguments.h"
#include "CustomDefinedFunctionInAllArguments.h"
#include "PartialFunctionFactory.h"
#include "PartialFunctionByCriteria.h"
#include "PartialFunctionContainer.h"
#include "MaximumPartialFunction.h"
#include "MinimumPartialFunction.h"
#include "readerOf16BitsNumbers.h"
#include <fstream>

static void replaceSymbol(char* ptr, int16_t count, char toReplace, char with)
{
	if (!ptr)
		throw std::invalid_argument("Nullptr");

	int times = 0;

	while (times < count)
	{
		if (*ptr == toReplace)
		{
			*ptr = with;
			times++;
		}
		ptr++;
	}
}

static void readFilesNames(const Pair<uint16_t, uint16_t>& fileNumbers, std::ifstream& ifs, char* buff, size_t buffSize)
{
	if (!buff)
		throw std::invalid_argument("Nullptr");

	ifs.read((char*)buff, buffSize);

	replaceSymbol(buff, fileNumbers.getLhs(), '\0', '|');
}

PartialFunction* PartialFunctionFactory::customDefinedFunctionFactory(const Pair<uint16_t, uint16_t>& fileNumbers, std::ifstream& ifs)
{
	uint16_t size = fileNumbers.getLhs();

	int32_t domainArr[LIMIT]{};
	ifs.read((char*)domainArr, sizeof(int32_t) * size);

	switch (fileNumbers.getRhs())
	{
	case 0:
	{
		int32_t rangeArr[LIMIT]{};

		ifs.read((char*)rangeArr, sizeof(int32_t) * size);

		return new PartialFunctionByCriteria<CustomDefinedFunctionInSubmittedArguments>
			(CustomDefinedFunctionInSubmittedArguments(domainArr, rangeArr, size));
	}
	case 1:
	{
		return new PartialFunctionByCriteria<CustomDefinedFunctionOutOfSubmittedArguments>
			(CustomDefinedFunctionOutOfSubmittedArguments(domainArr, size));
	}
	case 2:
	{
		return new PartialFunctionByCriteria<CustomDefinedFunctionInAllArguments>
			(CustomDefinedFunctionInAllArguments(domainArr, size));
	}
	}

	return nullptr;
}

PartialFunction* PartialFunctionFactory::maxMinFunctionFactory(const Pair<uint16_t, uint16_t>& fileNumbers, std::ifstream& mainIfs)
{
	char buff[1024]{};
	readFilesNames(fileNumbers, mainIfs, buff, 1024);

	std::stringstream ss(buff);

	PartialFunctionContainer container(fileNumbers.getLhs());

	char fileName[64]{};
	Pair<uint16_t, uint16_t> fileNumbersOfSubFiles;

	std::ifstream ifs;

	for (int i = 0; i < fileNumbers.getLhs(); i++)
	{
		ss.getline(fileName, 64, '|');

		ifs.open(fileName, std::ios::binary);

		if (!ifs.is_open())
			throw std::runtime_error("Cannot be opened");

		fileNumbersOfSubFiles = read16BitsNumbers(ifs);

		container.addFunction(customDefinedFunctionFactory(fileNumbersOfSubFiles, ifs));

		ifs.close();
	}

	switch (fileNumbers.getRhs())
	{
	case 3:
	{
		return new MaximumPartialFunction(container);
	}
	case 4:
	{
		return new MinimumPartialFunction(container);
	}
	}

	return nullptr;
}
