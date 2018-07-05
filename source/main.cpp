/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#include <iostream>
#include "main.hpp"
#include "graph.hpp"

int main()
{
    std::cout << "Projektarbeit Theoretische Informatik Version " << version << " von " << authors << std::endl;
    /*Read data (vertexes and edges) for example A*/
    std::vector<int> vertexA = { { 1 },{ 2 },{ 3 },{ 4 },{ 5 },{ 6 },{ 7 } };
    std::vector<Edge> edgesA = { { 1,2 },{ 2,4 },{ 4,3 },{ 4,6 },{ 3,6 },{ 3,5 },{ 6,5 },{ 6,7 } };
    /*Read data (vertexes and edges) for example B*/
    std::vector<int> vertexB = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    std::vector<Edge> edgesB = { { 1,2 },{ 1,3 },{ 2,3 },{ 2,4 },{ 2,5 },{ 2,7 },{ 3,4 },{ 3,6 },{ 3,7 },{ 4,5 },{ 4,8 },{ 4,9 },{ 4,11 },{ 5,6 },{ 5,8 },{ 5,10 },{ 5,11 },{ 6,7 },{ 6,12 },{ 6,13 },{ 6,15 },{ 7,12 },{ 7,14 },{ 7,15 },{ 8,9 },{ 8,16 },{ 8,17 },{ 8,19 },{ 9,10 },{ 9,16 },{ 9,18 },{ 9,19 },{ 10,11 },{ 10,20 },{ 10,21 },{ 10,23 },{ 11,12 },{ 11,20 },{ 11,22 },{ 11,23 },{ 12,13 },{ 12,24 },{ 12,25 },{ 12,27 },{ 13,14 },{ 13,24 },{ 13,26 },{ 13,27 },{ 14,15 },{ 14,28 },{ 14,29 },{ 14,31 },{ 15,28 },{ 15,30 },{ 15,31 },{ 16,17 },{ 17,18 },{ 18,19 },{ 19,20 },{ 20,21 },{ 21,22 },{ 22,23 },{ 23,24 },{ 24,25 },{ 25,26 },{ 26,27 },{ 27,28 },{ 28,29 },{ 29,30 },{ 30,31 } };

    /*Make an object with the given data*/
    Graph graphA(vertexA, edgesA);
    /*Make an object with the given data*/
    Graph graphB(vertexB, edgesB);

    /*Calculate vertexes needed to reach all given vertexes (for example A)*/
    graphA.CalculateVertexes();
    /*Print the calculated list of vertexes*/
    graphA.PrintVertexList();
    /*Calculate vertexes needed to reach all given vertexes (for example B)*/
    graphB.CalculateVertexes();
    /*Print the claculated list of vertexes*/
    graphB.PrintVertexList();

    return 0;
}
