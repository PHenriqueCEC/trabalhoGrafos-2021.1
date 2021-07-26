#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <float.h>
#include <iomanip>

using namespace std;

/**************************************************************************************************
 * Defining the Graph's methods
**************************************************************************************************/

// Constructor
Graph::Graph(int order, bool directed, bool weighted_edge, bool weighted_node, int _number_nodes)
{

    this->order = order;
    this->directed = directed;
    this->weighted_edge = weighted_edge;
    this->weighted_node = weighted_node;
    this->first_node = this->last_node = nullptr;
    this->number_edges = 0;
    number_nodes = _number_nodes;
}

// Destructor
Graph::~Graph()
{

    Node *next_node = this->first_node;

    while (next_node != nullptr)
    {

        next_node->removeAllEdges();
        Node *aux_node = next_node->getNextNode();
        delete next_node;
        next_node = aux_node;
    }
}

// Getters
int Graph::getOrder()
{

    return this->order;
}
int Graph::getNumberEdges()
{

    return this->number_edges;
}
//Function that verifies if the graph is directed
bool Graph::getDirected()
{

    return this->directed;
}
//Function that verifies if the graph is weighted at the edges
bool Graph::getWeightedEdge()
{

    return this->weighted_edge;
}

//Function that verifies if the graph is weighted at the nodes
bool Graph::getWeightedNode()
{

    return this->weighted_node;
}

Node *Graph::getFirstNode()
{

    return this->first_node;
}

Node *Graph::getLastNode()
{

    return this->last_node;
}

// Other methods
/*
    The outdegree attribute of nodes is used as a counter for the number of edges in the graph.
    This allows the correct updating of the numbers of edges in the graph being directed or not.
*/

int Graph::getNumberNodes()
{
    int number_nodes = 0;

    for (Node *p = getFirstNode(); p != nullptr; p = p->getNextNode())
    {
        number_nodes++;
    }

    return number_nodes;
}

void Graph::insertNode(int id)
{
    if (getNode(id) != nullptr)
    {
        return;
    }

    else
    {
        int number_nodes = getNumberNodes();
        Node *p = new Node(id, number_nodes);

        if (last_node == nullptr)
        {
            first_node = p;
            last_node = p;
        }

        else
        {
            last_node->setNextNode(p);
            last_node = p;
        }
    }
}

void Graph::insertEdge(int id, int target_id, float weight)
{
    if (!searchNode(id))
        insertNode(id);

    if (!searchNode(target_id))
        insertNode(target_id);

    Node *exit = getNode(id);
    Node *entry = getNode(target_id);

    exit->insertEdge(target_id, weight);
    entry->insertEdge(id, weight);

    exit->incrementInDegree();
    entry->incrementInDegree();

    number_edges++;
}

void Graph::removeNode(int id)
{
    Node *p = getNode(id);

    if (p == nullptr)
    {
        return;
    }

    else
    {
        Node *q = first_node;

        if (p == first_node)
        {
            first_node = p->getNextNode();
            delete p;
            return;
        }

        else
        {
            while (p != q->getNextNode())
            {
                q = q->getNextNode();
            }

            if (p->getNextNode() == nullptr)
            {
                last_node = q;
            }
            else
            {
                q->setNextNode(p->getNextNode());
            }
            delete p;
        }
    }
}

bool Graph::searchNode(int id)
{
    Node *p = first_node;
    
    while(p != nullptr)
    {
        if (p->getId() == id)
            return true;
        p = p->getNextNode();
    }
    return false;
}

Node *Graph::getNode(int id)
{
    Node *p = first_node;

    while (p != nullptr)
    {
        if (p->getId() == id)
            return p;
        p = p->getNextNode();
    }
    return nullptr;

}

//Function that prints a set of edges belongs breadth tree

void Graph::breadthFirstSearch(ofstream &output_file)
{
    
}

float Graph::floydMarshall(int idSource, int idTarget)
{
}

float Graph::dijkstra(int idSource, int idTarget)
{
}

//function that prints a topological sorting
void topologicalSorting()
{
}

void breadthFirstSearch(ofstream &output_file)
{
}

Graph *getVertexInduced(int *listIdNodes)
{
}

Graph *agmKuskal()
{
}

Graph *agmPrim()
{
}
