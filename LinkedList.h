/** @file */
#pragma once
#include "Graph.h"

//struct Edge;
/** Struktura w�z�a listy*/
struct LinkedListNode
{
	LinkedListNode* next=nullptr;	///< ustawienie wska�nika nast�pnego w�z�a listy na null
	Edge value;						///< warto�� danego elementu listy
};
/** Struktura listy*/ 
struct LinkedList
{
	LinkedListNode* head=nullptr;		///< wska�nik na pierwszy w�ze� listy, tzw. g�ow�
};

/** Funkcja dodaj�ca w�ze� do listy
@param list 
@param edge kraw�d� grafu */
void add(LinkedList& list, Edge edge);
/** Funkcja szukaj�ca podan� warto�� listy i zwracaj�ca wska�nik na ten element listy
@param list
@param edge przekazuje do funkcji warto�� elementu listy, kt�rego wska�nik jest szukany
@return zwraca wska�nik na szukany element listy*/
LinkedListNode* find(LinkedList& list, Edge edge);
/** Funkcja usuwa dany element listy
@param list
@param edge przekazuje do funkcji warto�� elementu listy, kt�ry bedzie u�ywany w funkcji find */
void remove(LinkedList& list, Edge edge);
/** Funkcja zawracaj�ca wska�nik LinkedListNode'a na poprzedni element listy
@param list
@param actual wskazuje na obecny w�ze� listy
@return zwraca wska�nik na poprzedni element listy*/
LinkedListNode* previous(LinkedList& list, LinkedListNode* actual);



