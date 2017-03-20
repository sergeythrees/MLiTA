//Степаненко С. ПС-22, лаб 8.3

#include "stdafx.h"
#include "ReadAndWrite.h"
#include "GenerateMatrix.h"

using namespace std; 

int main()
{
	vector<vector<int>> top;
	vector<vector<int>> left;
	vector<vector<int>> result;
	ifstream input("input.txt");
	ofstream output("output.txt");

	getline(input, string());
	FillMatrix(input, top, true);
	FillMatrix(input, left, true);
	result.assign(top.size(), std::vector<int>(top.size(), -1));

	if (VerifyTopAndLeftMatrix(top, left) &&
		GenerateMatrix(result, top, left, top.size() * top.size()))
	{
		PrintMatrix(result, output);
	}
	else
	{
		output << "0" << endl; 
	}
	PrintMatrix(result);
    return 0;
}