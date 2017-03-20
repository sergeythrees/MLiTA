#pragma once
#include "stdafx.h"

template <typename T>
bool GenerateMatrix(std::vector<std::vector<T>>& result, std::vector<std::vector<T>>& top,
	std::vector<std::vector<T>>& left, int numbersCount)
{
	int size = result.size();

	bool wasInserted = true;
	for (int number = 1; number <= numbersCount && wasInserted; ++number)
	{
		wasInserted = false;
		for (int j = 0; j < size && !wasInserted; ++j)
		{
			for (int k = 0; k < size && !wasInserted; ++k)
			{
				if (result[j][k] == -1)
				{
					if (VerifyForRow(left, result, j, k, number) &&
						VerifyForColumn(top, result, j, k, number))
					{
						result[j][k] = number;
						wasInserted = true;
					}

				}
			}
		}
	}

	return wasInserted;
}

template <typename T>
bool VerifyForRow(std::vector<std::vector<T>>& left, 
	std::vector<std::vector<T>>& matrix, int rowIndex, int columnIndex, int number)
{
	bool result = true;
	int size = left[rowIndex].size();
	for (int i= columnIndex +1; i < size && result; ++i )
	{
		if (matrix[rowIndex][i] == -1)
		{
			if ((GetFreeCellsCount(matrix, rowIndex, 0, i, -1, true) <= left[rowIndex][i]))
			{
				result = false;
			}
		}
		else
		{
			if (left[rowIndex][i] == 0 && left[rowIndex][i] < number)
			{
				result = false;
			}
		}
	}
	return result;
}

template <typename T>
bool VerifyForColumn(std::vector<std::vector<T>>& top, 
	std::vector<std::vector<T>>& matrix, int rowIndex, int columnIndex, int number)
{
	bool result = true;
	int size = top.size();
	for (int i = rowIndex + 1; i < size && result; ++i)
	{
		if (matrix[i][columnIndex] == -1)
		{
			if ((GetFreeCellsCount(matrix, columnIndex, 0, i, -1, false)
				<= top[i][columnIndex]))
			{
				result = false;
			}
		}
		else
		{
			if (top[i][columnIndex] == 0 && matrix[i][columnIndex] < number)
			{
				result = false;
			}
		}
	}
	return result;
}

template <typename T>
bool VerifyTopAndLeftMatrix(std::vector<std::vector<T>>& top,
	std::vector<std::vector<T>>& left)
{
	for (int column = 0; column < top.size(); ++column)
		for (int row = 0; row < top.size(); ++row)
			if (top[row][column] > row)
				return false;
	for (int row = 0; row < top.size(); ++row)
		for (int column = 0; column < left.size(); ++column)
			if (left[row][column] > column)
				return false;

	return true;
}

template <typename T>
unsigned GetFreeCellsCount(std::vector<std::vector<T>>& matrix,
	unsigned fieldNumber, unsigned from, unsigned to, 
	T freeCellValue, bool isForRow)
{
	unsigned count = 0;
	if (isForRow)
	{
		for (int i = from; i < to; ++i)
			if (matrix[fieldNumber][i] == freeCellValue)
				++count;
	}
	else
	{
		for (int i = from; i < to; ++i)
			if (matrix[i][fieldNumber] == freeCellValue)
				++count;
	}

	return count;
}