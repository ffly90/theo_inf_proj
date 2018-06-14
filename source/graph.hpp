#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include "edge.hpp"


class Graph{
public:
  Graph(std::vector<Edge> edges_, std::vector<char> nodes_);
  void pintedges();
private:
  std::vector<Edge> _edges;
  std::vector<char> _nodes;
};

#endif //GRAPH_HPP
