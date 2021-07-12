#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"

class ListaEncad
{
public:
    ListaEncad();
    ~ListaEncad();

    void insereInicio(int val);
    void insereFinal(int val);
    void removeInicio();
    void removeFinal();
    bool busca(int val);
    void imprime();
    int contaNos();
    int contaNos2();
    int ocorrencias(int val);
    int primeiraocorrencia(int val);


private:
    No *primeiro; // ponteiro para o primeiro no
    int n;
    No *ultimo; // ponteiro para o ultimo no
};

#endif // LISTAENCAD_H_INCLUDED
