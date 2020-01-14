#include "Graph.h"
#include "PriorityQueue.h"
void addEdge(Graph& graph, Edge e)
{
	add(graph.vertices[e.from].edges_list, e);
}


Graph createGraph(size_t how_many_vertices, std::string path, Tree dictionary)
{
	Graph result;
	result.vertices_number = how_many_vertices;
	
	for (int i = 0; i < how_many_vertices; i++)
	{
		result.vertices[i].distance = 0;
		result.vertices[i].parent_index = -1;
		result.vertices[i].index = i;
		//result.vertices[i].name=
	}
	std::fstream file;
	file.open(path);
	int distance;
	std::string a, b;
	while (!file.eof())
	{
		file >> a >> b >> distance;
		result.vertices[find(dictionary, a)].name = a;
		result.vertices[find(dictionary, b)].name = b;
	}
	file.close();
	
	return result;
}

void dijkstra(Graph& graph, size_t beginning_vertex_index)
{
	for(int i=0; i<graph.vertices_number; i++)
	{
		graph.vertices[i].distance = INF;
		graph.vertices[i].parent_index = -1;
	}
	graph.vertices[beginning_vertex_index].distance = 0;
	PriorityQueue* queue = createPriorityQueue();
	for (int i = 0; i < graph.vertices_number; i++)
	{
		insert(*queue, graph.vertices[i]);
	}
	bool was_visited[MAX_N];
	for (int i = 0; i < graph.vertices_number; i++) was_visited[i] = false;
	while (!isEmpty(*queue))
	{
		Vertex u = getMin(*queue);
		if (was_visited[u.index] == true)continue;
		was_visited[u.index] = true;
		LinkedListNode* it = u.edges_list.head;
		while (it != nullptr)
		{
			if (u.distance + it->value.weight < graph.vertices[it->value.to].distance)
			{
				Vertex v;
				v.index = graph.vertices[it->value.to].index;
				v.edges_list = graph.vertices[it->value.to].edges_list;
				v.distance= u.distance + it->value.weight;
				v.parent_index = u.index;
				v.distance_to_parent = it->value.weight;
				graph.vertices[v.index].distance = v.distance;
				graph.vertices[v.index].parent_index = v.parent_index;
				graph.vertices[v.index].distance_to_parent = v.distance_to_parent;
				
				
				insert(*queue, v);
			}
			it = it->next;
		}
	}

	delete queue;

}
