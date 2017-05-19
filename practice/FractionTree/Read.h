#pragma once
#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <locale>

std::vector<int> FillVectorFromFIle(const std::string& filePath)
{
	std::vector<int> result;
	std::ifstream file(filePath);
	std::string fileLine;
	getline(file, fileLine);

	int number;
	while (file >> number)
	{
		result.push_back(number);
	}

	return result;
}