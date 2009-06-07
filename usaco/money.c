/*
ID: gabriel9
LANG: C
TASK: money
*/

#include <stdio.h>

#define MNCOINS 25
#define MAXN 10000

int moedas[MNCOINS];
long long int numpos[MNCOINS+1][MAXN+1];

int main()
{
  int v, n;
  int i, j, k;

  FILE *fin = fopen("money.in", "r");
  FILE *fout = fopen("money.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  fscanf(fin, " %d %d", &v, &n);

  for(i=0; i<v; i++)
    fscanf(fin, " %d", &moedas[i]);

  for(i=0; i<=v; i++)
    numpos[i][0] = 1;

  /*
  for(i=1; i<=n; i++)
    for(j=0; j < v; j++)
      for(k=0; k*moedas[j] <= i; k++)
	numpos[j+1][i] += numpos[j][i-k*moedas[j]];
  */

  for(i=1; i<=n; i++)
    for(j=0; j < v; j++)
      for(k=0; k<=j; k++)
	if(moedas[k] <= i)
	  numpos[j+1][i] += numpos[k+1][i-moedas[k]];

  fprintf(fout, "%lld\n", numpos[v][n]);
  return 0;
}
