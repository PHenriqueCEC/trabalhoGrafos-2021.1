#include "./Grafo.h";

Grafo::Grafo(int _numVertices, bool _direcionado, bool _arestaPonderada, 
             bool _verticePonderado)
{
    numVertices = _numVertices;
    direcionado = _direcionado;
    arestaPonderada = _arestaPonderada;
    verticePonderado = _verticePonderado;
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
