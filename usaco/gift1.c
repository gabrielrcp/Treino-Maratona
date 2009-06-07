/*
ID: gabriel9
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nomes[16][16];
int n;


int indPessoa(char *nome)
{
  int i;
  for(i=0; i<n; i++)
    if(strcmp(nomes[i], nome) == 0)
      return i;
  return -1;
}

int main()
{
  
  FILE *fin = fopen("gift1.in", "r");
  FILE *fout = fopen("gift1.out", "w");
  
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  int  i;
  char atual[16];
  int dinheiro[16];
  int ia, nd, dar, dart;

  fscanf(fin, " %d", &n);
  for(i=0; i<n; i++){
    fscanf(fin, " %s", nomes[i]);
    dinheiro[i] = 0;
  }

  while( fscanf(fin, " %s", atual) > 0){
    ia = indPessoa(atual);
    fscanf(fin, " %d %d", &dart, &nd);
    dinheiro[ia] -= dart;
    if(nd > 0){
      dar = dart / nd;
      dinheiro[ia] += dart - (nd * dar);
      for(i=0; i<nd; i++){
	fscanf(fin, " %s", atual);
	/*fprintf(stderr, "%s ++ %d\n", atual, dar);*/
	dinheiro[indPessoa(atual)] += dar;
      }    
      /*fprintf(stderr, "\n");*/
    }
  }
  for(i=0; i<n; i++){
    fprintf(fout, "%s %d\n", nomes[i], dinheiro[i]);
  }
  return 0;
}

