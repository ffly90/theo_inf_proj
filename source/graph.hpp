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
    Graph(std::vector<int> vertex_, std::vector<Edge> edges_);
    void CalculateVertexes();
    void PrintVertexList();
    void printvertex();
    int GetEdgeCount(int vertex);
    void printedges();
private:
    std::vector<Edge> _edges;
    std::vector<int> _vertex;
    std::vector<int> _vertexlist;
};
#endif //GRAPH_HPP
