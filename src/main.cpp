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
    cout << "ERRO! Verifique se os parametros foram passados corretamente!" << endl;
    exit(1);
  }
    FileHandler fileHandler(argv);
    Grafo *grafo = fileHandler.AbrirArquivo();  //Abre o arquivo de entrada e retorna um grafo

  cout << "Grau do Grafo: " << grafo->getGrau() << " // Numero de Vertices: " << grafo->getNumVertices()  << endl;
  grafo->imprimeGrafo();

  return 0;
}