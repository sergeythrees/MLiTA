#pragma once
#include <vector>
#include <algorithm>
#include <functional>

void BuildTree(std::vector<int> &tree, std::vector<int> arr, int i, int leftLimit, int rightLimit)
{
	if (leftLimit == rightLimit)
		tree[i] = arr[leftLimit];
	else
	{
		int half = (leftLimit + rightLimit) / 2;
		BuildTree(tree, arr, i * 2, leftLimit, half);
		BuildTree(tree, arr, i * 2 + 1, half + 1, rightLimit);
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

int Sum(const std::vector<int> &tree, int begin, int end, int i, int leftLimit, int rightLimit)
{
	if (begin > end)
		return 0;
	if (begin == leftLimit && end == rightLimit)
		return tree[i];

	int half = (leftLimit + rightLimit) / 2;

	return Sum(tree, begin, std::min(end, half), i * 2, leftLimit, half) 
		+ Sum(tree, std::max(begin, half + 1), end, i * 2 + 1, half + 1, rightLimit);
}

void Update(std::vector<int> &tree, int i, int leftLimit, int rightLimit, int pos, std::function<int(int)>& updateValue)
{
	if (leftLimit == rightLimit)
		tree[i] = updateValue(tree[i]);
	else
	{
		int half = (leftLimit + rightLimit) / 2;
		if (pos <= half)
			Update(tree, i * 2, leftLimit, half, pos, updateValue);
		else
			Update(tree, i * 2 + 1, half + 1, rightLimit, pos, updateValue);

		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}