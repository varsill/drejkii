#include "OpenFiles.h"

Tree getCities(std::string path, size_t& howManyCities)
{
	Tree tree;
	tree.root = nullptr;
	howManyCities = 0;
	std::fstream file;
	std::string a, b;
	int c;
	file.open(path);
	while (!file.eof())
	{
		file >> a >> b >> c;
		if (find(tree, a) == -1)
		{
			insert(tree, a, howManyCities);
			howManyCities++;
		}
		if (find(tree, b) == -1)
		{
			insert(tree, b, howManyCities);
			howManyCities++;
		}
	}
	file.close();
	return tree;
}

Graph readGraphFromFile(std::string path, Tree dictionary)
{
	
	size_t howManyCities = 0;
	Tree citiesDictionaryTree = getCities(path, howManyCities);
	Graph graph = createGraph(howManyCities, path, dictionary);
	std::fstream file;
	std::string a, b;
	int distance;
	file.open(path);
	while (!file.eof())
	{
		file >> a >> b >> distance;
		size_t cityAIndex = find(citiesDictionaryTree, a);
		size_t cityBIndex = find(citiesDictionaryTree, b);
		Edge edge{cityAIndex, cityBIndex, distance };
		
		addEdge(graph, edge);
	}
	file.close();
	return graph;

}
