/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#include <string>
#include <iostream>
#include "main.hpp"
#include "graph.hpp"
#define ERROR -1
//#define DEBUG

char GetOtherVertexOfEdge(const Edge& e, int v);
void CalculateVertexes(Graph g);
void AnalyzeEdgesOfVertex(Graph& g, int v, std::vector<int>& vertexlist);
void PrintVertexList(std::vector<int> vertexlist);

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
	std::vector<int> vertexA = { { 1 },{ 2 },{ 3 },{ 4 },{ 5 },{ 6 },{ 7 } };
	std::vector<Edge> edgesA = { { 1,2 },{ 2,4 },{ 4,3 },{ 4,6 },{ 3,6 },{ 3,5 },{ 6,5 },{ 6,7 } };

	std::vector<int> vertexB = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
	std::vector<Edge> edgesB = { { 1,2 },{ 1,3 },{ 2,3 },{ 2,4 },{ 2,5 },{ 2,7 },{ 3,4 },{ 3,6 },{ 3,7 },{ 4,5 },{ 4,8 },{ 4,9 },{ 4,11 },{ 5,6 },{ 5,8 },{ 5,10 },{ 5,11 },{ 6,7 },{ 6,12 },{ 6,13 },{ 6,15 },{ 7,12 },{ 7,14 },{ 7,15 },{ 8,9 },{ 8,16 },{ 8,17 },{ 8,19 },{ 9,10 },{ 9,16 },{ 9,18 },{ 9,19 },{ 10,11 },{ 10,20 },{ 10,21 },{ 10,23 },{ 11,12 },{ 11,20 },{ 11,22 },{ 11,23 },{ 12,13 },{ 12,24 },{ 12,25 },{ 12,27 },{ 13,14 },{ 13,24 },{ 13,26 },{ 13,27 },{ 14,15 },{ 14,28 },{ 14,29 },{ 14,31 },{ 15,28 },{ 15,30 },{ 15,31 },{ 16,17 },{ 17,18 },{ 18,19 },{ 19,20 },{ 20,21 },{ 21,22 },{ 22,23 },{ 23,24 },{ 24,25 },{ 25,26 },{ 26,27 },{ 27,28 },{ 28,29 },{ 29,30 },{ 30,31 } };


	Graph graph(vertexB, edgesB); //changed order
#ifdef DEBUG
	graph.printvertex();
	graph.printedges();
#endif // DEBUG
	CalculateVertexes(graph);
	return 0;
}

void CalculateVertexes(Graph g)
{
	std::vector<int> vertexlist;

	while (g.HasUnanalyzedEdges())
	{
		int max_vertex = 0, max_vertex_count = 0;
		for (int v : g.Vertexes())
		{
			if (g.GetEdgeCount(v) > max_vertex_count && !(ListContains<int>(vertexlist, v)) && g.HasUnanalyzedEdges(v))
			{
				max_vertex = v;
				max_vertex_count = g.GetEdgeCount(v);
			}
		}

		if (max_vertex == 0)
		{
			break;
		}
#ifdef DEBUG
		std::cout << "Analyze Vertex: " << max_vertex << std::endl;
#endif // DEBUG
		for (Edge e : g.GetEdgesOfVertex(max_vertex))
		{
#ifdef DEBUG
			std::cout << "Edge: (" << e.x << "," << e.y << "," << g.EdgeAnalyzed()[e] << ") of Vertex " << max_vertex << std::endl;
#endif // DEBUG
			if (g.EdgeAnalyzed()[e] != true)
			{
				if (!(ListContains<int>(vertexlist, max_vertex)))
				{
					vertexlist.insert(vertexlist.end(), max_vertex);
				}
#ifdef DEBUG
				std::cout << "Analyze Edge: (" << e.x << "," << e.y << ") of Vertex " << max_vertex << std::endl;
#endif // DEBUG
				g.SetEdgeAnalyzed(e);
				AnalyzeEdgesOfVertex(g, GetOtherVertexOfEdge(e, max_vertex), vertexlist);
			}
		}
#ifdef DEBUG
		PrintVertexList(vertexlist);
#endif // DEBUG
	}
	PrintVertexList(vertexlist);
#ifdef DEBUG
	g.printedges();
#endif // DEBUG

}

void AnalyzeEdgesOfVertex(Graph& g, int v, std::vector<int>& vertexlist)
{
#ifdef DEBUG
	std::cout << "Analyze Vertex: " << v << std::endl;
#endif // DEBUG
	for (Edge e : g.GetEdgesOfVertex(v))
	{
#ifdef DEBUG
		std::cout << "Edge: (" << e.x << "," << e.y << "," << g.EdgeAnalyzed()[e] << ") of Vertex " << v << std::endl;
#endif // DEBUG
		if (g.EdgeAnalyzed()[e] == true)
		{
			break;
		}
#ifdef DEBUG
		std::cout << "Analyze Edge: (" << e.x << "," << e.y << ") of Vertex " << v << std::endl;
#endif // DEBUG
		g.SetEdgeAnalyzed(e);
		if (!ListContains<int>(vertexlist, v))
		{
			vertexlist.insert(vertexlist.end(), v);
		}
		if (GetOtherVertexOfEdge(e, v) != ERROR && !ListContains<int>(vertexlist, GetOtherVertexOfEdge(e, v)))
		{
			AnalyzeEdgesOfVertex(g, GetOtherVertexOfEdge(e, v), vertexlist);
		}
	}
}

char GetOtherVertexOfEdge(const Edge& e, int v)
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

void PrintVertexList(std::vector<int> vertexlist)
{
	std::cout << "List of Vertexes: (";
	for (unsigned int i = 0; i < vertexlist.size(); i++)
	{
		std::cout << vertexlist[i];
		if (i == vertexlist.size() - 1)
		{
			break;
		}
		std::cout << ", ";
	}
	std::cout << ")" << std::endl;
}
