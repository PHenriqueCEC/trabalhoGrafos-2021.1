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
    vetNos.resize(0);

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

void Grafo::inserirAresta(int primeiroNo, int segundoNo, int peso)
{
    /*
    if(direcionado == true)
    {
        int a = pegarVertice(primeiroNo); // a recebe a posicao
        
        if (a != -1)
        {
                if( primeiroNo == vetNos[a].getVertice())
                {
                    vetNos[a].addLista(segundoNo);
                }
                else
                {
                    cout << "deu ruim no InserirArresta" << endl;
                }
        }
        else
        {
            int b = vetNos.size();
            vetNos[b].setVertice(primeiroNo);
            vetNos[b].addLista(segundoNo);
        }
    }

    else
    {
        int a = pegarVertice (primeiroNo);
        for(int i = 0; i < vetNos.size(); i++)
        {
            if( primeiroNo == vetNos[i].getVertice())
            {
                vetNos[i].addLista(segundoNo);
            }
        }
    }
    */
}


void Grafo::inserirAresta(int primeiroNo, int segundoNo)
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
                else
                {
                    cout << "deu ruim no InserirAresta" << endl;
                }
        }
        else
        {
            int b = vetNos.size();
            vetNos[b].setVertice(primeiroNo);
            vetNos[b].addLista(segundoNo);
        }
    }

    else
    {
        int a = pegarVertice (primeiroNo), b = pegarVertice(segundoNo);
        
        if (a == -1)
        {
            vetNos.push_back(No());
            
            int a = vetNos.size() -1;
            
            vetNos[a].setVertice(primeiroNo);
            vetNos[a].addLista(segundoNo);    
        }
        if (b == -1)
        {
            vetNos.push_back(No());
            
            int b = vetNos.size() -1;
            
            vetNos[b].setVertice(primeiroNo);
            vetNos[b].addLista(segundoNo);    
        }
            vetNos[a].addLista(segundoNo);
            vetNos[b].addLista(primeiroNo);
    }

}

void Grafo::imprimeGrafo()
{
    for(int i = 0 ; i < vetNos.size() ; i++)
    {
        cout << "indice: " << i << "Vertice: " << vetNos[i].getVertice() << " - ";
        vetNos[i].imprimeLista();
        cout << endl;
    }
}
