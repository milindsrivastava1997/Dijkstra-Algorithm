#pragma once
#include <vector>
#include <queue>
using namespace std;

struct Edge;

class Vertex
{
private:
    int ID;
    int value;
    Vertex* parent;
    int distanceFromSource;

public:
    vector<Edge> adjList;    

    Vertex();
    void setID(int);
    void setValue(int);
    void setParent(Vertex*);
    void setDistanceFromSource(int);

    void addNeighbour(Vertex*,int);

    int getID();
    int getValue();
    Vertex* getParent();
    int getDistanceFromSource();
};

struct Edge
{
    int weight;
    Vertex* sourceVertex;
    Vertex* destinationVertex;
};