#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../Aresta/Aresta.h"

using std::cout;
using std::endl;
using std::cin;

class No {

	public:
        No();
		~No();
        int getGrau();

	private:
		int grau;

};

#endif;
