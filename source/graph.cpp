/*
Projektarbeit von Sidney Kuyateh (1578641), Marcel Nowak (2915204), Thomas Schäberle (9055502) und Steffen Walter (1145690)
*/
#include "graph.hpp"
#include <iostream>
#include <algorithm>
#include <functional>


//Definition of the constructor of the class Graph
//	Complexity: O(1)
Graph::Graph(std::vector<size_t> vertex_, std::vector<Edge> edges_) :
	_edges(edges_), _vertex(vertex_)
{
}
/*Definition of the function that calculates the list of needed vertexes.
	In this case by sorting the list of vertexes by their degree and then
	analizing the vertexes from the beginning using the greedy algorithm*/
	// Complexity: O(v + e * ((v * e) + e^2))
void Graph::CalculateVertexes()
{
	_vertexlist.reserve(_vertex.size()); // O(v)

	// while-loop: O(e * ((v * e) + e^2))
	while (_edges.size() > 0) // Check: O(1) // Iterations: O(e)
	{
		std::vector<size_t>::iterator max_vertex_it = std::max_element(_vertex.begin(), _vertex.end(), [this](size_t v1, size_t v2) {
			return GetEdgeCount(v1) < GetEdgeCount(v2);
		}); // O(v * e)
		size_t max_vertex = *max_vertex_it;

		size_t length = _edges.size();
		bool alreadySet = false;

		// for-loop: O(e^2)
		for (size_t a = 0; a < length; a++) // Iterations: O(e)
		{
			if (_edges[a].x == max_vertex || _edges[a].y == max_vertex) // O(1)
			{
				if (!alreadySet)
				{
					_vertexlist.push_back(max_vertex); // O(1)
					alreadySet = true; // O(1)
				}
				_edges.erase(_edges.begin() + a); // O(e)
				a--;
				length = _edges.size();
			}
		}
	}
}

//Defition of the funtion that prints the fields of a vector to standard out.
//	In this case to print the content of the variable that holds the result of
//	the funtion Graph::CalculateVertexes
//	Complexity: O(v)
void Graph::PrintVertexList()
{
	std::cout << "List of Vertexes: (";
	for (size_t i = 0; i < _vertexlist.size(); i++)
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

// Prints vertexes. Complexity: O(v)
void Graph::printvertex()
{
	std::cout << "Vertex: (";
	for (size_t i = 0; i < _vertex.size(); i++)
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

// Gets count of Edges at a vertex; Complexity: O(e)
int Graph::GetEdgeCount(size_t vertex)
{
	int i = 0;
	for (Edge e : _edges)
	{
		if (e.x == vertex || e.y == vertex)
		{
			i++;
		}
	}
	return i;
}

// Checks if every edge contains one of the vertexes in the solution.
// Complexity: O(v * e)
bool Graph::CheckVertexlist(std::vector<Edge> edgelist)
{
	for (Edge e : edgelist)
	{
		if (([e,this]() -> bool {
			for (size_t v : _vertexlist)
			{
				if (e.x == v || e.y == v)
				{
					return true;
				}
			}
			return false;
		})() == false)
		{
		return false;
		}
	}
	return true;
}
