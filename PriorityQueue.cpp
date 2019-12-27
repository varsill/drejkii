#include "PriorityQueue.h"
#include <cstdlib>
#include <algorithm>
void insert(PriorityQueue& queue, Vertex element)
{
	queue.size++;
	queue.t[queue.size] = element;

	size_t i = queue.size;
	size_t p = PARENT(i);
	while(p!=0 and queue.t[i].distance<queue.t[p].distance)
	{
		std::swap(queue.t[p], queue.t[i]);
		i = p;
		p = PARENT(i);
	}
}

void heapify(PriorityQueue& queue, size_t i)
{
	size_t l=LEFT(i);
	size_t r=RIGHT(i);
	size_t largest;
	if (l <= queue.size and queue.t[l].distance < queue.t[i].distance) 
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r <= queue.size and queue.t[r].distance < queue.t[largest].distance)
	{
		largest = r;
	}
	if (largest != i)
	{
		std::swap(queue.t[largest], queue.t[i]);
		heapify(queue, largest);
	}


}

bool isEmpty(PriorityQueue& queue)
{
	if (queue.size == 0)return true;
	return false;
}

Vertex getMin(PriorityQueue& queue)
{
	std::swap(queue.t[1], queue.t[queue.size]);
	Vertex result = queue.t[queue.size];
	queue.size--;
	heapify(queue, 1);
	return result;
}

PriorityQueue* createPriorityQueue()
{
	PriorityQueue* queue = new PriorityQueue;
	queue->size = 0;
	return queue;
}


