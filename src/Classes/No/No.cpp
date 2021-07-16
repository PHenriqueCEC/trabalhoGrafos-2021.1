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
    //int existe = find(lista.begin(), lista.end(), elemento);

    if(find(lista.begin(), lista.end(), elemento) != lista.end()) //Se não funcionar, testar usando o método count
      return true;
    else 
      return false;

/*
    if(existe != lista.end())
      return true; 
    else
      return false;    
*/
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
  for (int i ; i<lista.size() ; i++)
  {
  //  cout << lista[i] << " ";
  }
} 
