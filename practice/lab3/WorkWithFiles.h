#pragma once
#include <fstream>
#include <string>
#include <vector>
void ReadArray(const std::string &fileName, std::vector<int>& weights, int& N, int& P)
{
	std::ifstream file(fileName);
	if (file.is_open())
	{
		file >> N;
		file >> P;
		while (!file.eof() && !file.fail())
		{
			int temp;
			file >> temp;
			weights.push_back(temp);
		}
	}
}
void PrintResult(const std::string &fileName, std::vector<int>& stonesNumbers, int stonesCount)
{
	std::ofstream file(fileName);
	if (file.is_open())
	{
		file << stonesCount << std::endl;
		for (auto current : stonesNumbers)
		{
			file << current << " ";
		}
	}
}