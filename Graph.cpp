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
#include <algorithm>

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

    while (p != nullptr)
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

//Retorna o primeiro noh que não existe no grafo recebido
Node *Graph::nodeNotExist(Node *p, Graph *graph)
{
    for (Node *node = p; node != nullptr; node = node->getNextNode())
    {
        if (!graph->searchNode(node->getId()))
        {
            return node;
        }
    }
    return nullptr;
}

//Function that prints a set of edges belongs breadth tree
void Graph::breadthFirstSearch(ofstream &output_file)
{
    int starting_vertex;
    int number_nodes = getNumberNodes();

    cout << "Digite o vertice de inicio: " << endl;
    cin >> starting_vertex;

    list<int>::iterator i; // percorre os vertices adjacentes
    list<int> queue;       // Cria uma queue

    // inicializa os vertices como nao visitados
    bool *visited = new bool[number_nodes];
    for (int i = 0; i < number_nodes; i++)
        visited[i] = false;

    visited[starting_vertex] = true;
    queue.push_back(starting_vertex);

    while (!queue.empty())
    {
        // Desenfileira um vertice
        starting_vertex = queue.front();

        cout << starting_vertex << " ";        //imprime um vertice
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
    Node *source_node = getNode(idSource); //pega o no com id de origem
    Node *target_node = getNode(idTarget); //pega o no com id de destino

    if (source_node == nullptr || target_node == nullptr)
    {
        cout << "Indices inseridos incorretamente!" << endl;
        return -1;
    }

    int source_index = source_node->getIndex(); //armazena o indice de origem
    int target_index = target_node->getIndex(); //armazena o indice de destino

    float **dist = initializeMatrixFloydMarshall();

    for (Node *p = getFirstNode(); p != nullptr; p = p->getNextNode())
    {
        for (Node *aux = getFirstNode(); aux != nullptr; aux = aux->getNextNode())
        {
            for (Node *aux2 = getFirstNode(); aux2 != nullptr; aux2 = aux2->getNextNode())
            {
                if ((dist[aux->getIndex()][aux2->getIndex()]) >
                    ((dist[aux->getIndex()][p->getIndex()]) +
                     (dist[p->getIndex()][aux2->getIndex()])))
                {
                    dist[aux->getIndex()][aux2->getIndex()] = dist[aux->getIndex()][p->getIndex()] +
                                                              dist[p->getIndex()][aux2->getIndex()];
                }
            }
        }
    }

    //Variavel que recebe o valor da distancia
    float var_dist = dist[source_index][target_index];

    for (int i = 0; i < order; i++) //Desaloca a matriz
        delete[] dist[i];
    delete[] dist;

    return var_dist;
}

float **Graph::initializeMatrixFloydMarshall()
{
    float **dist = new float *[order];

    for (int i = 0; i < order; i++)
    {
        dist[i] = new float[order];
    }

    for (Node *p = getFirstNode(); p != nullptr; p = p->getNextNode())
    {
        int i = p->getIndex();

        for (Node *aux = getFirstNode(); aux != nullptr; aux = aux->getNextNode())
        {
            int j = aux->getIndex();

            if (i != j)
            {
                Edge *edge = p->hasEdgeBetween(aux->getId());

                if (edge == nullptr)
                {
                    dist[i][j] = INFINITY;
                }
                else
                {
                    dist[i][j] = edge->getWeight();
                }
            }
            else
            {
                dist[i][i] = 0;
            }
        }
    }

    return dist;
}

float *Graph::dijkstra(int idSource, int idTarget) {
  Node *rootNode = this->getNode(idSource);
  Node *targetNode = this->getNode(idTarget);

  if (rootNode == nullptr) {
    cout << "\n[Dijkstra]: Node inicial nao encontrado";
    return nullptr;
  }
  if (targetNode == nullptr) {
    cout << "\n[Dijkstra]: Node target nao encontrado";
    return nullptr;
  }

  set<Node *> nodeList;
  nodeList.insert(rootNode);
  map<Node *, Node *> nodeMap;
  float distances[this->order];

  for (Node *p = this->getFirstNode(); p != NULL; p = p->getNextNode()) {
    Edge *edge = rootNode->hasEdgeBetween(p->getId());

    if (edge != nullptr) {
      distances[p->getIndex()] = edge->getWeight();
    } else {
      distances[p->getIndex()] = INFINITY;
    }
  }

  int rootIndex = rootNode->getIndex();
  distances[rootIndex] = 0;

  while (nodeList.size() > 0) {
    Node *nearestNode = this->getNearestNode(nodeList, distances);
    nodeList.erase(nearestNode);
    this->updateDistances(nearestNode, distances, &nodeList, &nodeMap);
  }

  set<Node *> minimumPath = this->getMinimumPath(targetNode, &nodeMap);

  for (set<Node *>::iterator it = minimumPath.begin(); it != minimumPath.end(); it++) {
    cout << (*it)->getId() << "  ";
  }
}
// Auxiliar Dijsktra para achar o caminho minimo
set<Node *> Graph::getMinimumPath(Node *idTarget, map<Node *, Node *> *nodeMap) {
  set<Node *> path;
  Node *step = idTarget;

  map<Node *, Node *>::iterator auxIt = nodeMap->find(step);
  if (auxIt == nodeMap->end()) {
    return path;
  }

  path.insert(step);
  map<Node *, Node *>::iterator it = nodeMap->find(step);
  while (it != nodeMap->end()) {
    step = (*it).second;
    path.insert(step);
    it = nodeMap->find(step);
  }
  return path;
}
// Auxiliar Dijsktra para atualizar as estruturas que determinam as distancia para o initialNode
void Graph::updateDistances(Node *initialNode, float *distances, set<Node *> *nodeList, map<Node *, Node *> *nodeMap) {
  for (Edge *edge = initialNode->getFirstEdge(); edge != nullptr; edge = edge->getNextEdge()) {

    int indexTargetNode = getNode(edge->getTargetId())->getIndex();
    int indexInitialNode = initialNode->getIndex();

    if (distances[indexTargetNode] >= distances[indexInitialNode] + edge->getWeight()) {
      distances[indexTargetNode] = distances[indexInitialNode] + edge->getWeight();

      Node *targetNode = this->getNode(edge->getTargetId());
      map<Node *, Node *>::iterator it = nodeMap->find(targetNode);

      if (it == nodeMap->end()) {
        nodeMap->insert(make_pair(targetNode, initialNode));
      } else {
        (*it).second = initialNode;
      }
      nodeList->insert(targetNode);
    }
  }
}
// Auxiliar Dijsktra para achar o node mais proximo
Node *Graph::getNearestNode(set<Node *> const &nodeList, float *distances) {
  Node *auxNode = nullptr;

  for (set<Node *>::iterator it = nodeList.begin(); it != nodeList.end(); ++it) {
    if (auxNode == nullptr) {
      auxNode = *it;
    } else {
      if (distances[(*it)->getIndex()] < distances[auxNode->getIndex()])
        auxNode = *it;
    }
  }

  return auxNode;
}


//function that prints a topological sorting
void topologicalSorting()
{
}

//Funcao recursiva onde, a partir de idSource, fazemos o caminhamento mais 
//profundo possivel
vector<int> Graph::depthFirstSearch(vector<int> vertexVector, int idSource, int graphOrder,  int *count)
{
    if (!searchNode(idSource))
    {
        cout << "idSource nao existe no grafo!" << endl;
        return vertexVector;
    }

     vertexVector = initializeVertexVector(vertexVector);

    for (list<Node>::iterator it = vertex->begin(); it != vertex->end(); ++it)
    {
        if (it->getId() == idSource)
        {
            cout << "Vertice atual " << it->getId() << endl;

            Node *p;
            vertexVector = auxDepth(vertexVector, it->getId(), count);

            if (it->getNextNode() != 0) //existe o noh;
            {
                p = new Node(it->getNextNode()->getId());

                if (it->getNextNode()->getNextNode() != 0)
                {
                    p->setNextNode(it->getNextNode()->getNextNode());
                }
            }

            //verifica se o grafo ja foi visitado por completo
            if(*count == graphOrder)
            {
                delete p;
                return vertexVector;
            }
            int current_vertex = it->getId();

            //caminha pelos vertices enquanto tiver um noh adjacente
            while(true)
            {
                int j = 0;
                
                for (vector<int>::iterator it = vertexVector.begin(); it != vertexVector.end(); ++it)
                {

                    if (p->getId() == vertexVector[j])
                    {
                        if (p->getNextNode() == 0)
                        {
                            return vertexVector;
                        }
                        p->setId(p->getNextNode()->getId());

                        if (p->getNextNode()->getNextNode() != 0)
                        {
                            p->setNextNode(p->getNextNode()->getNextNode());
                        }
                        else
                        {
                            p->setNextNode(nullptr);
                        }
                        break;
                    }
                    j++;

                    //chamada recursiva
                    if (j == vertexVector.size())
                    {
                        vertexVector = depthFirstSearch(vertexVector, graphOrder, p->getId(), count);
                        cout << "Retornou para o vertice " << current_vertex << endl;
                        if (*count == graphOrder)
                        {
                            delete p;
                            return vertexVector;
                        }
                        break;
                    }
                }
            }
        }
    }
    return vertexVector;
}

//Inicialzia com -1 a lista de vertice
vector<int> Graph::initializeVertexVector(vector<int> &vertexVector)
{
    int i = 0;
    
    for (vector<int>::iterator it = vertexVector.begin(); it != vertexVector.end(); ++it)
    {
        vertexVector[i] = -1;
        i++;
    }

    return vertexVector;
}

//Verifica se o noh ja foi visitado
vector<int> Graph::auxDepth(vector<int> vertexVector, int idNode, int *count)
{
    int i = 0;

    for (vector<int>::iterator it = vertexVector.begin(); it != vertexVector.end(); ++it)
    {
        if (idNode == vertexVector[i])
        {
            if (*count == 0)
            {
                *count = *count + 1;
            }
            return vertexVector;
        }
        i++;
    }
    
    vertexVector[*count] = idNode;
    *count = *count + 1;
    
    return vertexVector;
}

Graph *getVertexInduced(int *listIdNodes)
{
}

Graph *agmKuskal()
{
}

void Graph::agmPrim(int idSource)
{
    Node *p = getNode(idSource);

    if (p == nullptr)
    {
        cout << "Noh inicial nao encontrado!";
        return;
    }

    while (p->getDegree() == 0)
    {
        if (p->getId() != idSource)
        {
            p = p->getNextNode();
        }
        else
        {
            p = getFirstNode();
        }
    }

    idSource = p->getId();

    Node *root_node = getNode(idSource);
    vector<Node *> list;

    Graph *prim_tree = new Graph(order, false, false, false);

    list.push_back(root_node);

    int insert_vector_size = order - 1;
    int insert[insert_vector_size];

    float distance;

    while (order > list.size())
    {
        distance = INFINITY;
        for (int i = 0; i < list.size(); i++)
        {
            for (Edge *edge = list[i]->getFirstEdge(); edge != nullptr; edge = edge->getNextEdge())
            {
                vector<Node *>::iterator it = find(list.begin(), list.end(), getNode(edge->getTargetId()));
                if (edge->getWeight() < distance && it == list.end())
                {
                    distance = edge->getWeight();
                    insert[0] = list[i]->getId();
                    insert[1] = edge->getTargetId();
                }
            }
        }
        list.push_back(getNode(insert[1]));
        prim_tree->insertEdge(insert[0], insert[1], distance);
    }

    p = getFirstNode();
    Node *nodesLeft = nodeNotExist(p, prim_tree);

    while (nodesLeft != nullptr)
    {
        prim_tree->insertNode(nodesLeft->getId());
        nodesLeft = nodeNotExist(nodesLeft, prim_tree);
    }

    prim_tree->printPrimTree();
}

void Graph::printPrimTree()
{

    cout << "Ordem da arvore de prim: " << order << endl;

    for (Node *p = first_node; p != nullptr; p = p->getNextNode())
    {
        cout << "[" << p->getId() << "|" << p->getDegree() << "]";
        Edge *edge = p->getFirstEdge();

        while (edge != nullptr)
        {
            cout << " ----> (" << edge->getTargetId() << "|" << edge->getWeight() << ")";
            edge = edge->getNextEdge();
        }
        cout << endl;
    }
}