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
    cout << argv[1] << endl;
    cout << argv[2] << endl;
    cout << argv[3] << endl;
    cout << argv[4] << endl;
    cout << argv[5] << endl;
    cout << argv[6] << endl;
    cout << "entrei aqui" << argc << endl;
    cout << "ERRO! Verifique se os parametros foram passados corretamente!" << endl;
  }
  else 
  {
    FileHandler fileHandler(argv);
    Grafo *grafo = fileHandler.AbrirArquivo();  //Abre o arquivo de entrada e retorna um grafo
  }

  return 0;
}