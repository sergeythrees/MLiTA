//Степаненко С. ПС-22
#include "stdafx.h"
#include "ReadWriteFunctions.h"

using namespace std;

vector<int> GenerateNextPermutation(const vector<int>&currentPerm)
{
	vector<int> per(currentPerm);

	size_t currentPos = per.size() - 1;
	while (!(per[currentPos] > per[currentPos - 1]))
		currentPos--;

	size_t beginPos = currentPos - 1;
	int startDigit = per[beginPos];
	int toSwap = INT_MAX;
	size_t toSwapPos = currentPos;

	for (size_t k = currentPos; k < per.size(); k++)
	{
		if (per[k] > startDigit)
		{
			if (toSwap > per[k])
			{
				toSwap = per[k];
				toSwapPos = k;
			}
		}
	}

	if (toSwap != INT_MAX)
	{
		swap(per[toSwapPos], per[beginPos]);

		vector<int> invertVect(per.begin() + currentPos, per.end());

		int pos = 0;
		for (size_t k = per.size() - 1; k >= currentPos; k--, pos++)
		{
			per[k] = invertVect[pos];
		}
	}
	return per;
}

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	int numbersCount;
	int perCount;
	vector<vector<int>> per;
	per.assign(1, vector<int>());

	input >> numbersCount;
	input >> perCount;
	getline(input, string());
	ReadLineFromFileToVector(input, per[0]);

	for (int i = 1; i < perCount; ++i)
	{
		per.push_back(GenerateNextPermutation(per[i - 1]));
		PrintVectorToStream(per[i]);
	}
		
    return 0;
}

