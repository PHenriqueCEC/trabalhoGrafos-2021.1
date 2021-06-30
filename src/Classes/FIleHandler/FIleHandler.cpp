#include "./FileHandler.h";
#include <sstream>

FileHandler::FileHandler(char **argv)
{
    this->argv = argv;
}

FileHandler::~FileHandler()
{

}

Grafo* AbrirArquivo()
{
    ifstream entrada;

    //entrada.open(argv[0]); //Abre o arquivo de entrada que esta em argv[0]
}