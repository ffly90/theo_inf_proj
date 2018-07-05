/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#include <iostream>
#include "graph.hpp"
#include <algorithm>
#include <string>

Graph::Graph(std::vector<int> vertex_, std::vector<Edge> edges_) :
	_edges(edges_), _vertex(vertex_)
{
	for (Edge e : edges_)
	{
		_edgeAnalyzed.emplace(e, 0);
	}
}

void Graph::CalculateVertexes()
{
	this->SortVertexesByDegree(); // Complexity: O(n * log(n))
	this->printvertex();
	for (int v : this->Vertexes())
	{
		for (Edge e : this->GetEdgesOfVertex(v))
		{
			if (this->EdgeAnalyzed()[e] != true)
			{
				if (!(ListContains<int>(_vertexlist, v)))
				{
					_vertexlist.insert(_vertexlist.end(), v);
				}
				this->SetEdgeAnalyzed(e);
			}
		}
	}
}

void Graph::PrintVertexList()
{
	std::cout << "List of Vertexes: (";
	for (unsigned int i = 0; i < _vertexlist.size(); i++)
	{
		std::cout << _vertexlist[i];
		if (i == _vertexlist.size() - 1)
		{
			break;
		}
		std::cout << ", ";
	}
	std::cout << ")" << std::endl;
}

template <class T>
bool Graph::ListContains(std::vector<T> list, T item)
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

std::vector<int> Graph::Vertexes()
{
	return _vertex;
}

std::map<Edge, bool, EdgeCompare> Graph::EdgeAnalyzed()
{
	return _edgeAnalyzed;
}

void Graph::printedges()
{
	std::cout << "Edges: ";
	for (auto& e : _edgeAnalyzed)
	{
		std::cout << "(" << e.first.x << "," << e.first.y << "," << e.second << ")" << " ";
	}
	std::cout << std::endl;
}

void Graph::SortVertexesByDegree()
{
	std::sort(_vertex.begin(), _vertex.end(), [this](int a, int b) {return (this->GetEdgeCount(a) > this->GetEdgeCount(b)); });
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
int Graph::GetEdgeCount(int vertex)
{
	int i = 0;
	for (Edge e : _edges)
	{
		if ((e.x == vertex || e.y == vertex) && !(e.x == e.y))
		{
			i++;
		}
	}
	return i;
}

std::vector<Edge> Graph::GetEdgesOfVertex(int vertex)
{
	std::vector<Edge> v_edges;
	for (auto& e : _edgeAnalyzed)
	{
		if (e.first.x == vertex || e.first.y == vertex)
		{
			v_edges.insert(v_edges.end(), e.first);
		}
	}
	return v_edges;
}

bool Graph::HasUnanalyzedEdges(int vertex)
{
	for (Edge e : GetEdgesOfVertex(vertex))
	{
		if (_edgeAnalyzed[e] == false)
		{
			return true;
		}
	}
	return false;
}

void Graph::SetEdgeAnalyzed(const Edge & e)
{
	_edgeAnalyzed[e] = true;
}
