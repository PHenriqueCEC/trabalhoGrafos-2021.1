#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::endl;
using std::cin;

class Grafo {

    public:
        Grafo(bool _direcionado, bool _arestaPonderada, bool _verticePonderado);
        ~Grafo();

    private:
        bool direcionado;
        bool arestaPonderada;
        bool verticePonderado;
        int grau;
        int ordem;

};

#endif
