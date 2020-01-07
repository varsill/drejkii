#include "OpenFiles.h"
#include <iostream>


int main()
{
	
	size_t howManyCities;
	Tree dictionary = getCities("drogi.txt", howManyCities);
	Graph graph = readGraphFromFile("drogi.txt");

	std::fstream file;
	std::string cityA, cityB;
	file.open("Trasy.txt");
	while (!file.eof()) 
	{
		file >> cityA >> cityB;
		dijkstra(graph, find(dictionary, cityA));
		std::cout << graph.vertices[find(dictionary, cityB)].distance << std::endl;
	}
	file.close();
	
	/*dijkstra(graph, find(dictionary, "Gliwice"));
	std::cout << graph.vertices[find(dictionary, cityB)].distance << std::endl;*/
	
	return 0;

}