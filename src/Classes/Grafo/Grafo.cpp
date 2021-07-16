#include "./Grafo.h"
#include "../No/No.h"

Grafo::Grafo(int _numVertices, bool _direcionado, bool _arestaPonderada, 
             bool _pesoVertice)
{
    numVertices = _numVertices;
    direcionado = _direcionado;
    arestaPonderada = _arestaPonderada;
    pesoVertice = _pesoVertice;
    grau = 0;
    ordem = 0;

    vector<No> vetNos = {};
    vetNos.resize(numVertices);

}

Grafo::~Grafo()
{
    
}

int Grafo::getOrdem()
{
    return ordem;
}



void Grafo::setGrauGrafo()
{
    for(int i = 0; i < vetNos.size(); i++)
    {
        grau = grau + vetNos[i].getGrau(); // talvez tenha um +1 no vetNos[i].getGrau()
    }                                      // a ser testado
}

int Grafo::getGrau()
{
    return grau;
}

int Grafo::getNumVertices()
{
    return numVertices;
}

bool Grafo::checarVertice(int elemento) 
{
    for(int i = 0; i < getNumVertices(); i++)
    { 
        if(vetNos.at(i).getVertice() == elemento)
        {
            return true;
        }
    }   
    return false;
}

int Grafo::pegarVertice(int elemento) 
{
    for(int i = 0; i < getNumVertices(); i++)
    { 
        if(vetNos.at(i).getVertice() == elemento)
        {
            return i;
        }
    }   
    return -1; //Vertice nao encontrado
}

void Grafo::inserirNo(int vertice)
{
    if(!checarVertice(vertice))
    {
        vetNos.push_back(No());
    }
}

void Grafo::inserirArestaPonderada(int primeiroNo, int segundoNo, int peso)
{

}

void Grafo::inserirArestaNaoPonderada(int primeiroNo, int segundoNo)
{
    if(direcionado == true)
    {
        int a = pegarVertice(primeiroNo); // a recebe a posicao
        
        if (a != -1)
        {

                if( primeiroNo == vetNos[a].getVertice())
                {
                    vetNos[a].addLista(segundoNo);
                }


        }
    }













    else
    {
        int a = pegarVertice (primeiroNo);
        for(int i = 0; i < vetNos.size() ; i++)
        {
            if( primeiroNo == vetNos[i].getVertice())
            {
                vetNos[i].addLista(segundoNo);
            }
        }
    }


}

void Grafo::imprimeGrafo()
{
    for(int i = 0; i < vetNos.size() ; i++)
    {
        std::cout << "indice: " << i << "Vertice: " << vetNos[i].getVertice() << " - ";
        vetNos[i].imprimeLista();
        cout << endl;
    }
}

