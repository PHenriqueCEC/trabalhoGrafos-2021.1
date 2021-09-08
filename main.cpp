#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <utility>
#include <tuple>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include "Graph.h"
#include "Node.h"
#include <vector>

using namespace std;

Graph *leitura(ifstream &input_file, int directed, int weightedEdge, int weightedNode)
{

    //Variáveis para auxiliar na criação dos nós no Grafo
    int idNodeSource;
    int idNodeTarget;
    int order;

    //Pegando a ordem do grafo
    input_file >> order;

    //Criando objeto grafo
    Graph *graph = new Graph(order, directed, weightedEdge, weightedNode);

    //Leitura de arquivo

    if (!graph->getWeightedEdge() && !graph->getWeightedNode())
    {

        while (input_file >> idNodeSource >> idNodeTarget)
        {

            graph->insertEdge(idNodeSource, idNodeTarget, 0);
        }
    }
    else if (graph->getWeightedEdge() && !graph->getWeightedNode())
    {

        float edgeWeight;

        while (input_file >> idNodeSource >> idNodeTarget >> edgeWeight)
        {

            graph->insertEdge(idNodeSource, idNodeTarget, edgeWeight);
        }
    }
    else if (graph->getWeightedNode() && !graph->getWeightedEdge())
    {

        float nodeSourceWeight, nodeTargetWeight;

        while (input_file >> idNodeSource >> nodeSourceWeight >> idNodeTarget >> nodeTargetWeight)
        {

            graph->insertEdge(idNodeSource, idNodeTarget, 0);
            graph->getNode(idNodeSource)->setWeight(nodeSourceWeight);
            graph->getNode(idNodeTarget)->setWeight(nodeTargetWeight);
        }
    }
    else if (graph->getWeightedNode() && graph->getWeightedEdge())
    {

        float nodeSourceWeight, nodeTargetWeight, edgeWeight;

        while (input_file >> idNodeSource >> nodeSourceWeight >> idNodeTarget >> nodeTargetWeight)
        {

            graph->insertEdge(idNodeSource, idNodeTarget, edgeWeight);
            graph->getNode(idNodeSource)->setWeight(nodeSourceWeight);
            graph->getNode(idNodeTarget)->setWeight(nodeTargetWeight);
        }
    }

    return graph;
}

Graph *leituraInstancia(ifstream &input_file, int directed, int weightedEdge, int weightedNode)
{

    //Variáveis para auxiliar na criação dos nós no Grafo
    int idNodeSource;
    int idNodeTarget;
    int order;
    int numEdges;
    int cluster;
    int aux=0;
    while (input_file >> cluster)
    {
        int auxOrigem = 0 , auxDestino = 0;
        if (aux == 0)
        {
            order++;
            cout << order << " " << cluster << endl;
            if (cluster == 0)
            {
                cout << cluster;
                aux = aux + 1;
                order--;
            }
        }

    }
    //Criando objeto grafo
    Graph *graph = new Graph(order, directed, weightedEdge, weightedNode);
    Node *nodeaux = new Node(-1);
    //Leitura de arquivo

    aux = 0; //Fala que é para sair do primeiro loop
    int source = 0,target = 0,contador = 0;
    while (input_file >> cluster)
    {
        int auxOrigem = 0 , auxDestino = 0;
        if (aux == 0)
        {
            if (cluster == 0)
            {
                aux = aux + 1;
            }
        }                    
        if (aux != 0)
        {
            contador++;
            if (contador % 3 == 1)
                source = cluster;
            else 
            {
                if (contador % 3 == 2)
                    target = cluster;
                else
                {
                    if (contador % 3 == 0)
                        graph->insertEdge(source, target, cluster);
                }
            }
        }


    }



int menu(Graph *graph)
{

    int selecao;

    cout << "MENU" << endl;
    cout << "----" << endl;
    cout << "[1] Subgrafo induzido por conjunto de vértices" << endl;
    cout << "[2] Caminho Mínimo entre dois vértices - Dijkstra" << endl;
    cout << "[3] Caminho Mínimo entre dois vértices - Floyd" << endl;
    cout << "[4] Árvore Geradora Mínima de Prim" << endl;
    cout << "[5] Árvore Geradora Mínima de Kruskal" << endl;
    cout << "[6] Imprimir caminhamento em largura" << endl;
    cout << "[7] Imprimir ordenacao topológica" << endl;
    cout << "[8] Busca em profundidade" << endl;
    cout << "[9] Algoritmo Guloso" << endl;
    cout << "[10] Algoritmo Guloso Randomizado " << endl;
    cout << "[11] Algoritmo Guloso Randomizado Reativo" << endl;
    cout << "[0] Sair" << endl;
    cout << graph->getOrder() << endl;
    cout << graph->getNumberEdges() << endl;
    cout << graph->getNumberNodes() << endl;
    cin >> selecao;

    return selecao;
}
void selecionar(int selecao, Graph *graph, ofstream &output_file)
{
    switch (selecao)
    {

    //Subgrafo induzido por um conjunto de vértices X;
    case 1:
    {
        cout << "Subgrafo induzido por um conjunto de vértices X " << endl;

        cout << "AINDA NAO IMPLEMENTADO!" << endl;

        break;
    }
        //Caminho mínimo entre dois vértices usando Dijkstra;
        /*case 2:
    {
        cout << "Caminho mínimo entre dois vértices usando Dijkstra" << endl;
        int idSource, idTarget;

        cout << "Digite o vertice inicial e o vertice final para a busca do caminho minimo!" << endl;
        cin >> idSource >> idTarget;

        cout << "A Distancia minima do vertice" << idSource << " ao vertice " << idTarget
             << "eh: " << graph->dijkstra(idSource, idTarget);

        output_file << "A Distancia minima do vertice" << idSource << " ao vertice " << idTarget
                    << "eh: " << graph->dijkstra(idSource, idTarget);

        break;
    }
*/
        //Caminho mínimo entre dois vértices usando Floyd;
    case 3:
    {
        cout << "Caminho mínimo entre dois vértices usando Floyd" << endl;
        int idSource, idTarget;

        cout << "Digite o vertice inicial e o vertice final para a busca do caminho minimo!" << endl;
        cin >> idSource >> idTarget;

        float distance = graph->floydMarshall(idSource, idTarget);

        cout << "A Distancia minima do vertice" << idSource << " ao vertice " << idTarget
             << "eh: " << distance << endl;

        output_file << "A Distancia minima do vertice" << idSource << " ao vertice " << idTarget
                    << "eh: " << distance << endl;

        break;
    }

        //AGM - Prim;
    case 4:
    {
        cout << "Árvore Geradora Mínima de Prim" << endl;
        int idSource;

        cout << "Digite o vertice inicial: " << endl;
        cin >> idSource;

        graph->agmPrim(idSource);

        break;
    }

        //AGM Kruskal;
    case 5:
    {

        cout << "Arovre Geradora Minima de Kruskal" << endl;

        cout << "AINDA NAO IMPLEMENTADO!" << endl;

        break;
    }

        //Busca em largura;
    case 6:
    {
        cout << "Busca em largura" << endl;
        int idSource, idTarget;

        cout << "Digite o vertice inicial e o vertice final para a busca em largura!" << endl;
        cin >> idSource >> idTarget;

        graph->breadthFirstSearch(idSource, idTarget, output_file);

        break;
    }
        //Ordenação Topologica;
    case 7:
    {
        cout << "Ordenação Topologica" << endl;

        cout << "AINDA NAO IMPLEMENTADO!" << endl;

        break;
    }

    case 8: //Busca em profundidade
    {

        cout << "Busca em profundidade" << endl;

        int idSource;
        int count = 0;

        cout << "Digite o No de origem: " << endl;
        cin >> idSource;

        //Lista de vertice
        vector<int> vertex_vector(graph->getOrder());

        vertex_vector = graph->depthFirstSearch(vertex_vector, idSource, graph->getOrder(),
                                                &count);
        break;
    }

    case 9:
    {
        cout << "Algoritmo Guloso" << endl;

        clock_t tInicio, tFim, tTotal;

        tInicio = clock();
        graph->greed();
        tFim = clock();

        tTotal = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));

        cout << "Tempo decorrido " << tTotal << "ms" << endl;

        break;
    }

    case 10:
    {
        cout << "Algoritmo Guloso Randomizado" << endl;
        int numAlpha = 1; //inicializa automaticamente com 1

        cout << "Numero de testes a serem realizados: " << endl;
        cin >> numAlpha;

        float *alphaValues = new float[numAlpha];

        cout << "Insira os valores de alpha: " << endl;

        for (int i = 0; i < numAlpha; i++)
        {
            cout << "Insira o valor " << (i + 1) << endl;
            cin >> alphaValues[i];
        }

        int repetitions = 1; //inicializa automaticamente com 1

        cout << "Insira o numero de repeticoes dos valores de Alpha: " << endl;
        cin >> repetitions;
        clock_t tInicio, tFim, tTotal;

        tInicio = clock();
        graph->greedRandom(alphaValues, numAlpha, repetitions);
        tFim = clock();

        tTotal = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));

        cout << "Tempo decorrido " << tTotal << "ms" << endl;

        break;
    }

    case 11:
    {
        cout << "Algoritmo Guloso Randomizado Reativo" << endl;

        clock_t tInicio, tFim, tTotal;

        tInicio = clock();
        graph->greedRactiveRandom();
        tFim = clock();

        tTotal = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));

        cout << "Tempo decorrido de " << tTotal << "ms" << endl;

        break;
    }

    default:
    {
        cout << " Error!!! invalid option!!" << endl;
        break;
    }
    }
}

int mainMenu(ofstream &output_file, Graph *graph)
{

    int selecao = 1;

    while (selecao != 0)
    {
        system("clear");
        selecao = menu(graph);

        if (output_file.is_open())
            selecionar(selecao, graph, output_file);

        else
            cout << "Unable to open the output_file" << endl;

        output_file << endl;
    }

    return 0;
}

int main(int argc, char const *argv[])
{

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 6)
    {

        cout << "ERROR: Expecting: ./<program_name> <input_file> <output_file> <directed> <weighted_edge> <weighted_node> " << endl;
        return 1;
    }

    string program_name(argv[0]);
    string input_file_name(argv[1]);

    string instance;
    if (input_file_name.find("v") <= input_file_name.size())
    {
        string instance = input_file_name.substr(input_file_name.find("v"));
        cout << "Running " << program_name << " with instance " << instance << " ... " << endl;
    }

    //Abrindo arquivo de entrada
    ifstream input_file;
    ofstream output_file;
    input_file.open(argv[1], ios::in);
    output_file.open(argv[2], ios::out | ios::trunc);

    Graph *graph;

    if (input_file.is_open())
    {

        graph = leituraInstancia(input_file, atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
    }
    else
        cout << "Unable to open " << argv[1];

    mainMenu(output_file, graph);

    //Fechando arquivo de entrada
    input_file.close();

    //Fechando arquivo de saída
    output_file.close();

    return 0;
}
