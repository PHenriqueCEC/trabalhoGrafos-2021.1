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
    char *aux = argv[posicaoArgv];
    
    if (*aux == '1')
        return true;
    else
        return false;
}

//Abre o arquivo de entrada e retorna um grafo
Grafo *FileHandler::AbrirArquivo()
{
    string numVertices, peso, primeiroNo, segundoNo;
    bool ehDirecionado, arestaPonderada, pesoVertice;

    ifstream arq(argv[1]);
    getline(arq, numVertices); //Pega o numero de vertices

    ehDirecionado = verificaArgv(3);
    arestaPonderada = verificaArgv(4);
    pesoVertice = verificaArgv(5);

    Grafo *grafo = new Grafo(stoi(numVertices), ehDirecionado, arestaPonderada, pesoVertice);


    if (arestaPonderada)
    {
        while(!arq.eof())
        {
            getline(arq, primeiroNo, ' ');
            getline(arq, segundoNo, ' ');
            getline(arq, peso, '\n');
            
            grafo->inserirAresta(stoi(primeiroNo), stoi(segundoNo), stoi(peso));
        }
    } 

    else 
    {
        while(!arq.eof())
        {
            getline(arq, primeiroNo, ' ');
            getline(arq, segundoNo, '\n');
            
            grafo->inserirAresta(stoi(primeiroNo), stoi(segundoNo));
        }

    }

    arq.close();

    return grafo;
}

void FileHandler::SalvarArquivo(Grafo *grafo)
{
    ofstream saida;
    saida.open(argv[2]);

    saida << grafo->getOrdem();

/*     No* no = grafo->getPrimeiroNo();

    while(no != NULL)
    {
        Aresta* aresta = no->getPrimeiraAresta();


    } */
}
