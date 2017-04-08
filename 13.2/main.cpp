//Степаненко С.С., ПС-22, Задача 13.2
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "StringTransformFunctions.h"

using namespace std;

map<size_t, vector<size_t>> KMP_search(istream& input, string searchString)
{
	map<size_t, vector<size_t>> allPositions;
	vector<pair<size_t, size_t>> linesLenghts;
	searchString = ToLower(searchString);

	vector<size_t> prefixFunction(searchString.length());
	prefixFunction[0] = 0;
	for (size_t k = 0, readPos = 1; readPos < searchString.length(); ++readPos) {
		while (k > 0 && searchString[readPos] != searchString[k])
			k = prefixFunction[k - 1];

		if (searchString[readPos] == searchString[k])
			k++;

		prefixFunction[readPos] = k;
	}
	bool isNewLine = false;
	for (size_t k = 0, column = 0, line = 0; !input.eof(); ++column)
	{
		char current;
		input.get(current);
		current = ToLower(current);

		if (isNewLine)
		{
			linesLenghts.push_back(make_pair(line, column));
			line++;
			column = 0;
			isNewLine = false;
		}
		if (current == '\n')
		{
			isNewLine = true;
			current = ' ';
		}
			
		while ((k > 0) && (searchString[k] != current))
			k = prefixFunction[k - 1];

		if (searchString[k] == current)
			k++;
			

		if (k == searchString.length())
		{
			size_t foundPos = column;
			int foundLineIndex = line;
			if (foundPos < searchString.length())
			{
				do
				{
					foundLineIndex--;
					foundPos += linesLenghts[foundLineIndex].second;
				} 
				while (foundPos < searchString.length());
			}
				
					
			foundPos -= searchString.length() - 1;
			if (allPositions.find(foundLineIndex + 1) != allPositions.end())
				allPositions.at(foundLineIndex + 1).push_back(foundPos + 1);
			else
				allPositions.emplace(foundLineIndex + 1, vector<size_t>{ foundPos + 1 });
		}
			
	}

	return allPositions;
}

int main()
{
	ifstream input("input.txt");
	string searchString;
	string targetFilePath;
	getline(input, searchString);
	getline(input, targetFilePath);
	ifstream targetFile(targetFilePath);
	auto allPositions = KMP_search(targetFile, searchString);
	
	ofstream output("output.txt");

	if (!allPositions.empty())
		for (auto& line : allPositions)
		{
			for (auto& column : line.second)
				output << line.first << " " << column << " ";
			output << endl;
		}
	else
		output << "No";

	return 0;
}

