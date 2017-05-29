#pragma once
#include <vector>
#include <algorithm>

class Tree
{
public:

	Tree(const std::vector<int>& arr)
		:m_tree(std::vector<int>(arr.size() * 4, 0)),
		m_treeDiffs(m_tree)
	{
		BuildTree(arr, 1, 0, arr.size() - 1);
	}

	int Sum(int i, int begin, int end, int leftLimit, int rightLimit)
	{
		if (begin > end) 
			return 0;
		if (begin == leftLimit && end == rightLimit) 
			return m_tree[i];

		int half = (leftLimit + rightLimit) / 2;
		int diff = m_treeDiffs[i] * (end - begin + 1);
		return Sum(i * 2, begin, std::min(end, half), leftLimit, half) +
			Sum(i * 2 + 1, std::max(begin, half + 1), end, half + 1, rightLimit) + diff;
	}

	void Update(int i, int begin, int end, int leftLimit, int rightLimit, int updateValue)
	{
		if (begin > end)
			return;

		m_tree[i] = m_tree[i] + updateValue*(end - begin + 1);

		if (leftLimit == begin && rightLimit == end)
		{
			m_treeDiffs[i] += updateValue;
			return;
		}

		int half = (leftLimit + rightLimit) / 2;
		Update(i * 2, begin, std::min(end, half), leftLimit, half, updateValue);
		Update(i * 2 + 1, std::max(begin, half + 1), end, half + 1, rightLimit, updateValue);
	}

private:
	std::vector<int> m_tree;
	std::vector<int> m_treeDiffs;

	void BuildTree(const std::vector<int>& arr, int i, int leftLimit, int rightLimit)
	{
		if (leftLimit == rightLimit)
			m_tree[i] = arr[leftLimit];
		else
		{
			int half = (leftLimit + rightLimit) / 2;
			BuildTree(arr, i * 2, leftLimit, half);
			BuildTree(arr, i * 2 + 1, half + 1, rightLimit);
			m_tree[i] = m_tree[i * 2] + m_tree[i * 2 + 1];
		}
	}
};


