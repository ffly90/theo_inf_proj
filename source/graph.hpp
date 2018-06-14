#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include "edge.hpp"


class Graph{
public:
  Graph(std::vector<Edge> edges_);
  void pintedges();
private:
  std::vector<Edge> _edges;
};

#endif //GRAPH_HPP
