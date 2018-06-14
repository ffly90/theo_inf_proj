#include <iostream>
#include "graph.hpp"

Graph::Graph(std::vector<Edge> edges_):_edges(edges_){}

void Graph::printedges(){
  for (unsigned int i = 0; i < _edges.size(); i++){
  std::cout << "(" << _edges[i].x << "," << _edges[i].y << ")" << " ";
  }
}
