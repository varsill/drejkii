#include "Graph.h"
#include <iostream>
void add(LinkedList& list, Edge edge)
{
	LinkedListNode* buf = list.head;
	list.head = new LinkedListNode;
	list.head->value = edge;
	list.head->next = buf;

}
LinkedListNode* find(LinkedList& list,Edge edge)
{
	LinkedListNode* i = list.head;
	while (i != nullptr)
	{
		if (i->value.to == edge.to)return i;
	}
	return nullptr;
}
void remove(LinkedList& list, Edge edge)
{
	LinkedListNode* to_delete=find(list, edge);
	if (to_delete == nullptr)
	{
		return;
	}

	LinkedListNode* prev = previous(list, to_delete);
	if (prev == nullptr) list.head = to_delete->next;
	else prev->next = to_delete->next;

}
LinkedListNode* previous(LinkedList& list, LinkedListNode* actual)
{
	LinkedListNode* a=nullptr;
	LinkedListNode* b = list.head;
	while (b != nullptr)
	{
		if (b->value.to == actual->value.to)return a;
		a = b;
		b = b->next;
	}
	return nullptr;

}


