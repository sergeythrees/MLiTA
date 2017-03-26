//Степаненко С. ПС-22
#include "stdafx.h"
#include <stack>
#include <string>
#include <fstream>
#include<stdlib.h>

using namespace std;
void Invert(char& sign);
void Invert(bool& b);
stack<size_t> GenerateStack(const string& code);

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	std::string code;
	input >> code;
	size_t size = code.length();

	stack<size_t> stack(GenerateStack(code));


	bool isOdd = true;
	size_t index;
	for (size_t i = 0; i <= 15; i++)
	{ 
		output << code << endl;
		if (isOdd)
		{	
			index = size - 1;
			if (code[index] == '1')
				stack.pop();
			else
				stack.push(index);
		}
		else
		{
			if (stack.empty() || stack.top() == 0)
			{
				index = 0;
				if (code[index] == '0')
					stack.push(index);
			}
			else
			{
				index = stack.top() - 1;
				size_t temp = stack.top();
				if (code[index] == '1')
				{
					stack.pop();
					stack.top() = temp;
				}
				else
				{
					stack.top() = index;
					stack.push(temp);
				}
			}
		}
		Invert(code[index]);
		Invert(isOdd);
	}

	return 0;
}

void Invert(char& sign)
{
	if (sign == '0')
	{
		sign =  '1';
	}
	else
		sign = '0';
}

void Invert(bool& b)
{
	if (b == true)
	{
		b = false;
	}
	else
		b = true;
}

stack<size_t> GenerateStack(const string& code)
{
	stack<size_t> stack;
	for (size_t i = 0; i < code.size(); i++)
	{
		if (code[i] == '1')
		{
			stack.push(i);
		}
	}

	return stack;
}