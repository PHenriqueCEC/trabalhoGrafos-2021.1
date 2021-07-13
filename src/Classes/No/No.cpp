#include "No.h"

No::No()
{
  lista.resize(0);
  int grau = 0;
}
No::~No()
{
    lista.~list();    
}

void No::setGrau()
{
    grau++;
    //return; 
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
  for (int n : lista) 
  {
    if(n == elemento)
      return true;
  }
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