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
void AnalyzeEdgesOfVertex(Graph& g, char v, std::vector<char>& vertexlist);
void PrintVertexList(std::vector<char> vertexlist);

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
	std::vector<Edge> edges = { {'a','b'},{'f','c'},{'c','a'},{'c','b'},{'d','c'},{'e','f'} };

	std::vector<char> vertexA = { { '1' },{ '2' },{ '3' },{ '4' },{ '5' },{ '6' },{ '7' } };
	std::vector<Edge> edgesA = { { '1','2' },{ '2','4' },{ '4','3' },{ '4','6' },{ '3','6' },{ '3','5' },{ '6','5' },{ '6','7' } };

	std::vector<char> vertexB = { { '0' },{ '1' },{ '2' },{ '3' },{ '4' },{ '5' },{ '6' },{ '7' },{ '8' },{ '9' },{ 'a' },{ 'b' },{ 'c' },{ 'd' },{ 'e' },{ 'f' },{ 'g' },{ 'h' },{ 'i' },{ 'j' },{ 'k' },{ 'l' },{ 'm' },{ 'n' },{ 'o' },{ 'p' },{ 'q' },{ 'r' },{ 's' },{ 't' },{ 'u' } };
	std::vector<Edge> edgesB = { { '0','1' },{ '0','2' },{ '1','2' },{ '1','3' },{ '1','4' },{ '1','6' },{ '2','3' },{ '2','5' },{ '2','6' },{ '3','4' },{ '3','7' },{ '3','8' },{ '3','a' },{ '4','5' },{ '4','7' },{ '4','9' },{ '4','a' },{ '5','6' },{ '5','b' },{ '5','c' },{ '5','e' },{ '6','b' },{ '6','d' },{ '6','e' },{ '7','8' },{ '7','f' },{ '7','g' },{ '7','i' },{ '8','9' },{ '8','f' },{ '8','i' },{ '8','j' },{ '9','a' },{ '9','k' },{ '9','l' },{ '9','n' },{ 'a','b' },{ 'a','j' },{ 'a','l' },{ 'a','m' },{ 'b','c' },{ 'b','n' },{ 'b','o' },{ 'b','q' },{ 'c','d' },{ 'c','n' },{ 'c','p' },{ 'c','q' },{ 'd','e' },{ 'd','r' },{ 'd','s' },{ 'd','u' },{ 'e','r' },{ 'e','t' },{ 'e','u' },{ 'f','g' },{ 'g','h' },{ 'h','i' },{ 'i','j' },{ 'j','k' },{ 'k','l' },{ 'l','m' },{ 'm','n' },{ 'n','o' },{ 'o','p' },{ 'p','q' },{ 'q','r' },{ 'r','s' },{ 's','t' },{ 't','u' } };


	Graph graph(vertexB, edgesB); //changed order
	graph.printvertex();
	graph.printedges();
	CalculateVertexes(graph);
	return 0;
}

void CalculateVertexes(Graph g)
{
	std::vector<char> vertexlist;

	while (g.HasUnanalyzedEdges())
	{
		char max_vertex = 0, max_vertex_count = 0;
		for (char v : g.Vertexes())
		{
			if (g.GetEdgeCount(v) > max_vertex_count && !(ListContains<char>(vertexlist, v)) && g.HasUnanalyzedEdges(v))
			{
				max_vertex = v;
				max_vertex_count = g.GetEdgeCount(v);
			}
		}

		std::cout << "Analyze Vertex: " << max_vertex << std::endl;
		for (Edge e : g.GetEdgesOfVertex(max_vertex))
		{
			std::cout << "Edge: (" << e.x << "," << e.y << "," << g.EdgeAnalyzed()[e] << ") of Vertex " << max_vertex << std::endl;
			if (g.EdgeAnalyzed()[e] != true)
			{
				if (!(ListContains<char>(vertexlist, max_vertex)))
				{
					vertexlist.insert(vertexlist.end(), max_vertex);
				}
				std::cout << "Analyze Edge: (" << e.x << "," << e.y << ") of Vertex " << max_vertex << std::endl;
				g.SetEdgeAnalyzed(e);
				AnalyzeEdgesOfVertex(g, GetOtherVertexOfEdge(e, max_vertex), vertexlist);
			}
		}
		PrintVertexList(vertexlist);
	}
	PrintVertexList(vertexlist);
	g.printedges();
}

void AnalyzeEdgesOfVertex(Graph& g, char v, std::vector<char>& vertexlist)
{
	std::cout << "Analyze Vertex: " << v << std::endl;
	for (Edge e : g.GetEdgesOfVertex(v))
	{
		std::cout << "Edge: (" << e.x << "," << e.y << "," << g.EdgeAnalyzed()[e] << ") of Vertex " << v << std::endl;
		if (g.EdgeAnalyzed()[e] == true)
		{
			break;
		}
		std::cout << "Analyze Edge: (" << e.x << "," << e.y << ") of Vertex " << v << std::endl;
		g.SetEdgeAnalyzed(e);
		if (!ListContains<char>(vertexlist, v))
		{
			vertexlist.insert(vertexlist.end(), v);
		}
		if (GetOtherVertexOfEdge(e, v) != ERROR && !ListContains<char>(vertexlist, GetOtherVertexOfEdge(e, v)))
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

void PrintVertexList(std::vector<char> vertexlist)
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
