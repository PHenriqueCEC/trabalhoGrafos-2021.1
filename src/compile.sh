echo "Começando a compilação do projeto"

cd ./Classes && g++ ./FileHandler/FileHandler.cpp ./Aresta/Aresta.cpp ./Grafo/Grafo.cpp ./No/No.cpp ../main.cpp -o ../execGrupo1
if [ $? -eq 0 ];then 
   echo "Compilado com sucesso! :)"
else
   echo "Nao compilado :("
fi