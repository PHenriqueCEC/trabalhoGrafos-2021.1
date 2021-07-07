echo "Começando a compilação do projeto"

cd ./Classes && g++ ./FileHandler/FileHandler.cpp ./Aresta/Aresta.cpp ./Grafo/Grafo.cpp ./No/No.cpp ../main.cpp -o ../main
if [ $? -eq 0 ];then 
   echo "compilado com sucesso!"
   .././main "./"
else
   echo "nao compilado"
fi