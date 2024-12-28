#include "MultiSet.h"
#include <iostream>

int main()
{
	MultiSet ms(2,2);

	ms.addNumber(1, 3);

	ms.addNumber(0);

	ms.printMultiSetInMemory();

	MultiSet ms1 = complement(ms);

	ms1.printMultiSetInMemory();

	MultiSet msMix = intersection(ms, ms1);

	msMix.printMultiSetInMemory();

	msMix = difference(ms, ms1);

	msMix.printMultiSetInMemory();

	return 0;
}