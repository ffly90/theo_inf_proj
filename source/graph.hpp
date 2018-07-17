/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include "edge.hpp"


class Graph
{
public:
    Graph(std::vector<size_t> vertex_, std::vector<Edge> edges_);
    void CalculateVertexes();
    void PrintVertexList();
    void printvertex();
    int GetEdgeCount(size_t vertex);
	bool CheckVertexlist(std::vector<Edge> edgelist);
private:
    std::vector<Edge> _edges;
    std::vector<size_t> _vertex;
    std::vector<size_t> _vertexlist;
};
#endif //GRAPH_HPP
