#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <vector>
#include "../Aresta/Aresta.h"

using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::vector;
using std::find;

class No {

	public:
        No(int _vertice);
		~No();

        int getGrau();
		void setGrau();
		int getVertice();
		void setVertice(int vertice);
		void addLista(int elemento);
		bool existeNaLista(int elemento);
		void imprimeLista();
		
	private:
		int grau; 
		int vertice;
		list <int> lista = {};
};

#endif
