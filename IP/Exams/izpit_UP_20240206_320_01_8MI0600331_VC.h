//Aleksandar Angelow, 8MI0600331
#pragma once

//Task 1
int getGreatestDigit(const int digitArrayHistogram[], const int MAX_SIZE)
{
	for (int i = MAX_SIZE - 1; i >= 0; i--)
	{
		if (digitArrayHistogram[i] == 0)
		{
			return i;
		}
	}

	return -1;
}

int analyzeArray(const char* str)
{
	if (!str)
		return - 1;

	const int MAX_SIZE = 10;
	int digitArrayHistogram[MAX_SIZE]{};

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			digitArrayHistogram[(*str) - '0']++;
		}

		str++;
	}

	return getGreatestDigit(digitArrayHistogram, MAX_SIZE);
}

//Task 2
int findIndex(const int arr[], size_t size)
{
	int counter = 0;

	int resultIndex = 0;

	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[j] >= i)
			{
				counter++;
			}
		}

		if (counter >= i)
			return i;
		else
			counter = 0;
	}
}

//Task 3
int myABS(int condition)
{
	if (condition < 0)
	{
		return condition * (-1);
	}

	return condition;
}

void addElement(int usedElementsArray[], int number, int& size)
{
	usedElementsArray[size] = number;
	size++;
}

bool containsElement(int usedElementsArray[], int number, int &size)
{
	for (int i = 0; i < size; i++)
	{
		if (number == usedElementsArray[i])
		{
			return false;
		}
	}

	return true;
}

int getGreatestElement(const long arr[], size_t N, int &currentMaxElement, int usedElementsArray[], int &size)
{
	int maxElement = 0;
	int index = 0;

	for (int i = 0; i < N; i++)
	{
		if (maxElement < arr[i] && arr[i] != currentMaxElement && containsElement(usedElementsArray, arr[i], size))
		{
			maxElement = arr[i];
			index = i;
		}
	}

	currentMaxElement = maxElement;

	return index;
}

int getCountOfDigits(int number)
{
	int counter = 0;

	while (number != 0)
	{
		number /= 10;
		counter++;
	}

	return counter;
}

void writeNumber(char* resultStr, int number, int index)
{
	while (number != 0)
	{
		resultStr[index--] = (number % 10) + '0';
		number /= 10;
	}
	
}

void writeNumbersInArray(char* resultStr,int currentMaxElement, int nextMaxElement)
{
	int index = 0;

	int digits = getCountOfDigits(currentMaxElement);

	index += digits-1;

	writeNumber(resultStr, currentMaxElement, index);

	resultStr[++index] = ',';

	digits = getCountOfDigits(nextMaxElement);

	index += digits;

	writeNumber(resultStr, nextMaxElement, index);
}

void resetArray(int usedElementArray[], int& size)
{
	for (int i = 0; i < size; i++)
	{
		usedElementArray[i] = -1;
	}
	size = 0;
}

char* findDiff(const long arr[], size_t N)
{
	if (N <= 1)
		return nullptr;

	const int SIZE = 100;
	char* resultStr = new char[SIZE] {};

	int currentMaxElement = -1;
	int indexOfCurrentMaxElement = 0;

	const int MAX_SIZE = 1000;
	int usedElementsArray[MAX_SIZE];

	int sizeOfUsedElements = 0;

	int greatestMaxNumber = 0;
	getGreatestElement(arr, N, greatestMaxNumber, usedElementsArray, sizeOfUsedElements);

	int nextNum = 0;

	for (int n = 0; n <= greatestMaxNumber; n++)
	{
		for (int i = 0; i < N; i++)
		{
			indexOfCurrentMaxElement = getGreatestElement(arr, N, currentMaxElement, usedElementsArray, sizeOfUsedElements);

			for (int j = 0; j < N; j++)
			{
				if (j != indexOfCurrentMaxElement)
				{
					nextNum = arr[j];
					if (myABS(currentMaxElement - nextNum) == n)
					{
						writeNumbersInArray(resultStr, currentMaxElement, nextNum);
						return resultStr;
					}
				}
			}
			addElement(usedElementsArray, currentMaxElement, sizeOfUsedElements);
		}
		resetArray(usedElementsArray, sizeOfUsedElements);
	}	
}
