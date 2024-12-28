#include "ModifiableIntegersFunction.h"

#include <exception>
#include <iostream>
#include <fstream>

namespace Graphic
{
	const char point = 'o';
	const char whiteSpace = ' ';
	const char horizontalLine = '-';
	const char verticalLine = '|';
	const char undefinedX = '#';
	const short diffStartAndEnd = 20;
}

ModifiableIntegersFunction::ModifiableIntegersFunction(FuncPtr _func)
{
	if (!_func)
		throw std::exception("Nullptr");

	func = _func;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		inputSetterArray[i] = func(i + MIN_SHORT);
	}
}

void ModifiableIntegersFunction::modifyResult(short number, short newResult)
{
	if (pointExcludingArray[number + DIFF])
		pointExcludingArray[number + DIFF] = false;

	inputSetterArray[number + DIFF] = newResult;
}

void ModifiableIntegersFunction::excludePoint(short number)
{
	pointExcludingArray[number + DIFF] = true;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator+=(const ModifiableIntegersFunction& other)
{
	for (int i = 0; i < ARRAY_SIZE;i++)
	{
		if (other.pointExcludingArray[i])
		{
			inputSetterArray[i] = true;
			continue;
		}
	
		inputSetterArray[i] += other.inputSetterArray[i];
	}

	return *this;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator-=(const ModifiableIntegersFunction& other)
{
	for (int i = 0; i < ARRAY_SIZE;i++)
	{
		if (other.pointExcludingArray[i])
		{
			inputSetterArray[i] = true;
			continue;
		}

		inputSetterArray[i] -= other.inputSetterArray[i];
	}

	return *this;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator()(const ModifiableIntegersFunction& other)
{
	for (int i = 0; i < ARRAY_SIZE;i++)
	{
		if (other.pointExcludingArray[(other.inputSetterArray[i]) + DIFF])
		{
			pointExcludingArray[i] = true;
			continue;
		}

		inputSetterArray[i] = inputSetterArray[(other.inputSetterArray[i]) + DIFF];		
	}

	return *this;
}

short ModifiableIntegersFunction::operator()(short number) const
{
	if (!func)
		throw std::exception("Nullptr");

	if (pointExcludingArray[number + DIFF])
		throw std::exception("Not defined");

	if (func(number) == inputSetterArray[number + DIFF])
		return func(number);
	else
		return inputSetterArray[number + DIFF];
}

void ModifiableIntegersFunction::saveFunctionToFile(const char* fileName) const
{
	if (!fileName)
		throw std::exception("Nullptr");

	std::ofstream ofs(fileName, std::ios::binary);

	if (!ofs.is_open())
		throw std::exception("File not found");

	ofs.write((const char*)inputSetterArray, sizeof(short)*ARRAY_SIZE);

	ofs.write((const char*)pointExcludingArray, ARRAY_SIZE);

	ofs.close();
}

void ModifiableIntegersFunction::readFunctionFromFile(const char* fileName)
{
	if (!fileName)
		throw std::exception("Nullptr");

	std::ifstream ifs(fileName, std::ios::binary);

	if (!ifs.is_open())
		throw std::exception("File not found");

	ifs.read((char*)inputSetterArray, sizeof(short)*ARRAY_SIZE);

	ifs.read((char*)pointExcludingArray, ARRAY_SIZE);

	ifs.close();
}

void ModifiableIntegersFunction::printLine(short xStart, short yLine) const
{
	short xEnd = xStart + Graphic::diffStartAndEnd;

	bool flag = false;

	for (int x = xStart; x <= xEnd; x++)
	{
		if (pointExcludingArray[x + DIFF])
		{
			std::cout << Graphic::undefinedX << Graphic::whiteSpace;
			continue;
		}

		if (inputSetterArray[x + DIFF] == yLine)
		{
			std::cout << Graphic::point << Graphic::whiteSpace;
			continue;
		}
		
		if (x == 0)
		{
			std::cout << Graphic::verticalLine << Graphic::whiteSpace;
			flag = false;
		}
		else if (yLine == 0)
		{
			std::cout << Graphic::horizontalLine << Graphic::whiteSpace;
			flag = false;
		}
		else
		{
			flag = true;
		}
		
		if (flag)
		{
			std::cout << Graphic::whiteSpace << Graphic::whiteSpace;
		}
	}
}

void ModifiableIntegersFunction::printFunctionInInterval(short xStart, short yStart) const
{
	if (xStart > MAX_SHORT - Graphic::diffStartAndEnd || yStart > MAX_SHORT - Graphic::diffStartAndEnd)
		throw std::out_of_range("Cannot draw, x2 - x1 or y2 - y1 is > 20");

	short yEnd = yStart + Graphic::diffStartAndEnd;

	for (int y = yEnd; y >= yStart; y--)
	{
		printLine(xStart, y);

		std::cout << std::endl;
	}
}

void ModifiableIntegersFunction::countFunctionalValuesHelper(unsigned short* histogram) const
{
	for (int i = MIN_SHORT; i <= MAX_SHORT; i++)
	{
		if (!pointExcludingArray[i + DIFF])
		{
			if (histogram[inputSetterArray[i + DIFF] + DIFF] == ARRAY_SIZE - 1)//We don't want to overflow. Check conditon for functions like f(x) = number
				continue;

			histogram[inputSetterArray[i + DIFF] + DIFF]++;
		}
	}
}

ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& function, int times)
{
	ModifiableIntegersFunction toReturn;//Here it has default values. The function looks like f(x) = 0

	if (times < -1 || times == 0)
		throw std::out_of_range("K is out of range");

	if (times == -1)//invertable function
	{
		if (!(isInjection(function)))
			return toReturn;

		for (int i = 0; i < ModifiableIntegersFunction::ARRAY_SIZE; i++)
		{
			toReturn.inputSetterArray[function.inputSetterArray[i] + ModifiableIntegersFunction::DIFF] = 
				i + ModifiableIntegersFunction::MIN_SHORT;

			if (function.pointExcludingArray[i])
				toReturn.pointExcludingArray[function.inputSetterArray[i] + ModifiableIntegersFunction::DIFF] = true;
		}

		return toReturn;
	}

	toReturn = function;

	for (int i = 1; i < times; i++)
	{
		toReturn(toReturn);
	}

	return toReturn;
}

ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	ModifiableIntegersFunction toReturn(lhs);

	toReturn += rhs;

	return toReturn;
}

ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	ModifiableIntegersFunction toReturn(lhs);

	toReturn -= rhs;

	return toReturn;
}

bool operator||(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	const short diffConst = lhs.inputSetterArray[0] - rhs.inputSetterArray[0];
	//It doesn't matter which point we choose, 
	//the difference must be constant and must be 
	//the same for all points of the interval!

	for (int i = 0; i < ModifiableIntegersFunction::ARRAY_SIZE; i++)
	{
		if (!lhs.pointExcludingArray[i] != !rhs.pointExcludingArray[i])
			return false;

		if (diffConst != (lhs.inputSetterArray[i] - rhs.inputSetterArray[i]))
			return false;
	}

	return true;
}

bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	for (int i = 0; i < ModifiableIntegersFunction::ARRAY_SIZE; i++)
	{
		if (lhs.pointExcludingArray[i] && rhs.pointExcludingArray[i])//SHORT_MIN < SHORT_MIN is not true
			return false;

		if (rhs.pointExcludingArray[i])
			return false;

		if (lhs.pointExcludingArray[i])
			if (ModifiableIntegersFunction::MIN_SHORT == rhs.inputSetterArray[i])
				return false;

		if (lhs.inputSetterArray[i] >= rhs.inputSetterArray[i])
			return false;
	}

	return true;
}

bool operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	for (int i = 0; i < ModifiableIntegersFunction::ARRAY_SIZE; i++)
	{
		if (lhs.pointExcludingArray[i] && rhs.pointExcludingArray[i])
			continue;

		if (rhs.pointExcludingArray[i])
			if (!lhs.pointExcludingArray[i] && lhs.inputSetterArray[i] != ModifiableIntegersFunction::MIN_SHORT)
				return false;

		if (lhs.pointExcludingArray[i])
			continue;

		if (lhs.inputSetterArray[i] > rhs.inputSetterArray[i])
			return false;
	}

	return true;
}

bool operator>=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	for (int i = 0; i < ModifiableIntegersFunction::ARRAY_SIZE; i++)
	{
		if (lhs.pointExcludingArray[i] && rhs.pointExcludingArray[i])
			continue;

		if (lhs.pointExcludingArray[i])
			if (!rhs.pointExcludingArray[i] && rhs.inputSetterArray[i] != ModifiableIntegersFunction::MIN_SHORT)
				return false;

		if (rhs.pointExcludingArray[i])
			continue;

		if (lhs.inputSetterArray[i] < rhs.inputSetterArray[i])
			return false;
	}

	return true;
}

bool isInjection(const ModifiableIntegersFunction& func)
{
	 unsigned short histogram[ModifiableIntegersFunction::ARRAY_SIZE]{ 0 };

	func.countFunctionalValuesHelper(histogram);

	for (int i = 0; i < ModifiableIntegersFunction::ARRAY_SIZE; i++)
	{
		if (histogram[i] > 1)
			return false;
	}

	return true;
}

bool isSurjection(const ModifiableIntegersFunction& func)
{
	 unsigned short histogram[ModifiableIntegersFunction::ARRAY_SIZE]{ 0 };

	func.countFunctionalValuesHelper(histogram);

	for (int i = 0; i < ModifiableIntegersFunction::ARRAY_SIZE; i++)
	{
		if (histogram[i] == 0)
			return false;
	}

	return true;
}

bool operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	for (int i = 0; i < ModifiableIntegersFunction::ARRAY_SIZE; i++)
	{
		if (lhs.pointExcludingArray[i] && rhs.pointExcludingArray[i])
			return false;

		if (lhs.pointExcludingArray[i])
			return false;

		if (rhs.pointExcludingArray[i])
			if (ModifiableIntegersFunction::MIN_SHORT == lhs.inputSetterArray[i])
				return false;

		if (lhs.inputSetterArray[i] <= rhs.inputSetterArray[i])
			return false;
	}

	return true;
}

bool operator==(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	for (int i = 0; i < ModifiableIntegersFunction::ARRAY_SIZE; i++)
	{
		if (lhs.pointExcludingArray[i] && rhs.pointExcludingArray[i])
			continue;

		if (lhs.pointExcludingArray[i] && !rhs.pointExcludingArray[i])
			if (ModifiableIntegersFunction::MIN_SHORT != rhs.inputSetterArray[i])
				return false;

		if (!lhs.pointExcludingArray[i] && rhs.pointExcludingArray[i])
			if (ModifiableIntegersFunction::MIN_SHORT != lhs.inputSetterArray[i])
				return false;

		if (lhs.inputSetterArray[i] != rhs.inputSetterArray[i])
			return false;
	}

	return true;
}

bool operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	return !(lhs == rhs);
}

bool isBijection(const ModifiableIntegersFunction& func)
{
	return isInjection(func) && isSurjection(func);
}
