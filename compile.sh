echo "Começando a compilação do projeto"

g++ *.c* -o execGrupo1
if [ $? -eq 0 ];then 
   echo "Compilado com sucesso! :)"
else
   echo "Nao compilado :("
fi