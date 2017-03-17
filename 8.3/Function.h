#pragma once
#include "stdafx.h"

template <typename T>
void CalculateMatrix(std::vector<std::vector<T>>& top,
	std::vector<std::vector<T>>& left,
	std::vector<std::vector<T>>& result)
{
	std::vector<std::vector<T>> leftAndTop;
	size_t matrixSize = top.size();
	leftAndTop.assign(top.size(), vector<T>(top[0].size(), 0));
	for (size_t i = 0; i < top.size(); ++i)
		for (size_t j = 0; j < top[0].size(); ++j)
			leftAndTop[i][j] = left[i][j] + top[i][j];

	std::vector<std::vector<bool>> leftAndTopFreeCells;

	for (size_t i = 0; i < matrixSize * matrixSize; ++i)
	{

	}
	result = leftAndTop;
}