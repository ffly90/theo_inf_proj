/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#include <iostream>
#include "graph.hpp"

Graph::Graph(std::vector<char> vertex_, std::vector<Edge> edges_) :
	_edges(edges_), _vertex(vertex_)
{
	for (Edge e : _edges)
	{
		_edgeAnalyzed.insert(_edgeAnalyzed.end(), std::make_pair(e, false));
	}
}

std::vector<Edge> Graph::Edges()
{
	return _edges;
}

std::vector<char> Graph::Vertexes()
{
	return _vertex;
}

std::map<Edge, bool> Graph::EdgeAnalyzed()
{
	return _edgeAnalyzed;
}

void Graph::printedges()
{
	std::cout << "Edges: ";
	for (unsigned int i = 0; i < _edges.size(); i++)
	{
		std::cout << "(" << _edges[i].x << "," << _edges[i].y << ")" << " ";
	}
	std::cout << std::endl;
}

void Graph::printvertex()
{
	std::cout << "Vertex: (";
	for (unsigned int i = 0; i < _vertex.size(); i++)
	{
		std::cout << _vertex[i];
		if (i == _vertex.size() - 1)
		{
			break;
		}
		std::cout << ", ";
	}
	std::cout << ")" << std::endl;

}

/// Gets count of Edges at a vertex
int Graph::GetEdgeCount(char vertex)
{
	int i = 0;
	for (Edge e : _edges)
	{
		if (e.x == vertex || e.y == vertex && !(e.x == e.y))
		{
			i++;
		}
		return i;
	}
}

std::vector<Edge> Graph::GetEdgesOfVertex(char vertex)
{
	std::vector<Edge> v_edges;
	for (Edge e : _edges)
	{
		if (e.x == vertex || e.y == vertex && !(e.x == e.y))
		{
			v_edges.insert(v_edges.end(), e);
		}
	}
}

bool Graph::HasUnanalyzedEdges(char vertex)
{
	for each (Edge e in GetEdgesOfVertex(vertex))
	{
		if (_edgeAnalyzed[e] == false)
		{
			return true;
		}
	}
	return false;
}

bool Graph::HasUnanalyzedEdges()
{
	for (auto&&[first, second] : _edgeAnalyzed)
	{
		if (second == false)
			return true;
	}
	return false;
}