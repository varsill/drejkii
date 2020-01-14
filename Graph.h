/** @file */
#pragma once
#include <string>
#include "Tree.h"
#include <fstream>
#define MAX_N 64
#define INF 99999999

/** Struktura kraw�dzi przechowuj�ca parametry od i do oraz wag� kraw�dzi*/
struct Edge
{
	size_t from;		///< odleg�o�� od wierzcho�ka
	size_t to;			///< odleg�o�� do wierzcho�ka
	int weight;			///< waga kraw�dzi
};

/** Struktura w�z�a listy*/
struct LinkedListNode
{
	LinkedListNode* next = nullptr;	///< ustawienie wska�nika nast�pnego w�z�a listy na null
	Edge value;						///< warto�� danego elementu listy
};
/** Struktura listy*/
struct LinkedList
{
	LinkedListNode* head;		///< wska�nik na pierwszy w�ze� listy, tzw. g�ow�
};


/** Struktura wierzcho�ka*/
struct Vertex
{
	size_t index;			///< indeks wierzcho�ka
	std::string name; 
	unsigned int distance;	///< odleg�o�� do nast�pnego wierzcho�ka
	int parent_index;		///< indeks swojego "ojca"
	float distance_to_parent;///< odleglosc do ojca 
	LinkedList edges_list{nullptr};	///< lista kraw�dzi
};
/** Struktura Grafu*/ 
struct Graph
{
	Vertex vertices[MAX_N]; ///<tablica wierzcho�k�w(?)
	size_t vertices_number; ///<liczba wierzcho�k�w
};


/** Funkcja dodaj�ca kraw�dz do grafu
@param graph przekazuje strukture grafu do funkcji
@param e przekazuje strukture kraw�dzi do funkcji*/
void addEdge(Graph& graph, Edge e);
/** Funkcja tworz�ca struktur� grafu
@param how_many_vertices przekazuje liczbe wierzcho�k�w do utworzenia w grafie
@return zwraca wska�nik na pierwszy element grafu*/
Graph createGraph(size_t how_many_vertices, std::string path_to_cities_file, Tree dictionary);
/** Funkcja- algorytm Dijkstry, liczy najkr�tsz� tras� mi�dzy dwoma miastami
@param graph przekazuje struktur� grafu do funkcji
@param beginning_vertex_index przekazuje indeks pierwszego wierzcho�ka grafu*/
void dijkstra(Graph& graph, size_t beginning_vertex_index);
/** Funkcja dodaj�ca w�ze� do listy
@param list przekazuje liste do funkcji
@param edge kraw�d� grafu */
void add(LinkedList& list, Edge edge);
/** Funkcja szukaj�ca podan� warto�� listy i zwracaj�ca wska�nik na ten element listy
@param list przekazuje liste do funkcji
@param edge przekazuje do funkcji warto�� elementu listy, kt�rego wska�nik jest szukany
@return zwraca wska�nik na szukany element listy*/
LinkedListNode* find(LinkedList& list, Edge edge);
/** Funkcja usuwa dany element listy
@param list przekazuje liste do funkcji
@param edge przekazuje do funkcji warto�� elementu listy, kt�ry bedzie u�ywany w funkcji find */
void remove(LinkedList& list, Edge edge);
/** Funkcja zawracaj�ca wska�nik LinkedListNode'a na poprzedni element listy
@param list przekazuje liste do funkcji
@param actual wskazuje na obecny w�ze� listy
@return zwraca wska�nik na poprzedni element listy*/
LinkedListNode* previous(LinkedList& list, LinkedListNode* actual);



