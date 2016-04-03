#include "Vertex.h"

Vertex::Vertex()
{
    ID = -1;
    value = 0;
    parent = nullptr;
    distanceFromSource = INT_MAX;
}

void Vertex::setID(int x)
{
    ID = x;
}

void Vertex::setValue(int x)
{
    value = x;
}

void Vertex::setParent(Vertex* x)
{
    parent = x;
}

void Vertex::setDistanceFromSource(int x)
{
    distanceFromSource = x;
}

void Vertex::addNeighbour(Vertex* x, int y)
{
    Edge temp;
    temp.sourceVertex = this;
    temp.destinationVertex = x;
    temp.weight = y;

    adjList.push_back(temp);
}

int Vertex::getID()
{
    return ID;
}

int Vertex::getValue()
{
    return value;
}

Vertex* Vertex::getParent()
{
    return parent;
}

int Vertex::getDistanceFromSource()
{
    return distanceFromSource;
}