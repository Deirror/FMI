#include "ModifiableIntegersFunction.h"
#include <math.h>
#include <iostream>

int main()
{
	ModifiableIntegersFunction func1([](short x) -> short {return x/2 ;});

	ModifiableIntegersFunction func2([](short x) -> short {return x/2 + 1;});

	func1.printFunctionInInterval(-10, -10);

	//func1.excludePoint(0);

	//func2.excludePoint(0);

	//std::cout << (func1 || func2);

	return 0;
}