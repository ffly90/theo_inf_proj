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
	char max_vertex = 0, max_vertex_count = 0;
	for each (char v in g.Vertexes())
	{
		if (g.GetEdgeCount(v) > max_vertex_count)
		{
			max_vertex = v;
			max_vertex_count = g.GetEdgeCount(v);
		}
	}
	std::vector<Edge> v_edges = g.GetEdgesOfVertex(max_vertex);
	for each (Edge e in v_edges)
	{
		g.EdgeAnalyzed[e] = true;
	}
	
	while (g.HasUnanalyzedEdges())
	{
		// TODO: Assign the remaining Edges
	}
}