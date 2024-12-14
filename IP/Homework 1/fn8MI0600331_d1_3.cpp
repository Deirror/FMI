/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Aleksandar Angelow
* @idnumber 8MI0600331
* @task 3
*
*/

#include <iostream>

void OutputArray(char arr[], const int SIZE);

void RemoveCombinationFromArray(char arrayOfSymbols[], int n, int distance, int startingIndex);

int LeftSideCheckForCombination(char arrayOfSymbols[], int indexOfShotBall);

int RightSideCheckForCombination(char arrayOfSymbols[], int n, int indexOfShotBall);

void CheckIfCombination(char arrayOfSymbols[], int& n, int index);

void AddBallInArray(char arrayOfSymbols[], int& n, int index, char ball);

void InputIndexesAndShotBalls(int s, char arrayOfSymbols[], int& n);

bool InputArray(char arr[], const int SIZE);

void PrintIncorrentInput();

const int MAX_SIZE = 256;

int main()
{
	int n = 0;
	
	std::cin >> n;

	if (n > 0 && n < 256)
	{
		char arrayOfSymbols[MAX_SIZE] = {};

		if (InputArray(arrayOfSymbols, n))
		{
			int s = 0;
			std::cin >> s;
			if (s >= 0 && s <= 127)
			{
				InputIndexesAndShotBalls(s, arrayOfSymbols, n);

				OutputArray(arrayOfSymbols, n);
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
	}
	else
	{
		PrintIncorrentInput();
	}

	return 0;
}

void RemoveCombinationFromArray(char arrayOfSymbols[], int n,int distance,int startingIndex)
{
	for (int i = startingIndex; i + distance < n; i++)
	{
		arrayOfSymbols[i] = arrayOfSymbols[i + distance];
	}
}

int LeftSideCheckForCombination(char arrayOfSymbols[], int indexOfShotBall)
{
	int count = 0;
	for (int i = indexOfShotBall; i > 0; i--)
	{
		if (arrayOfSymbols[i] == arrayOfSymbols[i - 1])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}

int RightSideCheckForCombination(char arrayOfSymbols[], int n, int indexOfShotBall)
{
	int count = 0;

	for (int i = indexOfShotBall; i < n-1; i++)
	{
		if (arrayOfSymbols[i] == arrayOfSymbols[i + 1])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}

void CheckIfCombination(char arrayOfSymbols[], int &n, int index)
{
	bool flag = true;

	int indexOfShotBall = index + 1;

	while (flag)
	{
		if (indexOfShotBall <= n)
		{
			int leftside = LeftSideCheckForCombination(arrayOfSymbols,indexOfShotBall);

			int rightside = RightSideCheckForCombination(arrayOfSymbols, n, indexOfShotBall);

			int wholecount = leftside + rightside + 1;

			if (wholecount >= 3)
			{                                                               
				RemoveCombinationFromArray(arrayOfSymbols, n, wholecount, indexOfShotBall - leftside);
				
				n -= wholecount;

				indexOfShotBall -= leftside;
			}
			else
			{
				flag = false;
			}
		}
		else
		{
			flag = false;
		}
	}


}

void AddBallInArray(char arrayOfSymbols[], int &n, int index, char ball)
{
	for (int i = n; i > index;i--)
	{
		arrayOfSymbols[i + 1] = arrayOfSymbols[i];
	}

	arrayOfSymbols[index + 1] = ball;

	n++;

}

void InputIndexesAndShotBalls(int s, char arrayOfSymbols[],int &n)
{
	int index = 0;
	char ball = 'a';
	for (int i = 1; i <= s;i++)
	{
		std::cin >> index >> ball;

		if (index >= 0 && index < n)
		{
			AddBallInArray(arrayOfSymbols,n,index,ball);

			CheckIfCombination(arrayOfSymbols, n, index);
		}
	}


}

bool InputArray(char arr[], const int SIZE)
{
	for (int i = 0;i < SIZE;i++)
	{
		std::cin >> arr[i];

		if (arr[i] < 'a' || arr[i] > 'z')
		{
			return false;
		}
	}

	return true;
}

void OutputArray(char arr[], const int SIZE)
{
	if (SIZE == 0)
	{
		std::cout << -1;
	}
	else
	{
		for (int i = 0;i < SIZE;i++)
		{
			std::cout << arr[i] << " ";
		}
	}
}

void PrintIncorrentInput()
{
	std::cout << "Incorrect input";
}