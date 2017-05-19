//Степаненко С. ПС-22
#include "stdafx.h"
#include "Read.h"
#include "Tree.h"
#include <iostream>
#include <iterator>
#include <map>

using namespace std;

void HandleCommand(vector<int>& tree, vector<int>& inputArray, const string& commandLine)
{
	stringstream strm(commandLine);
	string command;
	strm >> command;
	if (command == "add")
	{
		int index;
		int valueForAdd;
		function<int(int)> func = [&]
			(int value) { return value + valueForAdd; };
		if (strm >> index >> valueForAdd)
			Update(tree, 1, 0, inputArray.size() - 1, index, func);
		else
			cout << "Invalid values";
	}
	else if (command == "sum")
	{
		int first;
		int last;
		if (strm >> first >> last)
		{
			cout << "Sum of elements between " 
				<< first << " and " << last << " = "
				<< Sum(tree, first, last, 1, 0, inputArray.size() - 1);
		}
		else
			cout << "Invalid values";
	 
	}
	else if (command == "print")
	{
		copy(tree.begin(), tree.end(), ostream_iterator<int>(cout, " "));
	}
	else
	{
		cout << "Unknown command";
	}
}
int main()
{
	vector<int> inputArray = FillVectorFromFIle("input.txt");
	std::vector<int> tree(inputArray.size() * 4);
	BuildTree(tree, inputArray, 1, 0, inputArray.size() - 1);

	cout << "Commands:" << endl
		<< "sum [firstElement] [lastElement]" << endl
		<< "add [index] [valueForAdd]" << endl
		<< "print" << endl
		<< "Ctrl + Z for exit" << endl;
	string commandLine;
	
	while (getline(cin, commandLine))
	{
		HandleCommand(tree, inputArray, commandLine);
		cout << endl;
	}

	return 0;
}