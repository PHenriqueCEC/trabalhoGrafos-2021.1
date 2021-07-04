#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "../Grafo/Grafo.h";

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

class FileHandler
{

public:
        FileHandler(char **argv);
        ~FileHandler();
        bool verificaArgv(int posicaoArgv);
        Grafo* AbrirArquivo(); //Retorna um grafo
        Grafo* SalvarArquivo(Grafo* grafo);    

private:
        char **argv;

};

#endif;
