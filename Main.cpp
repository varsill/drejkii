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
	Graph graph = readGraphFromFile(roadsFilePath);

	std::fstream routesToFind;
	routesToFind.open(routesToFindFilePath);
	std::fstream output;
	output.open(outputFilePath, std::ios::app); 
	std::string cityA, cityB;
	

	while (!routesToFind.eof())
	{
		routesToFind >> cityA >> cityB;
		dijkstra(graph, find(dictionary, cityA));
		output << graph.vertices[find(dictionary, cityB)].distance << std::endl;
	}
	routesToFind.close();
	output.close();

	
	return 0;

}