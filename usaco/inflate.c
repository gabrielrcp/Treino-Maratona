/*
ID: gabriel9
LANG: C
TASK: inflate
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
  int tempo;
  int pontos;
} CAT;

CAT cat[MAX];
int m, n;
int maxpontos[MAX+1];

int main()
{
  int i, t;
  FILE *fin = fopen("inflate.in", "r");
  FILE *fout = fopen("inflate.out", "w");

  
  fscanf(fin, " %d %d", &m, &n);
  for(i=0; i<n; i++)
    fscanf(fin, " %d %d", &cat[i].pontos, &cat[i].tempo);
  /*
  for(t=1; t<=m; t++)
    for(i=0; i<n; i++)
      if(t >= cat[i].tempo &&
	 cat[i].pontos + maxpontos[t-cat[i].tempo] > maxpontos[t])
	maxpontos[t] = cat[i].pontos + maxpontos[t-cat[i].tempo];
  */
  for(i=0; i<n; i++)
    for(t=cat[i].tempo; t<=m; t++)
      if(cat[i].pontos + maxpontos[t-cat[i].tempo] > maxpontos[t])
	maxpontos[t] = cat[i].pontos + maxpontos[t-cat[i].tempo];


  fprintf(fout, "%d\n", maxpontos[m]);
  return 0;
}
