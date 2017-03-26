#include "stdafx.h"
#include <map>
#include <iostream>
#include "StringTransformFunctions.h"

using namespace std;

namespace
{
	static const map<char, char> toLowerRussianLettersMap({ 
		{ 'À', 'à' },{ 'Á', 'á' },{ 'Â', 'â' },{ 'Ã', 'ã' },{ 'Ä', 'ä' },
		{ 'Å', 'å' },{ '¨', '¸' },{ 'Æ', 'æ' },{ 'Ç', 'ç' },{ 'È', 'è' },
		{ 'É', 'é' },{ 'Ê', 'ê' },{ 'Ë', 'ë' },{ 'Ì', 'ì' },{ 'Í', 'í' },
		{ 'Î', 'î' },{ 'Ï', 'ï' },{ 'Ð', 'ð' },{ 'Ñ', 'ñ' },{ 'Ò', 'ò' },
		{ 'Ó', 'ó' },{ 'Ô', 'ô' },{ 'Õ', 'õ' },{ 'Ö', 'ö' },{ '×', '÷' },
		{ 'Ø', 'ø' },{ 'Ù', 'ù' },{ 'Ú', 'ú' },{ 'Û', 'û' },{ 'Ü', 'ü' },
		{ 'Ý', 'ý' },{ 'Þ', 'þ' },{ 'ß', 'ÿ' }
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