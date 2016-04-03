#include "Graph.h"
#include <iostream>
#include <conio.h>

int main()
{
    Graph myGraph;
    
    myGraph.inputVertices();
    myGraph.inputEdges();
    myGraph.traverseUsingDijkstra();
    myGraph.printDistanceFromSource();

    _getch();
    return 0;
}