//Степаненко С. ПС-22

#include "stdafx.h"
#include "WorkWithFiles.h"
#include "Function.h"
#include <math.h>

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
		GenerateMatrix(result, top, left, 9))
	{
		PrintMatrix(result, output);
		PrintMatrix(result, cout);
	}
	else
	{
		output << "0" << endl; 
		cout << "0" << endl;
	}

    return 0;
}