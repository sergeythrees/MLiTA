#pragma once
#include "stdafx.h"

template <typename T>
bool GenerateMatrix(std::vector<std::vector<T>>& result, std::vector<std::vector<T>>& top,
	std::vector<std::vector<T>>& left, int numbersCount)
{
	int size = result.size();

	int j = 0;
	int k = 0;
	bool wasInserted = true;
	for (int number = 1; number <= numbersCount && wasInserted; ++number)
	{
		wasInserted = false;

		if (j >= size - 1)
			j = 0;
		while ((j < size) && !wasInserted)
		{
			if (k >= size - 1)
				k = 0;
			while ((k < size) && !wasInserted)
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
				if (!wasInserted)
					++k;
			}
			if (!wasInserted)
				++j;
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
		
		if (matrix[rowIndex][i] == -1)
		{
			if (cellIndex > i - left[rowIndex][i] || cellIndex == i - left[rowIndex][i])
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
bool VerifyForCell(std::vector<std::vector<T>>& top, 
	std::vector<std::vector<T>>& matrix, int rowIndex, int cellIndex, int number)
{
	bool result = true;
	int size = top.size();
	for (int i = rowIndex + 1; i < size && result; ++i)
	{
		if (matrix[i][cellIndex] == -1)
		{
			if (rowIndex > i - top[i][cellIndex] || rowIndex == i - top[i][cellIndex])
			{
				result = false;
			}
		}
		else
		{
			if (top[i][cellIndex] == 0 && matrix[i][cellIndex] < number)
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
	for (int cell = 0; cell < top.size(); ++cell)
		for (int row = 0; row < top.size(); ++row)
			if (top[row][cell] > row)
				return false;
	for (int row = 0; row < top.size(); ++row)
		for (int cell = 0; cell < left.size(); ++cell)
			if (left[row][cell] > cell)
				return false;

	return true;
}