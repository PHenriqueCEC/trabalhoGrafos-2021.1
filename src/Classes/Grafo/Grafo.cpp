#include "./Grafo.h";

Grafo::Grafo(bool _direcionado, bool _arestaPonderada, bool _verticePonderado)
{
    direcionado = _direcionado;
    arestaPonderada = _arestaPonderada;
    verticePonderado = _verticePonderado;
    grau = 0;
    ordem = 0;

}

Grafo::~Grafo()
{
    
}

