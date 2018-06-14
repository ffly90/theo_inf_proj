/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#include <iostream>
#include "graph.hpp"

Graph::Graph(std::vector<char> vertex_, std::vector<Edge> edges_):
            _edges(edges_),_vertex(vertex_){}

void Graph::printedges(){
  std::cout << "Edges: ";
  for (unsigned int i = 0; i < _edges.size(); i++){
    std::cout << "("<< _edges[i].x << "," << _edges[i].y << ")" << " ";
  }
  std::cout << std::endl;
}
void Graph::printvertex(){
  std::cout << "Vertex: (";
  for (unsigned int i = 0; i < _vertex.size(); i++){
    std::cout << _vertex[i];
    if(i==_vertex.size()-1){
      break;
    }
    std::cout << ", ";
  }
  std::cout << ")" << std::endl;

}
