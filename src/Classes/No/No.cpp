#include "No.h"
#include <list>
#include <algorithm>

No::No()
{
  std::list <int> lista = {};
  lista.resize(0);
  int grau = 0;
    //  
}
No::~No()
{

}

int No::getGrau()
{
    return grau;
}

bool existeNaLista(int elemento)
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
    cout << "ce besta, ja tem o trem" << endl;
  }
}


// adicionar na lista