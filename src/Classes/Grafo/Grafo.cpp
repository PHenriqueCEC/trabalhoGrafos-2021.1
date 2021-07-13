#include "./Grafo.h"
#include "../No/No.h"

Grafo::Grafo(int _numVertices, bool _direcionado, bool _arestaPonderada, 
             bool _pesoVertice)
{
    numVertices = _numVertices;
    direcionado = _direcionado;
    arestaPonderada = _arestaPonderada;
    pesoVertice = _pesoVertice;
    grau = 0;
    ordem = 0;

    vector<No> vetNos = {};
    vetNos.resize(numVertices);

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

bool Grafo::checarVertice(int elemento) 
{
    for(int i = 0; i < getNumVertices(); i++)
    { 
        if(vetNos.at(i).getVertice() == elemento)
        {
            return true;
        }
    }   
    return false;
}

void Grafo::inserirNo(int vertice)
{
    if(!checarVertice(vertice))
    {
        vetNos.push_back();
        //vetNos.end.setVertice(vertice);
    }
}

void Grafo::inserirArestaPonderada(int primeiroNo, int segundoNo, int peso)
{

}

void Grafo::inserirArestaNaoPonderada(int primeiroNo, int segundoNo)
{
  
}

