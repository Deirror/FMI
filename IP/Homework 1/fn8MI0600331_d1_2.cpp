/**
*
* Solution to homework assignment 1
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

void PrintIncorrentInput();

bool CheckIfIndexIsAdded(int arrayOfUsedIndexes[], const int SIZE, int index);

bool InputArray(int arr[], const int SIZE, const int MAX_SIZE);

void AddUsedIndex(int arrayOfUsedIndexes[], const int SIZE, int index);

int MinimalNumberOfPeople(const int arr[], const int SIZE);

void CheckNumberOfElementInArray(int number, int currentindex, const int arr[], const int SIZE, int arrayOfUsedIndexes[]);

const int MAX_SIZE = 1000;

int main()
{
	int n = 0;

	std::cin >> n;

	if (n >= 1 && n <= MAX_SIZE)
	{

		int arrNumberOfPeople[MAX_SIZE] = {};

		if (InputArray(arrNumberOfPeople, n, MAX_SIZE))
		{
	        std::cout << MinimalNumberOfPeople(arrNumberOfPeople,n);
		}
		else
		{
			PrintIncorrentInput();
		}
	}
	else
	{
		PrintIncorrentInput();
	}

	return 0;
}

bool CheckIfIndexIsAdded(int arrayOfUsedIndexes[], const int SIZE, int index)
{
	for (int i = 0;i < SIZE;i++)
	{
		
		if (arrayOfUsedIndexes[i] == index + 1)
		{
			return true;
		}
	}

	return false;
}

void AddUsedIndex(int arrayOfUsedIndexes[], const int SIZE, int index)
{
	for (int i = 0;i < SIZE;i++)
	{
		if (arrayOfUsedIndexes[i] == 0)
		{
			//All elements are 0 and array starts from index 0, so we add index+1. In that way the arrayOfUsedIndexes contains each index from arr.
			arrayOfUsedIndexes[i] = index + 1;
			break;
		}
	}
}

void CheckNumberOfElementInArray(int number,int currentindex,const int arr[],const int SIZE, int arrayOfUsedIndexes[])
{
	int minimalnumber = number;

	AddUsedIndex(arrayOfUsedIndexes,SIZE,currentindex);

	if (number != 0)
	{

		for (int i = currentindex + 1, j = 0;i < SIZE;i++)
		{
			if (number == arr[i])
			{
				AddUsedIndex(arrayOfUsedIndexes, SIZE, i);
				j++;
				if (minimalnumber <= j) break;

			}
		}
	}
}



int MinimalNumberOfPeople(const int arr[], const int SIZE)
{
	int sumOfMinimalNumber = 0;

	int arrayOfUsedIndexes[MAX_SIZE] = {};

	for (int i = 0;i < SIZE;i++)
	{
		if (!CheckIfIndexIsAdded(arrayOfUsedIndexes,SIZE,i))
		{
			CheckNumberOfElementInArray(arr[i], i, arr, SIZE, arrayOfUsedIndexes);

			sumOfMinimalNumber += arr[i]+1;
		}
	}
	return sumOfMinimalNumber;
}

bool InputArray(int arr[], const int SIZE, const int MAX_SIZE)
{
	for (int i = 0;i < SIZE;i++)
	{
		std::cin >> arr[i];
		if (arr[i] < 0 || arr[i] > MAX_SIZE)
		{
			return false;
		}
	}

	return true;
}

void PrintIncorrentInput()
{
	std::cout << "Incorrect input";
}
