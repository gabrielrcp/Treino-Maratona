/*
ID: gabriel9
LANG: C
TASK: sort3
*/

#include <stdio.h>
#include <stdlib.h>

int vetor[1000];
int conta[3] = {0, 0, 0};
int n;


int min(int a, int b)
{
  return (a < b ? a : b);
}


int main()
{
  int i, c, t;
  int n12=0, n13=0, n23=0, n21=0, n31=0, n32=0;
  int n;

  FILE *fin = fopen("sort3.in", "r");
  FILE *fout = fopen("sort3.out", "w");
  
  /*FILE *fin = stdin;*/
  /*FILE *fout = stdout;*/
  
  fscanf(fin, " %d", &n);
  for(i=0; i<n; i++){
    fscanf(fin, " %d", &vetor[i]);
    conta[vetor[i]-1]++;
  }

  for(i=0; i<conta[0]; i++){
    if(vetor[i] == 2)
      n12++;
    else if(vetor[i] == 3)
      n13++;
  }

  for(; i < conta[0] + conta[1]; i++){
    if(vetor[i] == 1)
      n21++;
    else if(vetor[i] == 3)
      n23++;
  }

  for(; i < conta[0] + conta[1] + conta[2]; i++){
    if(vetor[i] == 1)
      n31++;
    else if(vetor[i] == 2)
      n32++;
  }


  c = 0;

  t = min(n12, n21);
  c += t;
  n12 -= t;
  n21 -= t;

  t = min(n13, n31);
  c += t;
  n13 -= t;
  n31 -= t;

  t = min(n32, n23);
  c += t;
  n32 -= t;
  n23 -= t;
  
  c += n12;
  c += n21;
  c += n13;
  c += n31;
  /*
  c += n23;
  c += n32;
  */
  fprintf(fout, "%d\n", c);
  return 0;
}
