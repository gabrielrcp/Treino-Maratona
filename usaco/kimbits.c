/*
ID: gabriel9
LANG: C
TASK: kimbits
*/

#include <stdio.h>
#include <stdlib.h>


unsigned int comb[32][32];

unsigned int n, l, i;
char saida[33];

FILE *fin, *fout;


void imprime(int ordem)
{

  if(ordem == n){
    fprintf(fout, "%s\n", saida);
    exit(0);
    return;
  }
  if(comb[n-ordem-1][l] >= i){
    saida[ordem] = '0';
    imprime(ordem+1);
    return;
  }
  i -= comb[n-ordem-1][l];
  if(l == 0)
    return;
  saida[ordem] = '1';
  l--;
  imprime(ordem+1);
  l++;
}

int main()
{
  int k, j;
    
  fin = fopen("kimbits.in", "r");
  fout = fopen("kimbits.out", "w");
  /*
  fin = stdin;
  fout = stdout;
  */

  fscanf(fin, " %u %u %u", &n, &l, &i);

  for(k=0; k<32; k++)
    comb[k][0] = comb[k][k] = 1;
  for(k = 1; k<32; k++)
    for(j = 1; j < k; j++)
      comb[k][j] = comb[k-1][j-1] + comb[k-1][j];
  for(k=0; k<=n; k++)
    for(j=1; j <= n; j++)
      comb[k][j] += comb[k][j-1];
  imprime(0);

  return 0;
}
