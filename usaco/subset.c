/*
ID: gabriel9
LANG: C
TASK: subset
*/

#include <stdio.h>

int n;
int guarda[40][391];

int conta(int ini, int soma)
{
  int i, c;
  if(soma == 0){
    return 1;
  }
  else if(soma < 0)
    return 0;
    
  if(guarda[ini][soma] != -1)
    return guarda[ini][soma];

  c = 0;
  for(i=ini; i < n; i++)
    c += conta(i+1, soma-i);
  guarda[ini][soma] = c;
  return c;
}

int main()
{
  int i, j;
  int soma;
  /*
  FILE *fin = fopen("subset.in", "r");
  FILE *fout = fopen("subset.out", "w");
  */
  FILE *fin = stdin;
  FILE *fout = stdout;
  
  fscanf(fin, " %d", &n);
  soma = n*(n+1)/2;
  if(soma % 2 == 1){
    fprintf(fout, "0\n");
    return 0;
  }
  soma /= 2;

  for(i=0; i<40; i++)
    for(j=0; j<391; j++)
      guarda[i][j] = -1;

  fprintf(fout, "%d\n", conta(1, soma-n));
  return 0;
}
