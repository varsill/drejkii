/** @file */
#pragma once
#include "Tree.h"
#include "Graph.h"
#include <fstream>
#include <string>

/** Funkcja pobiera miasta z pliku
@param path przekazuje œcie¿ke do pliku
@param howManyCities zlicza ilosc wyst¹pieñ unikalnych miast w pliku
@return funkcja zwraca drzewo miast*/
Tree getCities(std::string path, size_t& howManyCities);
/** Funkcja tworzy graf z odczytanego pliku
@param path przekazuje œcie¿ke do pliku
@return funkcja zwraca graf utworzony z miast i odleg³oœci miêdzy tymi miastami*/
Graph readGraphFromFile(std::string path);


