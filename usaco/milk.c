/*
ID: gabriel9
LANG: C
TASK: milk
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  int preco;
  int aval;
} FAZENDEIRO;

int compara(FAZENDEIRO *f1, FAZENDEIRO *f2)
{
  /*
  FAZENDEIRO *f1, *f2;
  f1 = a;
  f2 = b;
  */
  if(f1->preco < f2->preco)
    return -1;
  else
    return 1;
}


int main()
{
  FAZENDEIRO faz[5000];
  int n, m, i;
  int tot;
  
  FILE *fin = fopen("milk.in", "r");
  FILE *fout = fopen("milk.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  fscanf(fin, " %d %d", &n, &m);
  for(i=0; i<m; i++)
    fscanf(fin, " %d %d", &(faz[i].preco), &(faz[i].aval));

  qsort(faz, m, sizeof(FAZENDEIRO), compara);

  tot = 0;
  for(i=0; n > 0; i++){
    if(faz[i].aval <= n){
      n -= faz[i].aval;
      tot += faz[i].preco * faz[i].aval;
    }
    else{
      tot += faz[i].preco * n;
      n = 0;
    }
  }
  fprintf(fout, "%d\n", tot);
  return 0;
}
