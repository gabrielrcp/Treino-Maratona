/*
ID: gabriel9
LANG: C
TASK: fence
*/

#include <stdio.h>
#include <stdlib.h>

int grau[500];
char grafo[500][500];
FILE *fin, *fout;

int PILHA[500*500];
int topo;

int circuito[500*500];
int pos;

int main()
{
  int f;
  int i, j, k;
  int tam;

  fin = fopen("fence.in", "r");
  fout = fopen("fence.out", "w");
  
  fscanf(fin, " %d", &f);

  tam = 0;
  for(k = 0; k < f; k++){
    fscanf(fin, " %d %d", &i, &j);
    i--; j--;
    grafo[i][j]++;
    grafo[j][i]++;
    grau[i]++;
    grau[j]++;
    if(i >= tam)
      tam = i+1;
    if(j >= tam)
      tam = j+1;
  }

  for(i=0; i<tam; i++)
    if(grau[i] % 2 == 1){
      PILHA[0] = i;
      break;
    }
  if(i == tam)
    for(i=0; i<tam; i++)
      if(grau[i] > 0){
	PILHA[0] = i;
	break;
      }

  pos = 0;
  topo = 1;

  while(topo > 0)
    {
      i = PILHA[--topo];
      if(grau[i] == 0){
	circuito[pos++] = i + 1;
	continue;
      }
      
      for(j=0; j<tam; j++)
	if(grafo[i][j] > 0){
	  PILHA[topo++] = i;
	  PILHA[topo++] = j;
	  grafo[i][j]--; grafo[j][i]--;
	  grau[i]--;
	  grau[j]--;
	  break;
	}
    }
  
  for(i=pos-1; i>=0; i--)
    fprintf(fout, "%d\n", circuito[i]);
  return 0;
}
