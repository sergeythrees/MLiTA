#pragma once
#include <fstream>
#include <string>
#include <vector>
void ReadArray(const std::string &fileName, std::vector<int>& weights, int& weightSum)
{
	int weightSumTemp = 0;
	std::ifstream file(fileName);
	if (file.is_open())
	{
		file >> std::string();
		int temp;
		while (file >> temp)
		{
			weightSumTemp += temp;
			weights.push_back(temp);
		}
		weightSum = weightSumTemp;
	}
}
void PrintResult(const std::string &fileName, std::vector<int>& stonesSet)
{
	std::ofstream file(fileName);
	if (file.is_open())
	{
		file << stonesSet.size() << std::endl;
		for (auto current : stonesSet)
		{
			file << current << " ";
		}
	}
}