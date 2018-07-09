/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#include "graph.hpp"
#include <iostream>
#include <algorithm>
#include <string>


//Definition of the constructor of the class Graph
//	Complexity: O(e)
Graph::Graph(std::vector<int> vertex_, std::vector<Edge> edges_) :
    _edges(edges_), _vertex(vertex_)
{
    for (Edge e : edges_)
    {
        _edgeAnalyzed.emplace(e, 0);
    }
}
/*Definition of the function that calculates the list of needed vertexes.
	In this case by sorting the list of vertexes by their degree and then
	analizing the vertexes from the beginning using the greedy algorithm*/
void Graph::CalculateVertexes()
{
    this->SortVertexesByDegree(); // Complexity: O(v * log(v))
    this->printvertex(); // Complexity: O(v)
    while (HasUnanalyzedEdges()) // O(v)
    {
		this->SortVertexesByDegree();
        for (Edge e : this->GetEdgesOfVertex(_vertex[0])) // O(e)
        {
            if (this->EdgeAnalyzed()[e] != true) // O(log(e))
            {
                if (!(ListContains(_vertexlist, _vertex[0]))) // O(v)
                {
                    _vertexlist.insert(_vertexlist.end(), _vertex[0]); // O(1)
                }
                this->SetEdgeAnalyzed(e); // O(log(e))
            }
        }
		_vertex.erase(_vertex.begin());
    } // O(v * log(v)) + O(v) + (O(v) * O(e) * O(log(e)) * (O(v) + O(log(e))))
	// O(v * e * log(e) * (v + log(e))
}

//Defition of the funtion that prints the fields of a vector to standard out.
//	In this case to print the content of the variable that holds the result of
//	the funtion Graph::CalculateVertexes
//	Complexity: O(v)
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

// Definition of the function that runs a check whether or not an element
//	(e.g. a vertex) of a given array is identicat to a given value
//	Complexity: O(n)
bool Graph::ListContains(std::vector<int> list, int item)
{
    for (int listitem : list)
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

// Prints the edges. Complexity: O(e)
void Graph::printedges()
{
    std::cout << "Edges: ";
    for (std::pair<Edge, bool> e : _edgeAnalyzed)
    {
        std::cout << "(" << e.first.x << "," << e.first.y << "," << e.second << ")" << " ";
    }
    std::cout << std::endl;
}

// Sorts vertexes by degree. Complexity: O(v * log(v))
void Graph::SortVertexesByDegree()
{
    std::sort(_vertex.begin(), _vertex.end(), [this](int a, int b)
    {
        return (this->GetUnanalyzedEdgeCount(a) > this->GetUnanalyzedEdgeCount(b));
    });
}

// Prints vertexes. Complexity: O(v)
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

// Gets count of Edges at a vertex; Complexity: O(e)
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

int Graph::GetUnanalyzedEdgeCount(int vertex)
{
	int i = 0;
	for (Edge e : _edges)
	{
		if ((e.x == vertex || e.y == vertex) && !(e.x == e.y) && _edgeAnalyzed[e] != true)
		{
			i++;
		}
	}
	return i;
}

// Get all Edges of a vertex. Complexity: O(e)
std::vector<Edge> Graph::GetEdgesOfVertex(int vertex)
{
    std::vector<Edge> v_edges;
    for (std::pair<Edge, bool> e : _edgeAnalyzed)
    {
        if (e.first.x == vertex || e.first.y == vertex)
        {
            v_edges.insert(v_edges.end(), e.first);
        }
    }
    return v_edges;
}

std::vector<Edge> Graph::GetUnanalyzedEdgesOfVertex(int vertex)
{
	std::vector<Edge> v_edges;
	for (std::pair<Edge, bool> e : _edgeAnalyzed)
	{
		if ((e.first.x == vertex || e.first.y == vertex) && e.second == true)
		{
			v_edges.insert(v_edges.end(), e.first);
		}
	}
	return v_edges;
}

// Checks, if a vertex has unanalyzed edges. Complexity: O(e)
bool Graph::HasUnanalyzedEdges(int vertex)
{
    for (std::pair<Edge, bool> e : _edgeAnalyzed)
    {
        if ((e.first.x == vertex || e.first.y == vertex) && e.second == false)
        {
            return true;
        }
    }
    return false;
}

bool Graph::HasUnanalyzedEdges()
{
	for (std::pair<Edge, bool> e : _edgeAnalyzed)
	{
		if (e.second == false)
		{
			return true;
		}
	}
	return false;
}

//Sets a edge as analyzed. Complexity: O(log(e))
void Graph::SetEdgeAnalyzed(const Edge & e)
{
    _edgeAnalyzed[e] = true;
}
