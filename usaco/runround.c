/*
ID: gabriel9
LANG: C
TASK: runround
*/

#include <stdio.h>
#include <string.h>

char usado[10];
char num[10];
int tam;

int preenche(unsigned long int n)
{
  if(n < 10){
    if(n == 0)
      return 0;
    tam = 1;
    num[0] = n;
    usado[n] = 1;
    return 1;
  }
  if(!preenche(n/10))
    return 0;

  n %= 10;
  num[tam] = n;
  if(usado[n] || n == 0)
    return 0;
  usado[n] = 1;
  tam++;
  return 1;
}


int serve(unsigned long int n)
{
  int p, conta;
  memset(usado, 0, 10*sizeof(char));
  if(!preenche(n))
    return 0;
  memset(usado, 0, 10*sizeof(char));

  conta = 1;
  p = 0;
  usado[p] = 1;
  while(1){
    p += num[p];
    p %= tam;
    if(usado[p]){
      if(p == 0 && conta == tam)
	return 1;
      else
	return 0;
    }
    usado[p] = 1;
    conta++;
  }
  fprintf(stderr, "Socorro!\n");
  return 1;
}



int main()
{
  unsigned long int n;
  
  FILE *fin = fopen("runround.in", "r");
  FILE *fout = fopen("runround.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  fscanf(fin, "%lud", &n);
  while(!serve(++n));

  fprintf(fout, "%ld\n", n);
  return 0;
}
