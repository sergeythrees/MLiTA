//Степаненко С. ПС-22, МЛиТА, задание 16.4

#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void HandleCommand(Tree& tree, int arraySize, ostream& output, const string& commandLine)

{
	stringstream strm(commandLine);
	string command;
	strm >> command;
	if (command == "1")
	{
		int first;
		int last;
		int valueForAdd;

		if (strm >> first >> last >> valueForAdd)
		{
			tree.Update(1, first - 1, last -  2, 0, arraySize - 1, valueForAdd);
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
				<< tree.Sum(1, first - 1, last - 2, 0, arraySize - 1)
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
	Tree tree(vector<int>(energyPostCount, 0));

	string commandLine;
	ofstream output("output.txt");
	
	try
	{
		while (getline(input, commandLine))
			HandleCommand(tree, energyPostCount, output, commandLine);
	}
	catch (const exception& ex)
	{
		cerr << ex.what() << endl;
		return EXIT_FAILURE;
	}

	return 0;
}