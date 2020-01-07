/** @file */
#pragma once
#include "Graph.h"
#define MAX_SIZE 1024
#define INF 999999999

#define LEFT(i)  2*i	///< lewy syn w kopcu
#define RIGHT(i) 2*i+1	///< prawy syn w kopcu
#define PARENT(i) i/2	///< rodzic w kopcu\

/** Utworzenie struktury kolejki priorytetowej*/
struct Vertex;
struct PriorityQueue
{
	size_t size;		///< rozmiar kopca	  
	Vertex t[MAX_SIZE];	///< tablica wierzcho³ków kopca
};

/** Funkcja dodaj¹ca element do kopca
@param queue odwo³anie sie do kolejki priorytetowej
@param element wartoœæ, która dodajemy do kopca*/
void insert(PriorityQueue& queue, Vertex  element);
/** Funkcja naprawiaj¹ca strukture kopca
@param queue odwo³anie sie do kolejki priorytetowej
@param i numer wêz³a w kopcu*/
void heapify(PriorityQueue& queue, size_t i);
/** Funkcja zwracaj¹ca wartoœæ minimum z kopca
@param queue odwo³anie do kolejki priorytetowej
@return zwraca minimaln¹ wartosc z kopca*/
Vertex getMin(PriorityQueue& queue);
/** Funkcja sprawdzaj¹ca czy kopiec jest niepusty
@param odwo³anie do kolejki priorytetowej
@return true w wypadku, gdy w kopcu znajduj¹ siê elementy lub false, gdy kopiec jest pusty*/
bool isEmpty(PriorityQueue& queue);
/** Funkcja tworz¹ca kolejkê priorytetow¹ i zwracaj¹ca wskaŸnik do struktury pustej kolejki priorytetowej
@return wskaŸnik do struktury pustej kolejki priorytetowej*/
PriorityQueue* createPriorityQueue();


