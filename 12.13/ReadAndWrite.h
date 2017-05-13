#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

struct Vertice
{
	Vertice(size_t verticeKey)
		: key(verticeKey)
	{
	}

	size_t key;
	std::map<Vertice*, size_t> adjacentVertices;
};

typedef std::map<size_t, Vertice*> VertexMap;


VertexMap ReadGraph(std::istream &input, unsigned vertexCount)
{
	VertexMap vertexMap;
	
	for (;vertexCount > 0; vertexCount--)
		vertexMap.emplace(vertexCount, Vertice(vertexCount));


	std::string line;
	size_t firstKey;
	size_t secondKey;
	size_t weight;

	while (getline(input, line))
	{
		std::stringstream strm(line);
		strm >> firstKey;
		strm >> secondKey;
		strm >> weight;

		auto vertexA = vertexMap.find(firstKey)->second;
		auto zz = vertexMap.find(secondKey)->second;

		firstNode->neighbourhoods.insert(std::make_pair(secondNode, weight));
		secondNode->neighbourhoods.insert(std::make_pair(firstNode, weight));
	}
}
