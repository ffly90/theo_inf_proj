#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include "edge.hpp"


class Graph{
public:
  Graph(std::vector<Edge> edges_, std::vector<char> vertex_);
  void printvertex();
  void printedges();
private:
  std::vector<Edge> _edges;
  std::vector<char> _vertex;
};

#endif //GRAPH_HPP
