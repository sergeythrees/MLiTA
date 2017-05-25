//Степаненко С. ПС-22, МЛиТА, задание 16.4

#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;

void HandleCommand(vector<int>& tree, vector<int>& inputArray, ostream& output, const string& commandLine)

{
	stringstream strm(commandLine);
	string command;
	strm >> command;
	if (command == "1")
	{
		int first;
		int last;
		int valueForAdd;
		function<int(int)> func = [&] (int value)
			{value += valueForAdd;
			return (value < 0) ? 0 : value; };

		if (strm >> first >> last >> valueForAdd)
		{
			for (int i = first - 1; i < last; i++)
				Update(tree, 1, 0, inputArray.size() - 1, i, func);
		}
		else
			throw invalid_argument("Invalid values");
	}
	else if (command == "2")
	{
		int first;
		int last;
		if (strm >> first >> last)
		{
			output
				<< Sum(tree, first - 1, last - 2, 1, 0, inputArray.size() - 1)
				<< endl;
		}
		else
			throw invalid_argument("Invalid values");

	}
	else
		throw invalid_argument("Unknown command");
}
int main()
{
	ifstream input("input.txt");
	int energyPostCount = 0;
	input >> energyPostCount;
	getline(input, string());
	vector<int> inputArray(energyPostCount, 0);
	std::vector<int> tree(energyPostCount * 4);
	BuildTree(tree, inputArray, 1, 0, energyPostCount - 1);

	string commandLine;
	ofstream output("output.txt");
	while (getline(input, commandLine))
	{
		try
		{
			HandleCommand(tree, inputArray, output, commandLine);
		}
		catch (const exception& ex)
		{
			cerr << ex.what() << endl;
			return EXIT_FAILURE;
		}
		
	}

	return 0;
}