/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <map>
#include "edge.hpp"


class Graph
{
public:
	Graph(std::vector<char> vertex_, std::vector<Edge> edges_);
	void printvertex();
	int GetEdgeCount(char vertex);
	std::vector<Edge> GetEdgesOfVertex(char vertex);
	bool HasUnanalyzedEdges(char vertex);
	bool HasUnanalyzedEdges();
	std::vector<Edge> Edges();
	std::vector<char> Vertexes();
	std::map<Edge, bool> EdgeAnalyzed();
	void printedges();
private:
	std::vector<Edge> _edges;
	std::vector<char> _vertex;
	std::map<Edge, bool> _edgeAnalyzed;
};

#endif //GRAPH_HPP
