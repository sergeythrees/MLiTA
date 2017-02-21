//Степаненко С. ПС-22

//Имеется N камней.Требуется набрать заданный вес.
//Ввод из файла "INPUT.TXT" .В первой строке записаны через пробел целое
//число N - количество камней(1 <= N <= 500) и вес P(1 <= P <= 50000).Во второй
//строке находятся N целых чисел Mi(1 <= Mi <= 100) - веса камней.
//Вывод в файл OUTPUT.TXT.Если набор составить возможно, то в первой
//строке выведите K - количество камней в наборе, а во второй строке в
//порядке возрастания K номеров камней, входящих в набор.Если существует
//несколько ответов, то выведите любой из них.Если набор составить
//невозможно, то выведите число 0.
//Примеры
//Ввод 1             Ввод 2
//8 6                3 4
//1 3 4 1 2 5 1 1    1 5 6
//Вывод 1            Вывод 2
//2                  0
//6 8

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "WorkWithFiles.h"

using namespace std;

int main()
{
	int N = 0; int P = 0;
	vector<int> weights;
	ReadArray("input.txt", weights, N, P);


	vector<int> stonesNumbers;
	stonesNumbers.assign(P+1, -1);
	stonesNumbers[0] = 0;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		for (int k = P; k > 0; k--)
		{
			if (k - weights[i] >= 0)
			{
				if (stonesNumbers[k - weights[i]] != -1)
				{
					stonesNumbers[k] = i + 1;
					count++;
					break;
				}
			}	
		}
		if (stonesNumbers[P] != -1)
		{
			break;
		}
	}

	vector<int> result;
	if (stonesNumbers[P] > 0)
	{
		for (int k = P; k > 0;)
		{
			result.push_back(stonesNumbers[k]);
			k = k - weights[stonesNumbers[k] - 1];
		}
	}
	else
	{
		count = 0;
	}
	
	PrintResult("output.txt", result, count);

    return 0;
}

