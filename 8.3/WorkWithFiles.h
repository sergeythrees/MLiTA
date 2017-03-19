#pragma once
#include <fstream>
#include <string>
#include <sstream>

template <typename T>
void FillMatrix(std::istream &input, std::vector<std::vector<T>>& matrix, bool isSquare = false)
{
		std::string line;
		std::vector<T> row;
		
		if (isSquare)
		{
			getline(input, line);
			std::vector<T> temp;
			ReadArrayFromLine(line, row);	
			matrix.push_back(row);
			size_t sizeOfMatrix = row.size();
			for (size_t numberOfRow = 1; numberOfRow < sizeOfMatrix; ++numberOfRow)
			{
				row.clear();
				getline(input, line);
				ReadArrayFromLine(line, row);
				matrix.push_back(row);
			}
		}	
		else
		{
			while (getline(input, line))
			{
				ReadArrayFromLine(line, row);
				matrix.push_back(row);
			}
		}
}

template <typename T>
void ReadArrayFromLine(std::string &line, std::vector<T>& array)
{
	std::stringstream stream;
	stream << line;
	T element;
	while (stream >> element)
	{
		array.push_back(element);
	}
}

template <typename T>
void PrintMatrix(const std::vector<std::vector<T>>& matrix, std::ostream& output = std::cout)
{
	for (auto row : matrix)
	{
		for (auto cell : row)
			output << cell << " ";
		output << endl;
	}
}


template <typename T>
void PrintVector(const std::vector<T>& vector, std::ostream& output = std::cout)
{
	for (auto element : vector)
		output << element << " ";
}