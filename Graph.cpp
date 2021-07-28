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

#define INFINITE 2147483647 //valor maximo de uma variavel int

using namespace std;

/**************************************************************************************************
 * Defining the Graph's methods
**************************************************************************************************/

// Constructor
Graph::Graph(int order, bool directed, bool weighted_edge, bool weighted_node)
{

    this->order = order;
    this->directed = directed;
    this->weighted_edge = weighted_edge;
    this->weighted_node = weighted_node;
    this->first_node = this->last_node = nullptr;
    this->number_edges = 0;
    //number_nodes = _number_nodes;
    adj = new list<int>[getNumberNodes()];
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
    int number_nodes = getNumberNodes();
    int starting_vertex;
    
    list<int>::iterator i; // percorre os vertices adjacentes
    list<int> queue; // Cria uma queue
    
    // inicializa os vertices como nao visitados
    bool *visited = new bool[number_nodes];
    for(int i = 0; i < number_nodes; i++)
        visited[i] = false;
 
    // Marca o atual no como visitado e insere na queue
    cout << "Digite o vertice de inicio: " << endl;
    cin >> starting_vertex;
    
    visited[starting_vertex] = true;
    queue.push_back(starting_vertex); 
 
    while(!queue.empty())
    {
        // Desenfileira um vertice
        starting_vertex = queue.front();
        
        cout << starting_vertex << " "; //imprime um vertice
        output_file << starting_vertex << " "; //Faz a escrita no arquivo
        
        queue.pop_front();
 
        // Pega todos os vertices adjacentes desinfileirados 
        // Se nao foi visitado, marcamos como visitado e colocamos na fila
        for (i = adj[starting_vertex].begin(); i != adj[starting_vertex].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

float Graph::floydMarshall(int idSource, int idTarget)
{
    int number_vertex = getNumberNodes();
    
    //Matriz de distancia de tamanho igual ao num de vertices
    int dist[number_vertex][number_vertex];

    for(int i = 0; i < number_vertex; i++)
    {
        for(int j = 0; j < number_vertex; j++)
        {
            
        }
    }



}

float **Graph::initializeMatrixFloydMarshall()
{
    float **dist_matrix = new float *[order]; //Cria uma matriz de distancia de tam = ordem
    int *index_vector = new int(order); //Cria um vetor de indice de tam igual a ordem

    for(int i = 0; i < order; i++)
    {
        dist_matrix[i] = new float[order];

        for(int j = 0; j < order; j++)
        {
            if(i == j)
                dist_matrix[i][j] = 0;
            else
                dist_matrix[i][j] = INFINITE;
        }
    }

    Node *p = first_node;
    int i = 0;
    
    for(; p != nullptr; p = p->getNextNode())
    {
        index_vector[i] = p->getId();
        i++;
    }

    Edge *edge = nullptr; //Inicializa uma aresta auxiliar como nullptr
    p = first_node;

    for(; p != nullptr; p = p->getNextNode())
    {
        for(; edge != nullptr; edge = edge->getNextEdge())
        {
            Node *aux = edge->getTargetId();
        }
    }


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
