#include <iostream>
#include <fstream>
#include "FunctionDebugger.h"
#include "functionFileReader.h"
#include "PartialFunction.h"
#include "UniquePointer.hpp"
 
int main()
{
	try
	{
		UniquePointer<PartialFunction> function = functionFileReader("func.dat");

		FunctionDebugger::debug(function);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	catch (...)
	{
		std::cout << "Unknown error?" << std::endl;
	}
}