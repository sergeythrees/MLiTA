//Степаненко С. ПС-22

//4.6.Золотоискатели(6)
//За два года беспрерывной работы артель золотоискателей &quot; Вперед к капитализму!&quot; , состоящая
//из трех человек, добыла N самородков.Несмотря на то, что до конца вахты оставался еще целый
//год, один из золотоискателей решил уехать - на Большой Земле у него родился сын.Артельщики
//решили выдать отъезжающему ровно третью часть добытого золота.
//Вам надо написать программу, которая находит набор самородков, вес которого составляет
//третью часть от веса всего добытого золота, либо определить что это невозможно.
//Ввод из файла INPUT.TXT.В первой строке записано целое число N - количество добытых
//самородков(1 ? N ? 500).Во второй строке заданы через пробел N целых чисел M i(1 ? M i ? 1000)
//- веса добытых самородков.
//Вывод в файл OUTPUT.TXT.Если набор составить возможно, то в первой строке выведите K -
//количество самородков в наборе, а затем K чисел, задающих номера самородков, входящих в
//набор.Если существует несколько ответов, то выведите любой из них.Если набор составить
//невозможно, то выведите число 0.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "WorkWithFiles.h"

using namespace std;
vector<int> CalculateStonesSet(const vector<int>& weights, int P);

int main()
{
	int weightSum = 0;
	vector<int> weights;
	ReadArray("input.txt", weights, weightSum);

	vector<int> stonesSet;
	if (weightSum % 3 == 0)
		stonesSet = CalculateStonesSet(weights, weightSum / 3);

	PrintResult("output.txt", stonesSet);

    return 0;
}

vector<int> CalculateStonesSet(const vector<int>& weights, int P)
{
	vector<int> stonesSet;
	stonesSet.assign(P + 1, -1);
	stonesSet[0] = 0;

	for (int i = 0; i < weights.size(); i++)
	{
		for (int k = P; k > 0; k--)
		{
			if (k - weights[i] >= 0)
			{
				if (stonesSet[k - weights[i]] != -1)
				{
					stonesSet[k] = i + 1;
					break;
				}
			}
		}
		if (stonesSet[P] != -1)
		{
			break;
		}
	}

	vector<int> result;
	if (stonesSet[P] > 0)
	{
		for (int k = P; k > 0;)
		{
			result.push_back(stonesSet[k]);
			k = k - weights[stonesSet[k] - 1];
		}
	}

	return result;
}