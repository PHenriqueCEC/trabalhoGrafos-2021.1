/**************************************************************************************************
 * Implementation of the TAD Graph
**************************************************************************************************/

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "Node.h"
#include <fstream>
#include <stack>
#include <list>
#include <vector>

using namespace std;

class Graph
{

    //Atributes
private:
    int order;
    int number_edges;
    bool directed;
    bool weighted_edge;
    bool weighted_node;
    Node *first_node;
    Node *last_node;

public:
    //Constructor
    Graph(int order, bool directed, bool weighted_edge, bool weighted_node);
    //Destructor
    ~Graph();
    //Getters
    int getOrder();
    int getNumberEdges();
    int getNumberNodes();
    bool getDirected();
    bool getWeightedEdge();
    bool getWeightedNode();
    Node *getFirstNode();
    Node *getLastNode();
    //Other methods
    void insertNode(int id);
    void insertEdge(int id, int target_id, float weight);
    void removeNode(int id);
    bool searchNode(int id);
    Node *getNode(int id);

    //methods phase1
    void topologicalSorting();
    void breadthFirstSearch(ofstream &output_file);
    Graph *getVertexInduced(ofstream &output_file);
    Graph *agmKuskal();
    void agmPrim(int idSource);
    float floydMarshall(int idSource, int idTarget);
    float dijkstra(int idSource, int idTarget);
    vector<int> depthFirstSearch(vector<int> vertexVector, int idSource, int graphOrder,
                                 int *count);
    vector<int> auxDepth(vector<int> vertexVector, int idNode, int *count);
    
    //methods phase1
    float greed();
    float greedRandom();
    float greedRactiveRandom();

private:
    //Auxiliar methods
    float **initializeMatrixFloydMarshall();
    Node *nodeNotExist(Node *p, Graph *graph);
    void printPrimTree();
    vector<int> initializeVertexVector(vector<int> &vertexVector);
    bool edgeBetweenIdAndTarget(int id, int targetId);

public:
    list<int> *adj;
    list<Node> *vertex;
};

#endif // GRAPH_H_INCLUDED
