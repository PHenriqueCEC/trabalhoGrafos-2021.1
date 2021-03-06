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
#include <map>
#include <deque>

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

    this->number_edges++;
}

int Graph::mapping(int *map, int index)
{
    for (int i = 0; i < order; i++)
    {
        if (map[i] == index)
            return i;
    }
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

//Retorna o primeiro noh que n??o existe no grafo recebido
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
void Graph::breadthFirstSearch(int idSource, int idTarget, ofstream &output_file)
{
    /*if (initial_node == nullptr || target_node == nullptr)
    {
        cout << "Noh inicial ou noh final nao existe no grafo!" << endl;
        return;
    }

    int path_traveled[order] = {-1};
    path_traveled[0] = idSource;

    int path_index = 0;
    deque<Node *> node_deque;

    node_deque.push_back(initial_node);

    while (node)
    {
        for (Edge *edge = node_deque.front()->getFirstEdge(); edge != nullptr; edge = edge->getNextEdge())
        {
            if (!valueInArray(edge->getTargetId(), path_traveled, order))
            {
                if (!idExistsQueue(edge->getTargetId(), node_deque))
                {
                    node_deque.push_back(getNode(edge->getTargetId()));
                }
            }
        }

        cout << node_deque.front()->getId() << "  " << endl;
        output_file << node_deque.front()->getId() << "  " << endl;

        path_traveled[path_index++] = node_deque.front()->getId();

        if (node_deque.front()->getId() == idTarget)
            return;

        node_deque.pop_front();
    }*/

    return;
}

bool Graph::bfs(int inicio, int fim)
{
    /*    Node *noInicio = this->getNode(inicio);
    Node *noObjetivo = this->getNode(fim);
    
    if (noInicio == NULL || noObjetivo == NULL)
    {
        cout << "Deu ruim!" << endl;
        return false;
    }

    order = this->getOrder();
    int visited[order];
    for (int i = 0; i < order; i++)
        visited[i] = -1;

    deque<Node *> queue;

    visited[0] = inicio;
    queue.push_back(inicio);

    //list<int>::iterator i;
    int index = 0;

    while (!queue.empty())
    {
        for (Edge *aresta = queue.front()->getFirstEdge(); aresta != nullptr; aresta = aresta->getNextEdge())
        {
            if (!valueInArray(aresta->getTargetId(), visited, this->order))
            {
                if (!idExistsQueue(aresta->getTargetId(), queue))
                {
                    queue.push_back(this->getNode(aresta->getTargetId()));
                }
            }
        }

        cout << queue.front()->getId() << "  ";

        visited[index++] = queue.front()->getId();

        if (queue.front()->getId() == fim)
            return true;

        queue.pop_front();
    } */

    return false;
}

// Verifica se o id existe em uma fila de nodes
bool Graph::idExistsQueue(int id, deque<Node *> const &deque)
{
    for (int i = 0; i < deque.size(); i++)
    {
        if (deque.at(i)->getId() == id)
            return true;
    }
    return false;
}

bool Graph::valueInArray(int value, int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
            return true;
    }
    return false;
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
/*
float *Graph::dijkstra(int idSource, int idTarget)
{
    Node *source_node = getNode(idSource);
    Node *target_node = getNode(idTarget);

    if (source_node == nullptr || target_node == nullptr)
    {
        cout << " No de origem ou de destino nao encontrado!" << endl;
        return nullptr;
    }

    set<Node *> nodeList;
    nodeList.insert(source_node);
    map<Node *, Node *> nodeMap;

    float distances[order];

    for (Node *p = getFirstNode(); p != NULL; p = p->getNextNode())
    {
        Edge *edge = source_node->hasEdgeBetween(p->getId());

        if (edge != nullptr)
        {
            distances[p->getIndex()] = edge->getWeight();
        }
        else
        {
            distances[p->getIndex()] = INFINITY;
        }
    }

    int sourceIndex = source_node->getIndex();
    distances[sourceIndex] = 0;

    while (nodeList.size() > 0)
    {
        Node *nearestNode = this->getNearestNode(nodeList, distances);
        nodeList.erase(nearestNode);
        updateDistances(nearestNode, distances, &nodeList, &nodeMap);
    }

    set<Node *> shortestPath = this->getShortestPath(target_node, &nodeMap);

    for (set<Node *>::iterator it = shortestPath.begin(); it != shortestPath.end(); it++)
    {
        cout << (*it)->getId() << "  ";
    }
}

// Auxiliar Dijkstra para achar o caminho minimo
set<Node *> Graph::getShortestPath(Node *idTarget, map<Node *, Node *> *nodeMap)
{
    set<Node *> path;
    Node *step = idTarget;

    map<Node *, Node *>::iterator auxIt = nodeMap->find(step);
    if (auxIt == nodeMap->end())
    {
        return path;
    }

    path.insert(step);
    map<Node *, Node *>::iterator it = nodeMap->find(step);
    while (it != nodeMap->end())
    {
        step = (*it).second;
        path.insert(step);
        it = nodeMap->find(step);
    }
    return path;
}
// Auxiliar Dijkstra para atualizar as estruturas que determinam as distancia para o sourceNode

*/

void Graph::updateDistances(Node *sourceNode, float *distances, set<Node *> *nodeList, map<Node *, Node *> *nodeMap)
{
    for (Edge *edge = sourceNode->getFirstEdge(); edge != nullptr; edge = edge->getNextEdge())
    {

        int indexTargetNode = getNode(edge->getTargetId())->getIndex();
        int indexSourceNode = sourceNode->getIndex();

        if (distances[indexTargetNode] >= distances[indexSourceNode] + edge->getWeight())
        {
            distances[indexTargetNode] = distances[indexSourceNode] + edge->getWeight();

            Node *targetNode = this->getNode(edge->getTargetId());
            map<Node *, Node *>::iterator it = nodeMap->find(targetNode);

            if (it == nodeMap->end())
            {
                nodeMap->insert(make_pair(targetNode, sourceNode));
            }
            else
            {
                (*it).second = sourceNode;
            }
            nodeList->insert(targetNode);
        }
    }
}
// Auxiliar Dijkstra para achar o node mais proximo
Node *Graph::getNearestNode(set<Node *> const &nodeList, float *distances)
{
    Node *p = nullptr;

    for (set<Node *>::iterator it = nodeList.begin(); it != nodeList.end(); ++it)
    {
        if (p == nullptr)
        {
            p = *it;
        }
        else
        {
            if (distances[(*it)->getIndex()] < distances[p->getIndex()])
                p = *it;
        }
    }

    return p;
}

//function that prints a topological sorting
void topologicalSorting()
{
}

void Graph::dfsaux(Node *no, int idTarget, vector<bool> &visitados)
{
    if (visitados[idTarget] == true)
    {
        return;
    }
    
    
    Edge *aresta = no->getFirstEdge();
   
    while (aresta != nullptr)
    {
        if (visitados[aresta->getTargetId()] == false)
        {
       
            if (aresta->getNextEdge() == nullptr)
            {
                return;
            }
            
            
            visitados[aresta->getTargetId()] = true; 
            dfsaux(this->getNode(aresta->getTargetId()), idTarget, visitados);
            if (visitados[idTarget] == true)
            {
                return;
            }
            aresta = aresta->getNextEdge();
        }
        aresta = aresta->getNextEdge();
    }
}
//Funcao recursiva onde, a partir de idSource, fazemos o caminho para procurar target dando prioridade a profundidade
bool Graph::depthFirstSearch(int idSource, int idTarget)
{
    vector<bool> visitados(this->getOrder(), false);

    if (!searchNode(idSource) || !searchNode(idTarget))
    {
        cout << "idSource ou idTarget nao existe no grafo!" << endl;
        return false;
    }

    Node *no = this->getNode(idSource);
    Edge *aresta = no->getFirstEdge();
    visitados[idSource] = true;
    dfsaux(no, idTarget, visitados);
    if (visitados[idTarget] == true)
        return true;
    return false;
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

/* Graph *getVertexInduced(int *listIdNodes)
{
} */

void Graph::agmPrim(int idSource)
{
    Node *p = this->getNode(idSource);

    if (p == nullptr)
    {
        cout << "Noh inicial nao encontrado!" << endl;
        return;
    }

    while (p->getInDegree() == 0)
    {
        if (p->getId() == idSource)
        {

            p = getFirstNode();
        }
        else
        {
            p = p->getNextNode();
        }
    }

    idSource = p->getId();

    Node *root_node = getNode(idSource);
    vector<Node *> list;

    Graph *prim_tree = new Graph(order, directed, weighted_edge, weighted_node);

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

    if (order == 0)
    {
        cout << "ARVORE VAZIA!" << endl;
        return;
    }

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

void Graph::greedRandom(float *alphaValues, int numAlpha, int repetitions)
{
    for (int i = 0; i < numAlpha; i++)
    {
        float alpha = alphaValues[i];

        cout << "Alpha: " << alpha << endl;

        for (int j = 0; j < repetitions; j++)
        {
        }
    }
}

void Graph::greedRactiveRandom()
{
}

void Graph::printGrafoDot(ofstream &file)
{
    if (file.is_open())
    {
        Edge *aresta;
        Node *node = this->first_node;
        Node *no = this->first_node;
        int *map = new int[this->order];
        bool *visitados = new bool[this->order];
        int i = 0;

        while (node != nullptr)
        {
            visitados[i] = false;
            map[i] = node->getId();
            i++;
            node = node->getNextNode();
        }

        if (this->directed == 1)
        {
            file << "digraph { \n";
        }
        else
        {
            file << "graph { \n";
        }

        // Caso o n?? tenha peso
        if (this->weighted_node == 1)
        {
            while (no != nullptr)
            {
                file << "   " << no->getId() << " [weight = " << no->getWeight() << "] \n";
                no = no->getNextNode();
            }
            no = this->first_node;
        }
        no = this->first_node;

        while (no != nullptr)
        {
            aresta = no->getFirstEdge();
            visitados[mapping(map, no->getId())] = true;
            while (aresta != nullptr)
            {
                if (!visitados[mapping(map, aresta->getTargetId())])
                {
                    if (this->directed == 1)
                    {
                        file << "   " << no->getId() << "->" << aresta->getTargetId();
                    }
                    else
                    {
                        file << "   " << no->getId() << "--" << aresta->getTargetId();
                    }
                    if (this->weighted_edge == 1)
                    {
                        file << " [label=" << aresta->getWeight() << ",weight=" << aresta->getWeight() << "]";
                    }
                    file << "\n";
                }
                aresta = aresta->getNextEdge();
            }
            no = no->getNextNode();
        }
        file << "}\n"
             << endl;

        cout << "Grafo armazanado no arquivo Guloso.txt " << endl;
    }
    else
    {
        cout << "Falha ao abrir o arquivo" << endl;
    }
}

Graph *Graph::greed(Graph *graph)
{
    //estrutura inicial
    vector<int> noOrigem;
    vector<int> noDestino;
    vector<float> arestaPeso;
    vector<float> arestaPesoAux;
    vector<int> aux;
    int size = 0;

    //estrutura resolu????o

    //interadores
    Node *no = graph->getFirstNode();
    Edge *aresta = no->getFirstEdge();
    int co = 0;
    while (no != nullptr)
    {

        while (aresta != nullptr)
        {
            noOrigem.push_back(no->getId());
            noDestino.push_back(aresta->getTargetId());
            arestaPeso.push_back(aresta->getWeight());
            aresta = aresta->getNextEdge();
            co++;
        }
        no = no->getNextNode();
        if (no != nullptr)
        {
            aresta = no->getFirstEdge();
        }
    }

    ////////////////////////ordenando os trem/////////////////////////
    Graph *grafoKruskal = new Graph(this->order, this->directed, this->weighted_edge, this->weighted_node);
    noOrigem.push_back(-1);
    noDestino.push_back(-1);

    std::vector<int>::iterator it1;
    std::vector<int>::iterator it2;

    arestaPesoAux = arestaPeso;

    sort(arestaPesoAux.begin(), arestaPesoAux.end());
    unique(arestaPesoAux.begin(), arestaPesoAux.end());
    int loops = 0;

    for (int i = 0; i < arestaPesoAux.size() - 2; i++)
    {
        for (int j = 0; j < arestaPeso.size() - 2; j++)
        {
           
                
                if (arestaPesoAux[i] == arestaPeso[j])
                {
                    if (loops == 0)
                    {
                        loops++;
                        aux.insert(aux.begin(), 1, noOrigem[j]);
                        aux.insert(aux.begin(), 1, noDestino[j]);
                        // aux.push_back(-1);
                        grafoKruskal->insertEdge(noOrigem[j], noDestino[j], arestaPeso[j]);
                    }
                    else
                    {

                        
                        it1 = find(aux.begin(), aux.end(), noOrigem.at(j));
                        it2 = find(aux.begin(), aux.end(), noDestino.at(j)); 
                        if (this->getOrder()*2 >= loops)
                        {
                            if (it1 != aux.end())
                            {

                            if (it2 != aux.end())
                            {   
                                // n??o adicionar nada pois j?? existe essa aresta ou op????o melhor
                                if (depthFirstSearch(noOrigem[j], noDestino[j]))
                                {
                                    grafoKruskal->insertEdge(noOrigem[j], noDestino[j], arestaPeso[j]);
                                    loops++;
                                }
                            }
                                else
                                {
                                    //cout << "Origem" << endl;
                                    // adicionar aresta pois s?? vertice da origem est?? presente na lista

                                    aux.insert(aux.begin(), 1, noDestino[j]);
                                    grafoKruskal->insertEdge(noOrigem[j], noDestino[j], arestaPeso[j]);
                                    loops++;
                                }
                            }
                            else
                            {
                                if (it2 != aux.end())
                                {
                                // cout << "destino" << endl;
                                    // adicionar aresta por apenas vertice de Destino estar presente na lista

                                    aux.insert(aux.begin(), 1, noOrigem[j]);
                                    grafoKruskal->insertEdge(noOrigem[j], noDestino[j], arestaPeso[j]);
                                    loops++;
                                }
                                else
                                {
                                // cout << "adicionando os dois" << endl;
                                    //adicionar ambos por nenhum dos dois estarem presentes
                                    aux.insert(aux.begin(), 1, noOrigem[j]);
                                    aux.insert(aux.begin(), 1, noDestino[j]);
                                    grafoKruskal->insertEdge(noOrigem[j], noDestino[j], arestaPeso[j]);
                                    loops++;
                                }
                        
                            }
                        }
                    }
                }
        }
    }

 /*    sort(arestaPeso.begin(), arestaPesoAux.end());
    for (int kaka = 0; kaka < arestaPeso.size(); kaka++)
    {
        cout << arestaPeso[kaka] << endl;
    }
    cout << endl; */

    std::ofstream saidaKruskal("Guloso.txt", std::ofstream::out);

    grafoKruskal->printGrafoDot(saidaKruskal);

    saidaKruskal.close();

    return grafoKruskal;
}
