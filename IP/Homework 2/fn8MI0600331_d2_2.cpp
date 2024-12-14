/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Aleksandar Angelow
* @idnumber 8MI0600331
* @task 2
*
*/
#include <iostream>

int getLengthOfStr(const char str[]);

int getNumberOfProcents(const char str[]);

bool checkIfElementsAreValid(const char str[], const int size, const bool flag);

bool isDigit(const char element);

bool isSymbol(const char element);

bool isSpecialSymbol(const char element);

void swapElements(bool& firstSymbol, bool& secondSymbol);

void sortCharArray(bool* str, const int size, int startingIndex);

void findRightMostLargeSymbol(const bool str[], int& indexOfNextLargerSymbol, const int currentIndex);

void findRightMostSmallSymbol(const bool str[], int& currentIndex);

bool generateSequentialStr(bool str[], const int size);

void addIndex(int* usedIndexesArray, int index, const int size);

bool manageRepetitions(int* usedIndexesArray, int currentIndex, int sizeOfUsedIndexes);

bool containsIndex(int* usedIndexesArray, int index, const int size);

int searchForSpecialSubstringInCurrentVariant(const char* str, const char* templateStr, bool* procentsArray, int* usedIndexesArray, const int sizeOfUsedIndexes);

void generateAllVariantsOfString(const char* str, const char* templateStr, bool* procentsArray, const int size, int& counter);

int checkSymbolValue(const char* templateStr, const char*& str, int& counter, bool*& procentsArray);

void countSpecialSubstrings(const char* str, const char* templateStr, int& counter);

int findSubstrings(const char* str, const char* templateStr, const int sizeOftemplateStr);

int countMatches(const char str[], const char templateStr[]);

int main()
{
	const int MAX_SIZE = 1000;

	char str[MAX_SIZE]{};

	std::cin.getline(str, MAX_SIZE);

	int sizeOfStr = getLengthOfStr(str);

	if (checkIfElementsAreValid(str, sizeOfStr, 0))
	{
		char templateStr[MAX_SIZE]{};

		std::cin.getline(templateStr, MAX_SIZE);

		int sizeOfTemplateStr = getLengthOfStr(templateStr);

		if (checkIfElementsAreValid(templateStr, sizeOfTemplateStr, 1))
		{
			std::cout << countMatches(str, templateStr);
		}
		else
		{
			std::cout << "Incorrect input";
			return -1;
		}
	}
	else
	{
		std::cout << "Incorrect input";
		return -1;
	}

	return 0;
}

int getLengthOfStr(const char str[])
{
	int index = 0;

	while (str[index++]);

	return --index;
}

int getNumberOfProcents(const char str[])
{
	int index = 0;

	int counter = 0;

	while (str[index])
	{
		if (str[index++] == '%')
		{
			counter++;
		}
	}

	return counter;
}

bool isDigit(const char element)
{
	if (element >= '0' && element <= '9')
	{
		return true;
	}

	return false;
}

bool isSymbol(const char element)
{
	if ((element >= 'a' && element <= 'z') || (element >= 'A' && element <= 'Z'))
	{
		return true;
	}

	return false;
}

bool isSpecialSymbol(const char element)
{
	if (element == '*' || element == '%' || element == '@')
	{
		return true;
	}

	return false;
}

bool checkIfElementsAreValid(const char str[], const int size, const bool flag)
{
	for (int i = 0;i < size; i++)
	{
		if (!(isSymbol(str[i]) || isDigit(str[i]) || str[i] == ' ' || (flag && isSpecialSymbol(str[i]))))
		{
			return false;
		}
	}

	return true;
}

void addIndex(int* usedIndexesArray, int index, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!usedIndexesArray[i])
		{
			usedIndexesArray[i] = index;
		}
	}
}

bool containsIndex(int* usedIndexesArray, int index, const int size)
{
	for (int i = 0; i < size;i++)
	{
		if (*(usedIndexesArray++) == index)
			return true;
	}

	return false;
}

//This function checks the values of the elements in the original and the template string and returns if are equal/not equal/special case
int checkSymbolValue(const char* templateStr, const char* &str, int& counter, bool* &procentsArray)
{
	switch (*templateStr)
	{
		case '*':
		{
			counter++;
			return 0;
		}
		case '@':
		{
			if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			{
				counter++;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		case '%':
		{
			bool isCurrentDigit = *str >= '0' && *str <= '9';

			bool isNextDigit = *(str + 1) >= '0' && *(str + 1) <= '9';

			bool areDigits = isCurrentDigit && isNextDigit;

			if (!procentsArray)//Here procentsArray is nullptr
			{
				if (areDigits)
				{
					return 1;
				}
				else if(isCurrentDigit)
				{
					counter++;
					return 0;
				}
				else
				{
					return -1;
				}
			}
			else
			{
				//Here we check how many digits a procent refers to
				if (*procentsArray)
				{
					if (areDigits)
					{
						counter += 2;
						str++;
						procentsArray++;
						return 0;
					}
					else
					{
						return -1;
					}
				}
				else
				{
					if (isCurrentDigit)
					{
						counter++;
						procentsArray++;
						return 0;
					}
					else
					{
						return -1;
					}
				}
			}
		}
		default:
		{
			if (*templateStr == *str)
			{
				counter++;
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}
}

bool manageRepetitions(int* usedIndexesArray, int currentIndex, int sizeOfUsedIndexes)
{
	if (containsIndex(usedIndexesArray, currentIndex, sizeOfUsedIndexes))
	{
		return true;
	}
	else
	{
		addIndex(usedIndexesArray, currentIndex, sizeOfUsedIndexes);
		return false;
	}
}

int searchForSpecialSubstringInCurrentVariant(const char* str, const char* templateStr, bool* procentsArray, int* usedIndexesArray, const int sizeOfUsedIndexes)
{
	int currentIndex = 0;

	int currentCase = 0;

	while (*str && *templateStr)
	{
		currentCase = checkSymbolValue(templateStr, str, currentIndex, procentsArray);

		if (currentCase)
		{
			if (currentCase == -1)
			{
				return 0;
			}
		}
		
		templateStr++;
		str++;

		if (!*str && *templateStr)
		{
			return 0;
		}
	}

	//Here we check if the current substring has already been found
	if (manageRepetitions(usedIndexesArray, currentIndex, sizeOfUsedIndexes))
	{
		return 0;
	}

	return 1;
}

void swapElements(bool& firstSymbol, bool& secondSymbol)
{
	bool buff = firstSymbol;

	firstSymbol = secondSymbol;

	secondSymbol = buff;
}

void sortCharArray(bool* str, const int size, int startingIndex)
{
	for (int i = startingIndex; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (str[i] > str[j])
			{
				swapElements(str[j], str[i]);
			}
		}
	}
}

void findRightMostSmallSymbol(const bool str[], int& currentIndex)
{
	while (currentIndex >= 0 && str[currentIndex] >= str[currentIndex + 1])
	{
		currentIndex--;
	}
}

void findRightMostLargeSymbol(const bool str[], int& indexOfNextLargerSymbol, const int currentIndex)
{
	while (str[indexOfNextLargerSymbol] <= str[currentIndex])
	{
		indexOfNextLargerSymbol--;
	}
}

bool generateSequentialStr(bool str[], const int size)
{
	int currentIndex = size - 2;//Index of second-to-last symbol

	findRightMostSmallSymbol(str, currentIndex);

	if (currentIndex < 0)
	{
		return false;//All current variants of string are made
	}

	int indexOfNextLargerSymbol = size - 1;//Last symbol in the string

	findRightMostLargeSymbol(str, indexOfNextLargerSymbol, currentIndex);

	swapElements(str[currentIndex], str[indexOfNextLargerSymbol]);

	sortCharArray(str, size, currentIndex + 1);

	return true;
}

void generateAllVariantsOfString(const char* str, const char* templateStr, bool* procentsArray, const int size, int& counter)
{
	bool flag = true;

	int sizeOfUsedIndexes = getLengthOfStr(str);

	int* usedIndexesArray = new int[sizeOfUsedIndexes]{};

	while (flag)
	{
		counter += searchForSpecialSubstringInCurrentVariant(str, templateStr, procentsArray, usedIndexesArray, sizeOfUsedIndexes);

		if (!generateSequentialStr(procentsArray, size))
		{
			flag = false;//All variants of current array(procentsArray) have been made
		}
	}

	delete[] usedIndexesArray;
}

void addOneToProcentArray(bool* procentsArray, int counterOfTwo)
{
	for (int i = 0; i < counterOfTwo; i++)
	{
		if (i + 1 == counterOfTwo)
			procentsArray[i] = true;
		    //1(true)-Refers to two digits
		    //0(false)-Refers to one digit
	}
}

//This function will decide for each procent how many digits it will refer to
void countSpecialSubstrings(const char* str, const char* templateStr, int& counter)
{
	int counterOfTwo = 0;//This variable counts how many procents will take two digits

	int numberOfProcents = getNumberOfProcents(templateStr);

	//This array will contain all possible variations for the given percentages to take one or two digits
	bool* procentsArray = new bool[numberOfProcents + 1] {};

	for (int j = 0; j <= numberOfProcents; j++)
	{
		addOneToProcentArray(procentsArray, counterOfTwo);

		counterOfTwo++;

		sortCharArray(procentsArray, numberOfProcents, 0);

		generateAllVariantsOfString(str, templateStr, procentsArray, numberOfProcents, counter);
	}

	delete[] procentsArray;
}

int findSubstrings(const char* str, const char* templateStr, const int sizeOfTemplateStr)
{
	if (!str || !templateStr)
	{
		return NULL;
	}

	int counter = 0;

	int symbolCounter = 0;

	int currentCase = 0;

	bool* ptr = nullptr;

	while (*str && *templateStr)
	{
		currentCase = checkSymbolValue(templateStr, str, symbolCounter, ptr);//When ptr is a null pointer we don't check cases where ptr must be in use.

		if (currentCase)
		{
			if (currentCase == -1)
			{
				return 0;
			}
			else
			{
				countSpecialSubstrings(str, templateStr, counter);//We have encountered a procent and two digits

				return counter;
			}
		}

		if (symbolCounter == sizeOfTemplateStr)
		{
			return ++counter;
		}
		else
		{
			templateStr++;
			str++;
		}
	}

	return 0;
}

int countMatches(const char str[], const char templateStr[])
{
	int counter = 0;

	int sizeOfStr = getLengthOfStr(str);

	int sizeOfTemplateStr = getLengthOfStr(templateStr);

	for (int i = 0; (sizeOfStr - i) >= sizeOfTemplateStr;i++)
	{
		counter += findSubstrings(&str[i], templateStr, sizeOfTemplateStr);
	}

	return counter;
}