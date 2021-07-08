#include "./Grafo.h"

Grafo::Grafo(int _numVertices, bool _direcionado, bool _arestaPonderada, 
             bool _pesoVertice)
{
    numVertices = _numVertices;
    direcionado = _direcionado;
    arestaPonderada = _arestaPonderada;
    pesoVertice = _pesoVertice;
    grau = 0;
    ordem = 0;

    for(int i = 0; i < numVertices; i++)
    {
        inserirNo();
    }

}

Grafo::~Grafo()
{
    
}

int Grafo::getOrdem()
{
    return ordem;
}

int Grafo::getGrau()
{
    return grau;
}

int Grafo::getNumVertices()
{
    return numVertices;
}

void Grafo:: inserirNo()
{
    //N sei como implementar isso ainda
}

void Grafo::inserirArestaPonderada(int primeiroNo, int segundoNo, int peso)
{

}

void Grafo::inserirArestaNaoPonderada(int primeiroNo, int segundoNo)
{
    
}