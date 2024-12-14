/**
*
* Solution to homework assignment 1
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

int NumberOfDivisors(const int number);

int main()
{
	int n = 0, k = 0;

	std::cin >> n >> k;

	if (n > 0 && k > 0)
	{

		int count = 0;

		for (int x = 1;x <= n;x++)
		{
			int dx = NumberOfDivisors(x);

			for (int y = x;y <= n;y++)
			{
				int dy = NumberOfDivisors(y);
				if (k * dx * dy == x * y)
				{
					count++;
				}
			}
		}
		std::cout << count;
	}
	else
	{
		std::cout << "Incorrect input";
	}

	return 0;
}

int NumberOfDivisors(const int number)
{
	int count = 0;

	for (int i = 1; i <= number;i++)
	{
		if (number % i == 0)
		{
			count++;
		}
	}

	return count;
}