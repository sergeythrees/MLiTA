//Степаненко С. ПС-22
#include "stdafx.h"
#include <set>
#include <map>

using namespace std;
typedef map<int, set<int>> Vertices;

Vertices ReadVertices(istream &input)
{
	Vertices vertices;

	string line;
	getline(input, line);

	for (int i = 0; getline(input, line); ++i)
	{
		stringstream strm(line);
		strm.get();

		int vertice;
		set<int> toVisit;
		while (strm >> vertice)
			toVisit.emplace(vertice);

		vertices.emplace( i + 1, toVisit);
	}
	return vertices;
}

auto FindNodeWithEmptyVisitList(Vertices &vertices)
{
	for (auto it = vertices.begin(); it != vertices.end(); ++it)
		if (it->second.size() == 0)
			return it;

	return vertices.end();
}

int main()
{
	ifstream input("input.txt");
	Vertices vertices(ReadVertices(input));

	int visited = 0;
	vector<int> visitOrder;
	size_t vertexCount = vertices.size();

	auto free = vertices.end();
	while ((free = FindNodeWithEmptyVisitList(vertices) )!= vertices.end()
		&& visitOrder.size() <= vertexCount)
	{
		for (auto& vertice : vertices)
			(vertice.second).erase((*free).first);

		visitOrder.push_back((*free).first);
		vertices.erase(free);
	}

	ofstream out("output.txt");
	if (visitOrder.size() == vertexCount)
	{
		out << "YES" << endl;
		for (auto vert : visitOrder)
			out << vert << endl;
	}
	else
		out << "NO" << endl;
	return 0;
}