#pragma once
#include "Tree.h"
#include "Graph.h"
#include <fstream>
#include <string>

Tree getCities(std::string path, size_t& howManyCities);
Graph readGraphFromFile(std::string path);


