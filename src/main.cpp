#include <iostream>
#include "./FileHandler/Filehandler.h"
#include "./Grafo/Grafo.h"

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char **argv)
{

  if(argc != 4)
  {
    cout << "ERRO! Verifique se os parametros foram passados corretamente!" << endl;
  }
  else 
  {
    FileHandler fileHandler(argv);
    Grafo *grafo = fileHandler.AbrirArquivo(); //Abre o arquivo de entrada e retorna um grafo
  }

  return 0;
}