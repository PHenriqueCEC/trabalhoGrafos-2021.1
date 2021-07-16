#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <list>
#include "../Aresta/Aresta.h"
#include "../No/No.h"

using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::vector;

class Grafo 
{

    public:
        Grafo(int _numVertices, bool _direcionado, bool _arestaPonderada, 
              bool _pesoVertice);
        ~Grafo();
        int getOrdem();
        int getGrau();
        void setGrauGrafo();
        int getNumVertices();
        int pegarVertice(int elemento);
        void inserirNo(int vertice);
        void inserirArestaPonderada(int primeiroNo, int segundoNo, int peso);
        void inserirArestaNaoPonderada(int primeiroNo, int segundoNo);
        bool checarVertice(int elemento);
        void imprimeGrafo();

    private:
        bool direcionado;
        bool arestaPonderada;
        bool pesoVertice;

        int grau;
        int ordem;
        int numVertices;

        vector<No> vetNos;

};

#endif
