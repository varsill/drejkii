/** @file */
#pragma once
#include <string>
#include "Tree.h"
#include <fstream>
#define MAX_N 64
#define INF 99999999

/** Struktura krawêdzi przechowuj¹ca parametry od i do oraz wagê krawêdzi*/
struct Edge
{
	size_t from;		///< odleg³oœæ od wierzcho³ka
	size_t to;			///< odleg³oœæ do wierzcho³ka
	int weight;			///< waga krawêdzi
};

/** Struktura wêz³a listy*/
struct LinkedListNode
{
	LinkedListNode* next = nullptr;	///< ustawienie wskaŸnika nastêpnego wêz³a listy na null
	Edge value;						///< wartoœæ danego elementu listy
};
/** Struktura listy*/
struct LinkedList
{
	LinkedListNode* head;		///< wskaŸnik na pierwszy wêze³ listy, tzw. g³owê
};


/** Struktura wierzcho³ka*/
struct Vertex
{
	size_t index;			///< indeks wierzcho³ka
	std::string name; 
	unsigned int distance;	///< odleg³oœæ do nastêpnego wierzcho³ka
	int parent_index;		///< indeks swojego "ojca"
	float distance_to_parent;///< odleglosc do ojca 
	LinkedList edges_list{nullptr};	///< lista krawêdzi
};
/** Struktura Grafu*/ 
struct Graph
{
	Vertex vertices[MAX_N]; ///<tablica wierzcho³ków(?)
	size_t vertices_number; ///<liczba wierzcho³ków
};


/** Funkcja dodaj¹ca krawêdz do grafu
@param graph przekazuje strukture grafu do funkcji
@param e przekazuje strukture krawêdzi do funkcji*/
void addEdge(Graph& graph, Edge e);
/** Funkcja tworz¹ca strukturê grafu
@param how_many_vertices przekazuje liczbe wierzcho³ków do utworzenia w grafie
@return zwraca wska¿nik na pierwszy element grafu*/
Graph createGraph(size_t how_many_vertices, std::string path_to_cities_file, Tree dictionary);
/** Funkcja- algorytm Dijkstry, liczy najkrótsz¹ trasê miêdzy dwoma miastami
@param graph przekazuje strukturê grafu do funkcji
@param beginning_vertex_index przekazuje indeks pierwszego wierzcho³ka grafu*/
void dijkstra(Graph& graph, size_t beginning_vertex_index);
/** Funkcja dodaj¹ca wêze³ do listy
@param list przekazuje liste do funkcji
@param edge krawêdŸ grafu */
void add(LinkedList& list, Edge edge);
/** Funkcja szukaj¹ca podan¹ wartoœæ listy i zwracaj¹ca wskaŸnik na ten element listy
@param list przekazuje liste do funkcji
@param edge przekazuje do funkcji wartoœæ elementu listy, którego wskaŸnik jest szukany
@return zwraca wskaŸnik na szukany element listy*/
LinkedListNode* find(LinkedList& list, Edge edge);
/** Funkcja usuwa dany element listy
@param list przekazuje liste do funkcji
@param edge przekazuje do funkcji wartoœæ elementu listy, który bedzie u¿ywany w funkcji find */
void remove(LinkedList& list, Edge edge);
/** Funkcja zawracaj¹ca wskaŸnik LinkedListNode'a na poprzedni element listy
@param list przekazuje liste do funkcji
@param actual wskazuje na obecny wêze³ listy
@return zwraca wskaŸnik na poprzedni element listy*/
LinkedListNode* previous(LinkedList& list, LinkedListNode* actual);



