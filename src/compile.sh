echo "Começando a compilação do projeto"

 g++ *.c* -o execGrupo1
if [ $? -eq 0 ];then 
   echo "compilado com sucesso!"
else
   echo "nao compilado"
fi