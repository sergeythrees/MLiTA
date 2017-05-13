#include "stdafx.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<unsigned, unsigned> Point;

int main()
{
	ifstream input("input1.txt");
	size_t startPositionsCount;
	input >> startPositionsCount;
	vector<Point> startPositions;
	for (size_t i = 0; i < startPositionsCount; ++i)
	{
		startPositions.push_back({});
		input >> startPositions[i].first;
		input >> startPositions[i].second;
	}

	size_t distanceToFinish;
	for (auto startPosition : startPositions)
	{
		size_t lessCoord = startPosition.first;
		size_t biggerCoord = startPosition.second;
		if (startPosition.first > startPosition.second)
			swap(lessCoord, biggerCoord);

		distanceToFinish = biggerCoord - 1;
			
		if (distanceToFinish % 2 != 0 || lessCoord % 2 ==0)
			cout << "1";
		else
			cout << "2";
		cout << endl;
	}
    return 0;
}

