#include <iostream>
#include "graph.hpp"

Graph::Graph(std::vector<Edge> edges_,std::vector<char> nodes;):
            _edges(edges_),_nodes(nodes_){}

void Graph::pintedges(){
  for (unsigned int i = 0; i < _edges.size(); i++){
  std::cout << "(" << _edges[i].x << "," << _edges[i].y << ")" << " ";
  }
}
