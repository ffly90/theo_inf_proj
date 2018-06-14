/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#include <string>
#include <iostream>
#include "main.hpp"
#include "graph.hpp"

/*initialize data*/
int main()
{
  std::vector<char> nodes = {{'a'},{'b'},{'c'},{'c'},{'e'},{'f'}};
  std::vector<Edge> edges = {{'a','b'},{'b','c'},{'c','a'},{'c','b'},{'d','c'},{'e','f'},{'f','e'}};
  Graph graph(edges,nodes);
  graph.pintedges();
  return 0;
}
