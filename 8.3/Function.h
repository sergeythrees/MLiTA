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
		for (int j=0; j < size && !wasInserted; ++j)
		{
			for (int k=0; k < size && !wasInserted; ++k)
			{
				if (result[j][k] == -1)
				{
					if (VerifyForRow(left, result, j, k, number) &&
						VerifyForCell(top, result, j, k, number))
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
	std::vector<std::vector<T>>& matrix, int rowIndex, int cellIndex, int number)
{
	bool result = true;
	int size = left[rowIndex].size();
	for (int i= cellIndex +1; i < size && result; ++i )
	{
		
		if (cellIndex > i - left[rowIndex][i] || cellIndex == i - left[rowIndex][i])
		{
			if (matrix[rowIndex][i] == -1)
			{
				result = false;
			}
		}
		if (matrix[i][cellIndex] != -1)
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
bool VerifyForCell(std::vector<std::vector<T>>& top, 
	std::vector<std::vector<T>>& matrix, int rowIndex, int cellIndex, int number)
{
	bool result = true;
	int size = top.size();
	for (int i = rowIndex + 1; i < size && result; ++i)
	{
		
			if (rowIndex > i - top[i][cellIndex] || rowIndex == i - top[i][cellIndex])
			{
				if (matrix[i][cellIndex] == -1)
				{
					result = false;
				}
			}
			if (matrix[i][cellIndex] != -1)
			{
				if (top[i][cellIndex] == 0 && matrix[i][cellIndex] < number)
				{
					result = false;
				}
			}
	}
	return result;
}


