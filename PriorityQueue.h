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
	Vertex t[MAX_SIZE];	///< tablica wierzcho�k�w kopca
};

/** Funkcja dodaj�ca element do kopca
@param queue odwo�anie sie do kolejki priorytetowej
@param element warto��, kt�ra dodajemy do kopca*/
void insert(PriorityQueue& queue, Vertex  element);
/** Funkcja naprawiaj�ca strukture kopca
@param queue odwo�anie sie do kolejki priorytetowej
@param i numer w�z�a w kopcu*/
void heapify(PriorityQueue& queue, size_t i);
/** Funkcja zwracaj�ca warto�� minimum z kopca
@param queue odwo�anie do kolejki priorytetowej
@return zwraca minimaln� wartosc z kopca*/
Vertex getMin(PriorityQueue& queue);
/** Funkcja sprawdzaj�ca czy kopiec jest niepusty
@param odwo�anie do kolejki priorytetowej
@return true w wypadku, gdy w kopcu znajduj� si� elementy lub false, gdy kopiec jest pusty*/
bool isEmpty(PriorityQueue& queue);
/** Funkcja tworz�ca kolejk� priorytetow� i zwracaj�ca wska�nik do struktury pustej kolejki priorytetowej
@return wska�nik do struktury pustej kolejki priorytetowej*/
PriorityQueue* createPriorityQueue();


