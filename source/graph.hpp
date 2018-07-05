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
    Graph(std::vector<int> vertex_, std::vector<Edge> edges_);
    void CalculateVertexes();
    void PrintVertexList();
    template <class T>
    bool ListContains(std::vector<T>, T);
    void printvertex();
    int GetEdgeCount(int vertex);
    std::vector<Edge> GetEdgesOfVertex(int vertex);
    bool HasUnanalyzedEdges(int vertex);
    std::vector<int> Vertexes();
    std::map<Edge, bool, EdgeCompare> EdgeAnalyzed();
    void printedges();
    void SortVertexesByDegree();
    void SetEdgeAnalyzed(const Edge& e);
private:
    std::vector<Edge> _edges;
    std::vector<int> _vertex;
    std::vector<int> _vertexlist;
    std::map<Edge, bool, EdgeCompare> _edgeAnalyzed;
};
#endif //GRAPH_HPP
