/*
ID: gabriel9
LANG: C
TASK: agrinet
*/

#include <stdio.h>

char contado[100];
int dist[100];
int peso[100][100];

int main()
{
  int n, i, j;
  int numv;
  int total;
  int min;
  
  FILE *fin = fopen("agrinet.in", "r");
  FILE *fout = fopen("agrinet.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  fscanf(fin, " %d", &n);

  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      fscanf(fin, " %d", &peso[i][j]);

  numv = 1;
  contado[0] = 1;
  total = 0;
  for(i=1; i<n; i++)
    dist[i] = peso[0][i];

  while(numv < n){
    min = -1;
    for(i=1; i<n; i++)
      if(contado[i] == 0)
	if(min == -1 || dist[min] > dist[i])
	  min = i;
    /*
    if(min == -1)
      fprintf(stderr, "Ahhhh?!\n");
    */
    contado[min] = 1;
    total += dist[min];
    numv++;
    for(i=1; i<n; i++)
      if(contado[i] == 0 && peso[min][i] < dist[i])
	dist[i] = peso[min][i];
  }

  fprintf(fout, "%d\n", total);
  return 0;
}
