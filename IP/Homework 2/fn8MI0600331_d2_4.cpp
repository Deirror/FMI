/**
*
* Solution to homework assignment 2
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
//Columns of directionsArray
const int COLS = 2;

void fillRowOfArray(int* rowOfArray, const int sizeOfRow);

int** allocateMatrix(const int n, int* lengthOfRowsArray);

void deallocateMatrix(int** matrix, const int n);

int getValueOfMinInt();

int returnLongerPath(const int lengthOfCurrentPath, const int currentMaxLength);

int findLongestIncreasingSequence(int** matrix, const int n, const int* lengthOfRowsArray, const int directionsArray[][COLS], const int rowsOfDirectionArray, int row, int col, int valueOfPreviousElement, int length);

void visitAllElementsOfMatrix(int** matrix, const int n, const int* lengthOfRowsArray, const int directionsArray[][COLS], const int rowsOfDirectionsArray, const int minInt, int i, int& maxLength);

void getMaxPath(int** matrix, const int n, const int* lengthOfRowsArray, int& maxLength);

int main() 
{
    int n = 0;

    std::cin >> n;

    if (n <= 0)
    {
        std::cout << "Incorrect input";
        return -1;
    }

    int* lengthOfRowsArray = new int[n];

    int** matrix = allocateMatrix(n, lengthOfRowsArray);
 
    if (!matrix)
    {
        std::cout << "Incorrect input";
        return -1;
    }

    int maxLength = 0;

    getMaxPath(matrix, n, lengthOfRowsArray, maxLength);

    std::cout << maxLength;

    delete[]lengthOfRowsArray;

    deallocateMatrix(matrix, n);

    return 0;
}

void fillRowOfArray(int* rowOfArray, const int sizeOfRow)
{
    for (int i = 0; i < sizeOfRow;i++)
    {
        std::cin >> rowOfArray[i];
    }
}

int** allocateMatrix(const int n, int* lengthOfRowsArray)
{
    if (!lengthOfRowsArray)
    {
        return nullptr;
    }

    int** matrix = new int* [n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> lengthOfRowsArray[i];

        if (lengthOfRowsArray[i] < 0)
        {
            return nullptr;
        }

        matrix[i] = new int[lengthOfRowsArray[i]];

        fillRowOfArray(matrix[i], lengthOfRowsArray[i]);
    }

    return matrix;
}

void deallocateMatrix(int** matrix, const int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int getValueOfMinInt()
{
    return (1 << 31);
}

int returnLongerPath(const int lengthOfCurrentPath, const int currentMaxLength)
{
    if (lengthOfCurrentPath > currentMaxLength)
    {
        return lengthOfCurrentPath;
    }

    return currentMaxLength;
}

int findLongestIncreasingSequence(int** matrix, const int n, const int* lengthOfRowsArray, const int directionsArray[][COLS], const int rowsOfDirectionArray, int row, int col, int valueOfPreviousElement, int length)
{
    //Index is out of bounds of array
    if (row < 0 || row >= n || col < 0 || col >= lengthOfRowsArray[row])
    {
        return length;
    }

    //Here we check if the sequence is still increasing or when we return to the former element
    if (matrix[row][col] <= valueOfPreviousElement)
    {
        return length;
    }

    int maxLength = length;

    //This loop check in the next value in all directions
    for (int i = 0; i < rowsOfDirectionArray; i++)
    {
        int nextRow = row + directionsArray[i][0];
        int nextCol = col + directionsArray[i][1];

        int currentLength = findLongestIncreasingSequence(matrix, n, lengthOfRowsArray, directionsArray, rowsOfDirectionArray, nextRow, nextCol, matrix[row][col], length + 1);
        
        maxLength = returnLongerPath(currentLength, maxLength);
    }

    return maxLength;
}

void visitAllElementsOfMatrix(int** matrix, const int n, const int* lengthOfRowsArray, const int directionsArray[][COLS], const int rowsOfDirectionsArray, const int minInt, int i, int& maxLength)
{
    for (int j = 0; j < lengthOfRowsArray[i]; j++)
    {
        int currentLength = findLongestIncreasingSequence(matrix, n, lengthOfRowsArray, directionsArray, rowsOfDirectionsArray, i, j, minInt, 0);

        maxLength = returnLongerPath(currentLength, maxLength);
    }
}

void getMaxPath(int** matrix, const int n, const int* lengthOfRowsArray, int& maxLength)
{
    if (!matrix || !lengthOfRowsArray)
    {
        return;
    }

    int minInt = getValueOfMinInt();//Starting value of previous elements

    const int rowsOfDirectionsArray = 8;

    //Check in all possible directions: up, down, left, right, up-left, up-right, down-left, down-right
    const int directionsArray[rowsOfDirectionsArray][COLS] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

    for (int i = 0; i < n; i++)
    {
        visitAllElementsOfMatrix(matrix, n, lengthOfRowsArray, directionsArray, rowsOfDirectionsArray, minInt, i, maxLength);
    }
}