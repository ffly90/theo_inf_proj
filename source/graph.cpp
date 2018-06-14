#include <iostream>
#include "graph.hpp"

Graph::Graph(std::vector<Edge> edges_, std::vector<char> nodes_):
            _edges(edges_),_nodes(nodes_){}

void Graph::printedges(){
  for (unsigned int i = 0; i < _edges.size(); i++){
    std::cout << "(" << _edges[i].x << "," << _edges[i].y << ")" << " ";
  }
  std::cout << std::endl;
}
void Graph::printnodes(){
  for (unsigned int i = 0; i < _nodes.size(); i++){
    std::cout << "(" << _nodes[i] << ")" << " ";
  }
  std::cout << std::endl;
}
