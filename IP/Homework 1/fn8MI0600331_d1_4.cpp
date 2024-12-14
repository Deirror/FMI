/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Aleksandar Angelow
* @idnumber 8MI0600331
* @task 4
*
*/

#include <iostream>

void PrintIncorrectInput();

bool CheckIfDaysAreCorrect(int month, int day, int year);

int ReturnLastDayOfMonth(int month, int year);

bool IsYearLeap(int year);

void PrintIntervalsOfDates(int startYear, int startMonth, int startDay, int endYear, int endMonth, int endDay, int n);

void PrintLastDayOfMonth(int startDay, int startMonth, int startYear);

const int UNIQUE_YEAR = 1916;

const int UNIQUE_MONTH = 4;

const int UNIQUE_DAYS = 13;

const int LAST_MONTH = 12;

const int FIRST_MONTH = 1;

const int FIRST_DAY = 1;

int main()
{
	int startYear = 0, startMonth = 0 ,startDay = 0;

	int endYear = 0, endMonth = 0, endDay = 0;

	std::cin >> startYear >> startMonth >> startDay;
	
	std::cin >> endYear >> endMonth >> endDay;

	int n = 0;

	std::cin >> n;

	if (startYear <= endYear && (n >= 1 && n <= 365))
	{
		if (startYear >= 1600 && endYear <= 2100)
		{
			if ((startMonth >= FIRST_MONTH && endMonth >= FIRST_MONTH) && (startMonth <= LAST_MONTH && endMonth <= LAST_MONTH))
			{
				if ((startDay >= FIRST_DAY && endDay >= FIRST_DAY) && (CheckIfDaysAreCorrect(startMonth, startDay, startYear) && CheckIfDaysAreCorrect(endMonth, endDay, endYear)))
				{
					if ((startYear == UNIQUE_YEAR && startMonth == UNIQUE_MONTH && startDay <= UNIQUE_DAYS) || (endYear == UNIQUE_YEAR && endMonth == UNIQUE_MONTH && endDay <= UNIQUE_DAYS))
					{
						PrintIncorrectInput();

						return -1;
					}

					if (startYear == endYear && startMonth > endMonth)
					{
						PrintIncorrectInput();
					}
					else if (startYear == endYear && startMonth == endMonth)
					{
						if (startDay <= endDay)
						{
							PrintIntervalsOfDates(startYear, startMonth, startDay, endYear, endMonth, endDay, n);
						}
						else
						{
							PrintIncorrectInput();
						}
					}
					else if(startYear == endYear && startMonth < endMonth)
					{
						PrintIntervalsOfDates(startYear, startMonth, startDay, endYear, endMonth, endDay, n);
					}
					else if(startYear<endYear)
					{
						PrintIntervalsOfDates(startYear, startMonth, startDay, endYear, endMonth, endDay, n);
					}
				}
				else
				{
					PrintIncorrectInput();
				}
			}
			else
			{
				PrintIncorrectInput();
			}
		}
		else
		{
			PrintIncorrectInput();
		}
	}
	else
	{
		PrintIncorrectInput();
	}

	return 0;
}

void PrintLastDayOfMonth(int startDay, int startMonth, int startYear)
{
	if (startDay - 1 == 0)
	{
		if (startMonth - 1 == 0)
		{
			std::cout << startYear - 1 << "-" << LAST_MONTH << "-" << ReturnLastDayOfMonth(LAST_MONTH, startYear) << std::endl;
		}
		else
		{
			std::cout << startYear << "-" << startMonth - 1 << "-" << ReturnLastDayOfMonth(startMonth - 1, startYear) << std::endl;
		}
	}
	else
	{
		std::cout << startYear << "-" << startMonth << "-" << startDay - 1 << std::endl;
	}
}

void PrintIntervalsOfDates(int startYear, int startMonth, int startDay, int endYear, int endMonth, int endDay, int n)
{

	int lastdayOfMonth = ReturnLastDayOfMonth(startMonth, startYear);

	bool beforeOrAfterUniqueDate = (startYear==UNIQUE_YEAR && startMonth<UNIQUE_MONTH)||(startYear<UNIQUE_YEAR);

	while (true)
	{
		std::cout << startYear << "-" << startMonth << "-" << startDay << " - ";

		startDay += n;

		while (startDay > lastdayOfMonth)
		{
			startDay -= lastdayOfMonth;
				
			if (startMonth == LAST_MONTH)
			{
				startMonth = FIRST_MONTH;
				startYear++;
				lastdayOfMonth = ReturnLastDayOfMonth(startMonth, startYear);
			}
			else
			{
				startMonth++;
				lastdayOfMonth = ReturnLastDayOfMonth(startMonth, startYear);
			}

			if (startYear == UNIQUE_YEAR && startMonth >= UNIQUE_MONTH && startDay!=FIRST_DAY && beforeOrAfterUniqueDate)
			{
				startDay += UNIQUE_DAYS;
				beforeOrAfterUniqueDate = false;
			}
		}

		if (startYear == endYear)
		{
			if (startMonth == endMonth)
			{
				if (startDay - 1 < endDay)
				{
					PrintLastDayOfMonth(startDay, startMonth, startYear);
				}
				else
				{
					std::cout << endYear << "-" << endMonth << "-" << endDay;
					break;
				}
			}
			else if(startMonth > endMonth)
			{
				std::cout << endYear << "-" << endMonth << "-" << endDay;
				break;
			}
			else
			{
				PrintLastDayOfMonth(startDay, startMonth, startYear);
			}
		}
		else if(startYear>endYear)
		{
			std::cout << endYear << "-" << endMonth << "-" << endDay;
			break;
		}
		else
		{
			PrintLastDayOfMonth(startDay, startMonth, startYear);
		}
		
		if (startYear == UNIQUE_YEAR && startMonth >= UNIQUE_MONTH && startDay == 1 && beforeOrAfterUniqueDate)
		{
			startDay += UNIQUE_DAYS;
			beforeOrAfterUniqueDate = false;
		}

	}
	
}

bool IsYearLeap(int year)
{
	if (year > UNIQUE_YEAR)
	{
		if ((year % 4 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			return true;
		}
		else
			return false;
	}
	else
	{
		if (year % 4 == 0)
		{
			return true;
		}
		else
			return false;
	}
}

int ReturnLastDayOfMonth(int month, int year)
{
	int lastDay = 0;

	switch (month)
	{
	  case 1:
	  case 3:
	  case 5:
	  case 7:
	  case 8:
	  case 10:
	  case 12:
	  {
		  lastDay = 31;
		  break;
	  }
	  case 2:
	  {
		  if (IsYearLeap(year))
		  {
			  lastDay = 29;
		  }
		  else
		  {
			  lastDay = 28;
		  }
		  break;
	  }
	  case 4:
	  case 6:
	  case 9:
	  case 11:
	  {
		  lastDay = 30;
		  break;
	  }

	}
	return lastDay;
}

bool CheckIfDaysAreCorrect(int month,int day, int year)
{
	if (day <= ReturnLastDayOfMonth(month, year))
	{
		return true;
	}
	else
		return false;
}

void PrintIncorrectInput()
{
	std::cout << "Incorrect input";
}