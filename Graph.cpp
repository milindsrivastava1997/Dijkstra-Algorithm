#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph()
{
    graphNodes = nullptr;
    cout << "Enter 1 for undirected graph, 2 for directed graph : ";
    int choice;
    cin >> choice;
    cout << endl << "Negative edges are only allowed if there are no negative cycles. This algorithm CANNOT detect negative cycles!";
    if (choice == 1)
    {
        undirected = true;
    }
    else
    {
        undirected = false;
    }
    cout << endl << "Enter number of nodes in the graph : ";
    cin >> numberOfNodes;
    graphNodes = new Vertex[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        graphNodes[i].setParent(nullptr);
    }
}

void Graph::inputVertices()
{
    for (int i = 0; i < numberOfNodes; i++)
    {
        int temp;
        cout << "Enter the value of ID = " << i << " Node : ";
        cin >> temp;
        cout << endl;
        graphNodes[i].setValue(temp);
        graphNodes[i].setID(i);
    }
    cout << "Enter the ID of the source vertex : ";
    cin >> sourceVertexID;
}

void Graph::inputEdges()
{
    char c = 'n';
    do {
        int sourceID, destinationID,weight;
        cout << endl << "Enter the source vertex ID and destination vertex ID of the edge : ";
        cin >> sourceID >> destinationID;
        cout << endl << "Enter the weight of the edge : ";
        cin >> weight;
        graphNodes[sourceID].addNeighbour(&graphNodes[destinationID],weight);
        if (undirected == true)
        {
            graphNodes[destinationID].addNeighbour(&graphNodes[sourceID], weight);
        }
        cout << endl << "Do you want to enter another edge ? ";
        cin >> c;
    } while (c == 'y' || c == 'Y');
}

Vertex* Graph::getGraphNodes()
{
    return graphNodes;
}

int Graph::getNumberOfNodes()
{
    return numberOfNodes;
}

int Graph::getSourceVertexID()
{
    return sourceVertexID;
}

void Graph::traverseUsingDijkstra()
{
    (graphNodes + sourceVertexID)->setDistanceFromSource(0);
    vector<Vertex*> yetToVisit;
    for (int i = 0; i < numberOfNodes; i++)//initially yetToVisit contains all nodes
    {
        yetToVisit.push_back(graphNodes + i);
    }

    while (int(yetToVisit.size()>0))//until yetToVisit is empty
    {
        Vertex* minVertex=yetToVisit[0];
        int minVertexIndex = 0;
        vector<Vertex*>::iterator iter=yetToVisit.begin();
        for (int i = 0; i < (int)yetToVisit.size(); i++)//extract node with min distanceFromSource from yetToVisit
        {
            if (yetToVisit[i]->getDistanceFromSource() < minVertex->getDistanceFromSource())
            {
                minVertex = yetToVisit[i];                
                minVertexIndex = i;
            }
        }
        advance(iter, minVertexIndex);

        for (int i = 0; i < (int)minVertex->adjList.size(); i++)//all outgoing edges from minVertex
        {
            Vertex* ithNeighbour = minVertex->adjList[i].destinationVertex;
            int u = minVertex->getDistanceFromSource();
            int v = ithNeighbour->getDistanceFromSource();
            int w = minVertex->adjList[i].weight;
            if (u + w < v)
            {
                minVertex->adjList[i].destinationVertex->setDistanceFromSource(u + w);//relaxation step
                ithNeighbour->setParent(minVertex);
            }
        }
        yetToVisit.erase(iter);
    }
}

void Graph::printDistanceFromSource()
{
    for (int i = 0; i < numberOfNodes; i++)
    {
        cout << "ID = " << i << " Value = " << graphNodes[i].getValue() << " Distance from source = " << graphNodes[i].getDistanceFromSource();
        cout << endl;
    }
}

Graph::~Graph()
{
    delete[] graphNodes;
}