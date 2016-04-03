#pragma once
#include "Vertex.h"

class Graph
{
private:
    Vertex* graphNodes;
    int numberOfNodes;
    int sourceVertexID;
    bool undirected;

public:
    Graph();

    void inputVertices();
    void inputEdges();

    Vertex* getGraphNodes();
    int getNumberOfNodes();
    int getSourceVertexID();

    void traverseUsingDijkstra();

    void printDistanceFromSource();

    ~Graph();
};
