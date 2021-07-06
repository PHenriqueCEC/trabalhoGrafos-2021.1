#include "./FileHandler.h";

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

Grafo *FileHandler::AbrirArquivo()
{
    string numVertices;
    bool ehDirecionado, temPesoAresta, temPesoNos;
    
    ifstream arq(argv[0]);
    getline(arq, numVertices); //Pega o numero de vertices
    
    ehDirecionado = verificaArgv(2);
    temPesoAresta = verificaArgv(3);
    temPesoNos = verificaArgv(4);

    Grafo *grafo = new Grafo(stoi(numVertices), ehDirecionado, temPesoAresta, temPesoNos);

    return grafo;
}

Grafo *FileHandler::SalvarArquivo(Grafo *grafo)
{
    ofstream saida;
    saida.open(argv[1]);

}
