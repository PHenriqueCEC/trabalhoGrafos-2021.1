#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "../Grafo/Grafo.h";

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;

class FileHandler {

	public:
        FileHandler(char **argv);
        ~FileHandler();
        Grafo* AbrirArquivo();

	private:
        char **argv;

};

#endif;
