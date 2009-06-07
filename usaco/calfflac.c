/*
ID: gabriel9
LANG: C
TASK: calfflac
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20000
#define MP 2000

char entrada[MAX];
char saida[MAX];
int posori[MAX];

int ehalfa(char c)
{
  if(c >= 'A' && c <= 'Z')
    return 1;
  if(c >= 'a' && c <= 'z')
    return 1;
  return 0;
}

char min(char c)
{
  if(c >= 'A' && c <= 'Z')
    return c - 'A' + 'a';
  return c;
}


int  main()
{
  
  FILE *fin = fopen("calfflac.in", "r");
  FILE *fout = fopen("calfflac.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  int i, j, k, tam;
  int e, d, maior;

  tam = -1;
  do{
    saida[++tam] = getc(fin);
  }while(saida[tam] != EOF);
  tam++;

  j = 0;
  for(i=0; i<tam; i++){
    if(ehalfa(saida[i])){
      entrada[j] = min(saida[i]);
      posori[j] = i;
      j++;
    }
  }
  tam = j;


  e = d = 0;
  maior = 1;
  for(k=0; k<tam; k++){
    i = j = k;
    while(i >= 0 && j < tam){
      if(entrada[i] == entrada[j]){
	i--; j++;
      }
      else
	break;
    }
    if(j - i - 1 > maior){
      e = i+1; d = j-1;
      maior = j - i - 1;
    }

    i = k - 1;
    j = k;
    while(i >= 0 && j < tam){
      if(entrada[i] == entrada[j]){
	i--; j++;
      }
      else
	break;
    }
    if(j - i - 1 > maior){
      e = i+1; d = j-1;
      maior = j - i - 1;
    }
  }

  fprintf(fout, "%d\n", maior);
  fprintf(stderr, "%d %d %d\n", maior, e, d);
  for(i=posori[e]; i<=posori[d]; i++)
    putc(saida[i], fout);
  putc('\n', fout);
  return 0;
}
