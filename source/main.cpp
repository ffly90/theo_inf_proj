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
    std::vector<char> vertex = {{'a'},{'b'},{'c'},{'d'},{'e'},{'f'}};
    std::vector<Edge> edges = {{'a','b'},{'b','c'},{'c','a'},{'c','b'},{'d','c'},{'e','f'}};
    Graph graph(vertex,edges); //changed order
    graph.printvertex();
    graph.printedges();
    return 0;
}
