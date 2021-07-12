#include "No.h"
#include <list>
#include <algorithm>

No::No()
{
  lista.resize(0);
  int grau = 0;
}
No::~No()
{
    lista.~list();    
}

void No::addGrau()
{
    grau++;
    return; 
}

int No::getGrau()
{
    return grau;
} 
/*
void No::setVertice(int vertice)
{
  vertice = valor;
}
*/

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
    lista.resize(lista.max_size() + 1);
    lista.push_back(elemento);
    grau++;
  }
  else
  {
    std::cout << "ce besta, ja tem o trem " << elemento << std::endl;
  }
}

// adicionar na lista