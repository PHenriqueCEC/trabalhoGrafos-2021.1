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
              bool _verticePonderado);
        ~Grafo();
        int getOrdem();
        int getGrau();
        int getNumVertices();
        void inserirNo();

    private:
        bool direcionado;
        bool arestaPonderada;
        bool verticePonderado;
        int grau;
        int ordem;
        int numVertices;

};

#endif
