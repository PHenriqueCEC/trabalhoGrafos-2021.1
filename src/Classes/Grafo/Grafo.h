#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../Aresta/Aresta.h"
#include "../No/No.h"

using std::cout;
using std::endl;
using std::cin;

class Grafo {

    public:
        Grafo(int _numVertices, bool _direcionado, bool _arestaPonderada, 
              bool _pesoVertice);
        ~Grafo();
        int getOrdem();
        int getGrau();
        int getNumVertices();
        void inserirNo();
        void inserirArestaPonderada(int primeiroNo, int segundoNo, int peso);
        void inserirArestaNaoPonderada(int primeiroNo, int segundoNo);
        int checarVertice(int elemento);

    private:
        bool direcionado;
        bool arestaPonderada;
        bool pesoVertice;
        int grau;
        int ordem;
        int numVertices;
        // lista de nos

};

#endif
