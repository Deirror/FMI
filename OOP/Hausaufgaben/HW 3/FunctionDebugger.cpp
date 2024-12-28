#include "FunctionDebugger.h"
#include <stdexcept>
#include <iostream>

void FunctionDebugger::debug(const UniquePointer<PartialFunction>& _function)
{
	if (!_function)
		throw std::invalid_argument("Nullptr");

	const FunctionDebugger funcDebugger(_function);//We don't want to change the object

	std::cout << "Choose regime :\n";

	int regime = 0;

	do
	{
	std::cout << "1.Print values in interval\n";
	std::cout << "2.Generate next defined point\n";
	std::cout << "3.Exit\n> ";

	std::cin >> regime;

	switch (regime)
	{
	case 1:
	{
		std::cout << "Input interval:\n> ";

		int start = 0;
		int end = 0;

		std::cin >> start >> end;

		funcDebugger.printInInterval(start, end);

		break;
	}
	case 2:
	{
		int subRegime = 0;

		std::cout << "Which regime would you like?\n";
		std::cout << "1.Starting from INT_MIN\n";
		std::cout << "2.Starting from a given point\n> ";

		std::cin >> subRegime;

	    funcDebugger.generateNextValuesRegime(subRegime);

		break;
	}
	case 3:
	{
		break;//Exit
	}
	default:
	{
		std::cout << "Invalid regime!\n";
	}
	}

	std::cout << "-----------------------" << std::endl;

	} while (regime != 3);
}

FunctionDebugger::FunctionDebugger(const UniquePointer<PartialFunction>& _function) 
	: function(_function)
{

}

void FunctionDebugger::printInInterval(int start, int end) const
{
	if (start > end)
		std::swap<int>(start, end);

	for (int i = start; i <= end; i++)
	{
		try
		{
			std::cout << "f(" << i << ") = " << function->operator()(i) << std::endl;
		}
		catch (std::invalid_argument&)
		{
		    //The result is undefined
		}
		catch (...)
		{

		}
	}
}

void FunctionDebugger::generateNextValuesRegime(int choice) const
{
	if (choice < 1 || choice > 2)
	{
		std::cout << "Invalid subRegime\n";
		return;
	}

	std::cout << "Generating directing( l or r ):\n> ";

	char direction = '\0';

	std::cin >> direction;

	if (direction != 'l' && direction != 'r')
	{
		std::cout << "Invalid direction\n";
		return;
	}

	int diff = (direction == 'l') ? -1 : 1;

	switch (choice)
	{
	case 1:
	{
		int32_t min = (1 << 31);

		printNextDefinedValues(min, diff);
	}
	case 2:
	{
		std::cout << "Write a starting x:\n> ";

		int32_t x = 0;

		std::cin >> x;

		printNextDefinedValues(x, diff);
	}
	}

}

void FunctionDebugger::printNextDefinedValues(int32_t x, int diff) const
{
	bool flag = true;

	while (flag)
	{
		try
		{
			std::cout << "f(" << x << ") = " << function->operator()(x) << std::endl;

			flag = false;
		}
		catch (std::invalid_argument&)
		{
			//The point is not defined
			x += diff;
			continue;
		}

		std::cout << "Do you want to continue generating? ( y or n )\n> ";

		char answer = '\0';

		std::cin >> answer;

		switch (answer)
		{
		case 'y':
		{
			flag = true;
			x += diff;
			break;
		}
		case 'n':
		{
			flag = false;
			break;
		}
		default:
		{
			std::cout << "Oops, unknown answer\n";
			flag = false;
			break;
		}
		}
	}
}
