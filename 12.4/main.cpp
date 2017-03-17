//Степаненко С.С., ПС-22, Задача 12.4
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string::size_type KMP_search(const string& inputLine, size_t begin, const string& searchString) 
{
	vector<size_t> prefixFunction(searchString.length());

	prefixFunction[0] = 0;
	for (size_t k = 0, readPos = 1; readPos < searchString.length(); ++readPos) {
		while (k > 0 && searchString[readPos] != searchString[k])
			k = prefixFunction[k - 1];

		if (searchString[readPos] == searchString[k])
			k++;

		prefixFunction[readPos] = k;
	}

	for (size_t k = 0, readPos = begin; readPos < inputLine.length(); ++readPos) {
		while ((k > 0) && (searchString[k] != inputLine[readPos]))
			k = prefixFunction[k - 1];

		if (searchString[k] == inputLine[readPos])
			k++;

		if (k == searchString.length())
			return (readPos - searchString.length() + 1);
	}

	return (string::npos);
}

vector<size_t>  FindAllPositions(string &inputLine, const string &searchString)
{

	size_t foundPosition = 0;
	size_t currentPosition = 0;
	vector<size_t> positions;

	while ((foundPosition = KMP_search(inputLine, currentPosition, searchString)) != string::npos)
	{
		currentPosition = foundPosition + 1;
		positions.push_back(currentPosition);
	}
	return positions;
}

template <typename T>
string VectorToString(const vector<T>&array)
{
	stringstream result;
	for (auto elem : array)
		result << elem << " ";
	return result.str();
}

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	unordered_map<string, vector<size_t>> wordsPositions;
	string text;

	size_t wordsCount;
	input >> wordsCount;
	getline(input, string());

	string word;
	for (size_t i = 0; i < wordsCount; ++i)
	{
		getline(input, word);
		wordsPositions.emplace(word, vector<size_t>());
	}
	getline(input, text);

	for (auto& currentWord : wordsPositions)
	{
		currentWord.second = FindAllPositions(text, currentWord.first);
		output << currentWord.first << " "
			<< (currentWord.second.size() > 0 ? 
				VectorToString(currentWord.second) : "No");
		output << endl;
	}

	return 0;
}

