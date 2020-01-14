#include "OpenFiles.h"
#include <iostream>

#define NOT_SET "NOT SET"

int main(int argc, char** argv)
{
	std::string roadsFilePath = NOT_SET;
	std::string routesToFindFilePath = NOT_SET;
	std::string outputFilePath = NOT_SET;
	//argument zerowy to nazwa programu, wiec lecimy z indeksami w tablicy argumentow od 1
	if (argc % 2 != 1)
	{
		std::cerr << "Wrong number of arguments";
		return 1; //error
	}
	for (int i = 1; i < argc; i=i+2)
	{
		std::string argType(argv[i]);
		if (argType == "-d" && roadsFilePath == NOT_SET)
		{
			roadsFilePath = argv[i + 1];
		}
		else if (argType == "-t" && routesToFindFilePath == NOT_SET)
		{
			routesToFindFilePath = argv[i + 1];
		}
		else if (argType == "-o" && outputFilePath==NOT_SET)
		{
			outputFilePath = argv[i + 1];
		}
		else
		{
			std::cerr << "Wrong arguments";
			return 1; //error
		}
	}


	size_t howManyCities;
	Tree dictionary = getCities(roadsFilePath, howManyCities);
	Graph graph = readGraphFromFile(roadsFilePath, dictionary);

	std::fstream routesToFind;
	routesToFind.open(routesToFindFilePath);
	std::fstream output;
	output.open(outputFilePath, std::ios::app); 
	std::string cityA, cityB;
	
	std::string * arrayToReverse = new std::string[100];
	while (!routesToFind.eof())
	{
		routesToFind >> cityA >> cityB;
		dijkstra(graph, find(dictionary, cityA));
		std::cout << "trasa: " << cityA << " --> " << cityB;
		if (graph.vertices[find(dictionary, cityB)].distance != INF)
		{
			std::cout << " (" << graph.vertices[find(dictionary, cityB)].distance << " km)" << std::endl;
			int city = find(dictionary, cityB);
			int next_city = graph.vertices[city].parent_index;
			//reverse route
			int numberOfCities = 0;
			while (next_city != -1)
			{
				arrayToReverse[numberOfCities] = graph.vertices[next_city].name + " --> " + graph.vertices[city].name + "   " + std::to_string((int)graph.vertices[city].distance_to_parent);
				city = next_city;
				next_city = graph.vertices[next_city].parent_index;
				numberOfCities++;
			}


			for (int i = numberOfCities-1; i >= 0; i--)
			{
				std::cout << arrayToReverse[i] << std::endl;
			}
		}
		else
		{
			std::cout << std::endl << "TRASA NIEMO¯LIWA DO WYZNACZENIA";
		}
		std::cout << std::endl;

	}
	routesToFind.close();
	output.close();

	
	return 0;

}