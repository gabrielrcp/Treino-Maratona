/*
ID: gabriel9
LANG: C
TASK: milk2
*/

#include <stdio.h>

#define MAX 1000000

int main()
{
      
  FILE *fin = fopen("milk2.in", "r");
  FILE *fout = fopen("milk2.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  int n;
  int maxm=0, maxi=0;
  int i, j;
  int ini, fim;
  char tempo[MAX];
  int inicio = -1, termino = 0;
  int ai=0, am=0;
  
  fscanf(fin, " %d", &n);

  for(i=0; i<MAX; i++)
      tempo[i] = 0;

  for(i=0; i<n; i++){
    fscanf(fin, " %d %d", &ini, &fim);
    if(inicio == -1 || ini < inicio)
      inicio = ini;
    if(fim > termino)
      termino = fim;
    for(j=ini; j<fim; j++)
      tempo[j] = 1;
  }

  for(i=inicio; i<termino; i++){
    if(tempo[i] == 1){
      am++;
      if(ai > maxi)
	maxi = ai;
      ai = 0;
    }
    else{
      ai++;
      if(am > maxm)
	maxm = am;
      am = 0;
    }
    /*
    j = i;
    while(j < termino && tempo[j] == 1)
      j++;
    if(j - i > maxm)
      maxm = j - i;

    j = i;
    while(j < termino && tempo[j] == 0)
      j++;
    if(j - i > maxi)
      maxi = j-i;
    */
  }

  if(ai > maxi)
    maxi = ai;
  if(am > maxm)
    maxm = am;


  fprintf(fout, "%d %d\n", maxm, maxi);
  
  return 0;
}

