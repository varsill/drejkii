/** @file */
#pragma once
#include "Graph.h"

//struct Edge;
/** Struktura wêz³a listy*/
struct LinkedListNode
{
	LinkedListNode* next=nullptr;	///< ustawienie wskaŸnika nastêpnego wêz³a listy na null
	Edge value;						///< wartoœæ danego elementu listy
};
/** Struktura listy*/ 
struct LinkedList
{
	LinkedListNode* head=nullptr;		///< wskaŸnik na pierwszy wêze³ listy, tzw. g³owê
};

/** Funkcja dodaj¹ca wêze³ do listy
@param list 
@param edge krawêdŸ grafu */
void add(LinkedList& list, Edge edge);
/** Funkcja szukaj¹ca podan¹ wartoœæ listy i zwracaj¹ca wskaŸnik na ten element listy
@param list
@param edge przekazuje do funkcji wartoœæ elementu listy, którego wskaŸnik jest szukany
@return zwraca wskaŸnik na szukany element listy*/
LinkedListNode* find(LinkedList& list, Edge edge);
/** Funkcja usuwa dany element listy
@param list
@param edge przekazuje do funkcji wartoœæ elementu listy, który bedzie u¿ywany w funkcji find */
void remove(LinkedList& list, Edge edge);
/** Funkcja zawracaj¹ca wskaŸnik LinkedListNode'a na poprzedni element listy
@param list
@param actual wskazuje na obecny wêze³ listy
@return zwraca wskaŸnik na poprzedni element listy*/
LinkedListNode* previous(LinkedList& list, LinkedListNode* actual);



