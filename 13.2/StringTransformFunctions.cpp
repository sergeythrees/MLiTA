#include "stdafx.h"
#include <map>
#include <iostream>
#include "StringTransformFunctions.h"

using namespace std;

namespace
{
	static const map<char, char> toLowerRussianLettersMap({ 
		{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },
		{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },
		{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },
		{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },
		{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },
		{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },{ '�', '�' },
		{ '�', '�' },{ '�', '�' },{ '�', '�' }
	});
}

string ToLower(const string &line)
{
	string result;
	for (auto symbol : line)
	{
		result += ToLower(symbol);
	}
	return result;
}

char ToLower(char symbol)
{
	if (toLowerRussianLettersMap.count(symbol) > 0)
		return toLowerRussianLettersMap.at(symbol);
	else
		return tolower(symbol);
}