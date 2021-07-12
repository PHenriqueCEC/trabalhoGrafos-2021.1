#include <iostream>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    primeiro = NULL;
    n = 0;
    ultimo = NULL;
}

ListaEncad::~ListaEncad()
{
    No *p = primeiro;
    while(p != NULL)
    {
        No *q = p->getProx();
        delete p;
        p = q;
    }
}

void ListaEncad::insereInicio(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(primeiro);
    if(primeiro == NULL)
        ultimo = p;
    primeiro = p;
    n++;
}

void ListaEncad::insereFinal(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(primeiro == NULL)
        primeiro = p;
    else
        ultimo->setProx(p);
    ultimo = p;
    n++;
}

void ListaEncad::removeInicio()
{
    if(primeiro == NULL)
        cout << "ERRO: Lista vazia" << endl;
    else
    {
        No *p = primeiro;
        primeiro = p->getProx();
        delete p;
        if(primeiro == NULL)
            ultimo = NULL;
        n--;
    }
}

void ListaEncad::removeFinal()
{
    if(primeiro == NULL)
        cout << "ERRO: Lista vazia" << endl;
    else
    {
        No *penultimo = primeiro;
        if(penultimo->getProx() == NULL)
        {
            delete ultimo;
            primeiro = ultimo = NULL;
        }
        else
        {
            while(penultimo->getProx() != ultimo)
                penultimo = penultimo->getProx();
            penultimo->setProx(NULL);
            delete ultimo;
            ultimo = penultimo;
        }
        n--;
    }
}

bool ListaEncad::busca(int val)
{
    for(No *p = primeiro; p != NULL; p = p->getProx()) 
    //for(int i = 0; i < n; i++)
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaEncad::primeiraocorrencia(int val)
{
  int posi = 0;

    for(No *p = primeiro; p != NULL; p = p->getProx()) 
    {
    //for(int i = 0; i < n; i++)
        posi++;
        if(p->getInfo() == val)
            return posi;
    }
    return -1;
}

int ListaEncad::ocorrencias(int val)
{
  int contador = 0;
  
    for(No *p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
          contador++;

    return contador;
}

void ListaEncad::imprime()
{
    cout << "Lista: ";
    for(No *p = primeiro; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout << endl;
}

int ListaEncad::contaNos()
{
    int cont = 0;
    for(No *p = primeiro; p != NULL; p = p->getProx())
        cont++;
    return cont;
}

int ListaEncad::contaNos2()
{
    return n;
}