#include "./Aresta.h"

Aresta::Aresta(float _peso){
    peso = _peso;
}

Aresta::~Aresta()
{

}

float Aresta::getPeso()
{
    return peso;

}

Aresta* Aresta::getProxAresta()
{
    return proximo;
}

void Aresta::setProxAresta(Aresta* _aresta)
{
    proximo = _aresta;
}