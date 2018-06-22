/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#include <string>
#include <iostream>
#include "main.hpp"
#include "graph.hpp"
#define ERROR -1

char GetOtherVertexOfEdge(const Edge& e, char v);
void CalculateVertexes(Graph g);
void AnalyzeEdgesOfVertex(Graph g, char v, std::vector<char> vertexlist);

template <class T>
bool ListContains(std::vector<T> list, T item)
{
	for (T listitem : list)
	{
		if (listitem == item)
		{
			return true;
		}
	}
	return false;
}

/*initialize data*/
int main()
{
	std::vector<char> vertex = { {'a'},{'b'},{'c'},{'d'},{'e'},{'f'} };
	std::vector<Edge> edges = { {'a','b'},{'b','c'},{'c','a'},{'c','b'},{'d','c'},{'e','f'} };
	Graph graph(vertex, edges); //changed order
	graph.printvertex();
	graph.printedges();
	return 0;
}

void CalculateVertexes(Graph g) 
{
	std::vector<char> vertexlist;
	char max_vertex = 0, max_vertex_count = 0;
	for (char v : g.Vertexes())
	{
		if (g.GetEdgeCount(v) > max_vertex_count)
		{
			max_vertex = v;
			max_vertex_count = g.GetEdgeCount(v);
		}
	}
	vertexlist.insert(vertexlist.end(), max_vertex);

	for (Edge e : g.GetEdgesOfVertex(max_vertex))
	{
		g.EdgeAnalyzed()[e] = true;
	}

	while (g.HasUnanalyzedEdges())
	{
		for (Edge e : g.GetEdgesOfVertex(max_vertex))
		{
			/// TODO
		}
	}
}

void AnalyzeEdgesOfVertex(Graph g, char v, std::vector<char> vertexlist)
{
	for (Edge e : g.GetEdgesOfVertex(v))
	{
		if (g.EdgeAnalyzed()[e] == true)
		{
			return;
		}
		g.EdgeAnalyzed()[e] = true;
		if (!ListContains<char>(vertexlist, v))
		{
			vertexlist.insert(vertexlist.end(), v);
		}
		if (GetOtherVertexOfEdge(e, v) != ERROR)
		{
			AnalyzeEdgesOfVertex(g, GetOtherVertexOfEdge(e, v), vertexlist);
		}
	}
}



char GetOtherVertexOfEdge(const Edge& e, char v)
{
	if (e.x == v)
	{
		return e.y;
	}
	else if (e.y == v)
	{
		return e.x;
	}
	else
	{
		return ERROR;
	}
}