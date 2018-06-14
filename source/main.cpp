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
  std::vector<Edge> graph = {{a,b},{b,c},{c,a},{c,b},{d,c},{e,f},{f,e}};
  Graph sample1(graph);
  return 0;
}
