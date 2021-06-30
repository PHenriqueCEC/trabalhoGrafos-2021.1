#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::endl;
using std::cin;

int buscar(int subset[], int v)
{
  if(subset[v] == -1)
    return v;
  return buscar(subset, subset[v]);
}

// void unir(int subset, int v1, int v2)
// {
//   int v1_set = buscar(subset, v1);
//   int v2_set = buscar(subset, v1);

//   subset[v1_set] = v2_set;

// }

int tem_ciclo(int grafo[3][3])
{
  int * subset;
}

int main(int argc, char **argv)
{
 int grafos[3][3] = {{0, 0,0}, {0, 0, 0}, {0, 0, 0}}; 
 
  grafos[0][1] = 1;
  grafos[1][0] = 1;
  grafos[1][2] = 1;
  grafos[2][1] = 1;
  grafos[0][2] = 1;
  grafos[2][0] = 1;


  return 0;
  
}