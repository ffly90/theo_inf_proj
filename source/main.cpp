/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#include <string>
#include <iostream>
#include "main.hpp"
#include "graph.hpp"

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

void CalculateVertexes(const Graph &g) {
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
		g.EdgeAnalyzed[e] = true;
	}

	while (g.HasUnanalyzedEdges())
	{
		// TODO: Assign the remaining Edges
	}
}