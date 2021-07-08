#include "./FileHandler.h"

FileHandler::FileHandler(char **argv)
{
    this->argv = argv;
}

FileHandler::~FileHandler()
{
}

bool FileHandler::verificaArgv(int posicaoArgv)
{
    if (argv[posicaoArgv] == "1")
        return true;
    else
        return false;
}

//Abre o arquivo de entrada e retorna um grafo
Grafo *FileHandler::AbrirArquivo()
{
    string numVertices;
    bool ehDirecionado, arestaPonderada, pesoVertice;
    int peso = 1;

    ifstream arq(argv[1]);
    getline(arq, numVertices); //Pega o numero de vertices

    ehDirecionado = verificaArgv(3);
    arestaPonderada = verificaArgv(4);
    pesoVertice = verificaArgv(5);

    Grafo *grafo = new Grafo(stoi(numVertices), ehDirecionado, arestaPonderada, pesoVertice);

    if (arestaPonderada)
    {
        //while()
            grafo->inserirArestaPonderada(peso);
    } 

    else 
    {
        //while()
            grafo->inserirArestaNaoPonderada();
    }

    return grafo;
}

void FileHandler::SalvarArquivo(Grafo *grafo)
{
    ofstream saida;
    saida.open(argv[2]);

    saida << grafo->getOrdem();
}
