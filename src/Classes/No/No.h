#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <algorithm>
#include "../Aresta/Aresta.h"

using std::cout;
using std::endl;
using std::cin;

class No {

	public:
        No();
		~No();
		std::list <int> lista = {};
        int getGrau();
		void addGrau();
		void addLista(int elemento);
		bool existeNaLista(int elemento);
		
	private:
		int grau;
};

#endif
