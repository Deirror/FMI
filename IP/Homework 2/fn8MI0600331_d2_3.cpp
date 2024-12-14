/**
*
* Solution to homework assignment 2
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

void swapElements(char& firstSymbol, char& secondSymbol);

void sortCharArray(char str[], const int size, int startingIndex);

bool generateSequentialStr(char str[], const int size);

void findRightMostSmallSymbol(const char str[], int& currentIndex);

void findRightMostLargeSymbol(const char str[], int& indexOfNextLargerSymbol, const int currentIndex);

void generateNLexicographicSmallStrings(char str[], const int size, int n);

int getLengthOfStr(const char str[]);

int main()
{
    const int MAX_SIZE = 1000;

    char str[MAX_SIZE]{};

    std::cin >> str;

    int n = 0;

    std::cin >> n;

    int size = getLengthOfStr(str);

    sortCharArray(str, size, 0);//Makes the string least lexicographical

    generateNLexicographicSmallStrings(str, size, n);

    return 0;
}

void swapElements(char& firstSymbol, char& secondSymbol)
{
    char buff = firstSymbol;

    firstSymbol = secondSymbol;

    secondSymbol = buff;
}

void sortCharArray(char str[], const int size, int startingIndex)
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

void findRightMostSmallSymbol(const char str[], int& currentIndex)
{
    while (currentIndex >= 0 && str[currentIndex] >= str[currentIndex + 1])
    {
        currentIndex--;
    }
}

void findRightMostLargeSymbol(const char str[], int& indexOfNextLargerSymbol, const int currentIndex)
{
    while (str[indexOfNextLargerSymbol] <= str[currentIndex])
    {
        indexOfNextLargerSymbol--;
    }
}

bool generateSequentialStr(char str[], const int size)
{
    int currentIndex = size - 2;//Index of second-to-last symbol

    findRightMostSmallSymbol(str,currentIndex);

    if (currentIndex < 0)
    {
        return false;//All variants of string are made
    }

    int indexOfNextLargerSymbol = size - 1;//Last symbol in the string

    findRightMostLargeSymbol(str, indexOfNextLargerSymbol, currentIndex);

    swapElements(str[currentIndex], str[indexOfNextLargerSymbol]);

    sortCharArray(str, size, currentIndex + 1);

    return true;
}

void generateNLexicographicSmallStrings(char str[], const int size, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << str << std::endl;

        if (!generateSequentialStr(str, size))
        {
            break;//All N lexicographical small strings have been printed
        }
    }
}

int getLengthOfStr(const char str[])
{
    int index = 0;

    while (str[index++]);

    return --index;
}
