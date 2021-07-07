#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::endl;
using std::cin;

class Aresta {

	public:
        Aresta(float _peso);
		~Aresta();
		Aresta* getProxAresta();
		void setProxAresta(Aresta* _aresta);
		float getPeso();

	private:
		int peso;					
		Aresta* proximo;

};

#endif
