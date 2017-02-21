//���������� �. ��-22

//4.6.��������������(6)
//�� ��� ���� ������������ ������ ������ ��������������� &quot; ������ � �����������!&quot; , ���������
//�� ���� �������, ������ N ����������.�������� �� ��, ��� �� ����� ����� ��������� ��� �����
//���, ���� �� ��������������� ����� ������ - �� ������� ����� � ���� ������� ���.����������
//������ ������ ������������ ����� ������ ����� �������� ������.
//��� ���� �������� ���������, ������� ������� ����� ����������, ��� �������� ����������
//������ ����� �� ���� ����� �������� ������, ���� ���������� ��� ��� ����������.
//���� �� ����� INPUT.TXT.� ������ ������ �������� ����� ����� N - ���������� �������
//����������(1 ? N ? 500).�� ������ ������ ������ ����� ������ N ����� ����� M i(1 ? M i ? 1000)
//- ���� ������� ����������.
//����� � ���� OUTPUT.TXT.���� ����� ��������� ��������, �� � ������ ������ �������� K -
//���������� ���������� � ������, � ����� K �����, �������� ������ ����������, �������� �
//�����.���� ���������� ��������� �������, �� �������� ����� �� ���.���� ����� ���������
//����������, �� �������� ����� 0.

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