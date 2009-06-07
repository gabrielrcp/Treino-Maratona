/*
ID: gabriel9
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <string.h>

int main()
{
  
  FILE *fin = fopen("beads.in", "r");
  FILE *fout = fopen("beads.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  int  i, j;
  char colar[400], bak[400];
  char tipo;
  int n, max, conta;
 

  fscanf(fin, " %d %s", &n, bak);

  max = 0;
  for(i=0; i<n; i++){
    conta = 0;
    strcpy(colar, bak);

    j = i;
    tipo = colar[j];
    while((colar[j] == tipo || colar[j] == 'w' || tipo == 'w') && colar[j] != 'p'){
      if(tipo == 'w' && colar[j] != 'w')
	tipo = colar[j];
      conta++;
      colar[j] = 'p';
      j++;
      j = j%n;
    }

    j = i - 1;
    if(j == -1) j = n - 1;
    tipo = colar[j];
    while((colar[j] == tipo || colar[j] == 'w' || tipo == 'w') && colar[j] != 'p'){
      if(tipo == 'w' && colar[j] != 'w')
	tipo = colar[j];
      conta++;
      colar[j] = 'p';
      j--;
      if(j == -1) j = n-1;
    }

    if(conta > max){
      max = conta;
    }
  }

  fprintf(fout, "%d\n", max);

  return 0;
}

