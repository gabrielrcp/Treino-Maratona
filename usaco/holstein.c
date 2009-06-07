/*
ID: gabriel9
LANG: C
TASK: holstein
*/

#include <stdio.h>
#include <string.h>

int v, g;

int req[25];
int mat[15][25];

char usado[15];


int suficiente(int num, int ini)
{
  int i, j;

  if(num == 0){
    for(i=0; i<v; i++)
      if(req[i] > 0)
	return 0;
    return 1;
  }

  for(i=ini; i<g; i++){
    usado[i] = 1;
    for(j=0; j<v; j++)
      req[j] -= mat[i][j];
    if(suficiente(num-1, i+1))
      return 1;
    for(j=0; j<v; j++)
      req[j] += mat[i][j];
    usado[i] = 0;
  }
  return 0;
}

int main()
{
  int i, j;
  int min;
  
  FILE *fin = fopen("holstein.in", "r");
  FILE *fout = fopen("holstein.out", "w");
  
  /*FILE *fin = stdin;*/
  /*FILE *fout = stdout;*/
  
  fscanf(fin, " %d", &v);
  for(i=0; i<v; i++)
    fscanf(fin, " %d", &req[i]);
  fscanf(fin, " %d", &g);

  for(i=0; i<g; i++)
    for(j=0; j<v; j++)
      fscanf(fin, " %d", &mat[i][j]);

  memset(usado, 0, 15*sizeof(char));

  min = 1;
  while(!suficiente(min, 0))
    min++; 

  fprintf(fout, "%d", min);
  for(i=0; i<g; i++)
    if(usado[i])
      fprintf(fout, " %d", i+1);
  putc('\n', fout);

  return 0;
}
