#pragma once
#include "stdafx.h"
#include <iterator>

template <typename T>
void ReadLineFromFileToVector(std::ifstream & file, std::vector<T> & vect)
{
	std::stringstream stream;
	std::string line;
	getline(file, line);
	stream << line;
	T elem;
	while (stream >> elem)
	{
		vect.push_back(elem);
	}
}

template <typename T>
void PrintVectorToStream(const std::vector<T>& vect, std::ostream& strm = std::cout)
{
	std::copy(vect.begin(), vect.end(), std::ostream_iterator<T>(strm, " "));
	strm << std::endl;
}

