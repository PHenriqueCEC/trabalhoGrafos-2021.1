#include <iostream>
#include "./Classes/FileHandler/FileHandler.h"
#include "./Classes/Grafo/Grafo.h"

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char **argv)
{

  if(argc != 6)
  {
    cout << argc << endl;
    cout << "entrei aqui" << argc << endl;
    cout << "ERRO! Verifique se os parametros foram passados corretamente!" << endl;
  }
  else 
  {
    FileHandler fileHandler(argv);
    Grafo *grafo = fileHandlerd.AbrirArquivo();  //Abre o arquivo de entrada e retorna um grafo
  }

  return 0;
}