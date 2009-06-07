/*
ID: gabriel9
LANG: C
TASK: hamming
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[64];
char usado[256];

int n, b, d;

int dist(int n1, int n2)
{
  int i, c=0;

  for(i=0; i<b; i++){
    if(n1 % 2 != n2 % 2)
      c++;
    n1 = n1 >> 1;
    n2 = n2 >> 1;
  }
  return c;
}

int testa(int t, int p)
{
  int i;
  for(i=0; i<p; i++){
    if(dist(t, num[i]) < d)
      return 0;
  }
  return 1;
}

int compara(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int main()
{
  int i;

  FILE *fin = fopen("hamming.in", "r");
  FILE *fout = fopen("hamming.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */

  fscanf(fin, " %d %d %d", &n, &b, &d);

  memset(num, 0, n*sizeof(int));
  memset(usado, 0, 256*sizeof(char));
  usado[0] = 1;

  i = 1;
  while(i < n){
    if(!(usado[num[i]]) && testa(num[i], i)){
      usado[num[i]] = 1;
      i++;
    }
    else
      num[i]++;
  }

  qsort(num, n, sizeof(int), compara);

  for(i=0; i<n; i++){
    if(i % 10 == 0 && i != 0)
      fprintf(fout, "\n");
    if(i % 10 == 0)
      fprintf(fout, "%d", num[i]);
    else
      fprintf(fout, " %d", num[i]);
  }
  fprintf(fout, "\n");
  /*printf("\n\n%d\n", dist(7, 8));*/
  return 0;
}
