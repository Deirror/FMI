/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Aleksandar Angelow
* @idnumber 8MI0600331
* @task 1
*
*/
#include <iostream>

void generateTwoEncodingsOfSymbol(char symbol, char* encodedStr);

char* encodeString(const char str[], const int sizeOfStr, const int sizeOfEncodedStr);

void outputArray(const char* encodedStr);

int getLenghtOfString(const char str[]);

int main()
{
	const int MAX_SIZE = 64;

	char str[MAX_SIZE+1]{};//Also including terminating zero

	std::cin.getline(str, MAX_SIZE+1);

	int sizeOfStr = getLenghtOfString(str);

	int sizeOfEncodedStr = sizeOfStr * 2;//One symbol refers to two encodings

	char* encodedStr = encodeString(str, sizeOfStr, sizeOfEncodedStr);

	outputArray(encodedStr);

	delete[] encodedStr;

	return 0;
}

void generateTwoEncodingsOfSymbol(char symbol, char* encodedSymbolsArr)
{
	if (!encodedSymbolsArr)
		return;

	unsigned short twoEncodingsNum = 0;//The number which contains the two encodings of the symbol

	short multiplier = 0;

	bool bit = false;

	for (int i = 0; i < 8; i++)//Loops through 8 bits
	{
		bit = (symbol & (1 << i)) ? 1 : 0;

		switch (bit)
		{
			case true:
			{
				twoEncodingsNum |= ((bit << 1) << (multiplier++) * 2);
				break;
			}
			case false:
			{
				twoEncodingsNum |= ((bit + 1) << (multiplier++) * 2);
				break;
			}
		}

	}

	*encodedSymbolsArr = ((twoEncodingsNum & 0xff00) >> 8);
	*(encodedSymbolsArr + 1) = twoEncodingsNum & 0xff;
}

char* encodeString(const char str[], const int sizeOfStr, const int sizeOfEncodedStr)
{
	char* encodedSymbolsArr = new char[sizeOfEncodedStr + 1]{};//Including terminating zero

	for (int i = 0, j = 0; i < sizeOfEncodedStr; i += 2, j++)
	{
		generateTwoEncodingsOfSymbol(str[j], encodedSymbolsArr + i);
	}

	return encodedSymbolsArr;
}

void outputArray(const char* encodedStr)
{
	if (!encodedStr)
		return;

	while (*encodedStr)
	{
		std::cout << *encodedStr++;
	}
}

int getLenghtOfString(const char str[])
{
	int index = 0;

	while (str[index++]);//Loops until terminating zero

	return --index;
}
