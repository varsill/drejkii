#include "OpenFiles.h"
#include <iostream>

int main()
{
	
	size_t howManyCities;
	Tree dictionary = getCities("drogi.txt", howManyCities);
	Graph graph = readGraphFromFile("drogi.txt");
	
	dijkstra(graph, find(dictionary, "Gliwice"));
	std::cout << graph.vertices[find(dictionary, "Poznan")].distance;
	
	return 0;

}