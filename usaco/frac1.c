/*
ID: gabriel9
LANG: C
TASK: frac1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int num;
  int den;
} FRAC;

FRAC fracoes[161*161];


int compara(const void *p1, const void *p2)
{
  int d;
  FRAC *a = (FRAC *)p1;
  FRAC *b = (FRAC *)p2;

  d = a->den * b->den;
  return (a->num * d / a->den - b->num * d / b->den);
}

int naosimplifica(int men, int mai)
{
  int r;
  r = mai % men;
  while(r > 0){
    mai = men;
    men = r;
    r = mai % men;
  }
  return (men == 1);
}


int main()
{
  int i, j, k, n;
  FILE *fin = fopen("frac1.in", "r");
  FILE *fout = fopen("frac1.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  fscanf(fin, " %d", &n);

  fracoes[0].num = 0;
  fracoes[0].den = 1;
  k = 1;

  for(i=1; i<=n; i++)
    for(j=i; j<=n; j++){
      if(naosimplifica(i, j)){
	fracoes[k].num = i;
	fracoes[k].den = j;
	k++;
      }
    }
  qsort(fracoes, k, sizeof(FRAC), compara);
  
  for(i=0; i<k; i++)
    fprintf(fout, "%d/%d\n", fracoes[i].num, fracoes[i].den);
  

  return 0;
}
