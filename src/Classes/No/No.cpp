#include "No.h"

No::No(int _vertice)
{
  lista.resize(0);
  int vertice = _vertice; 
  int grau = 0;

}

No::~No()
{
  lista.~list();    
}

void No::setGrau()
{
  grau = lista.size();
}

int No::getGrau()
{
  return grau;
} 

void No::setVertice(int valor)
{
  vertice = valor;
}

int No::getVertice()
{
  return vertice;
}

bool No::existeNaLista(int elemento)
{ 
    if(find(lista.begin(), lista.end(), elemento) != lista.end()) //Se não funcionar, testar usando o método count
      return true;
    else 
      return false;
}

void No::addLista(int elemento)
{
  if(!existeNaLista(elemento))
  {
    //lista.resize(lista.max_size() + 1);
    lista.push_back(elemento);
    grau++;
    cout << "trem adicionado com sucesso " << elemento << endl;
  }
  else
  {
    cout << "ce besta, ja tem o trem " << elemento << endl;
  }
}

 void No::imprimeLista()
{
  for(auto print : lista)
    cout << print << " " << endl;
} 
