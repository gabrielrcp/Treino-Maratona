/*
ID: gabriel9
LANG: C
TASK: numtri
*/

#include <stdio.h>

#define MAX 1000

int max(int a, int b){
  return ((a > b) ? a : b);
}

int main()
{
  int i, j, r,t;
  char num[MAX][MAX];
  int soma[MAX+1][MAX+1];

  
  FILE *fin = fopen("numtri.in", "r");
  FILE *fout = fopen("numtri.out", "w");
  
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  fscanf(fin, " %d", &r);


  for(i=0; i<r; i++)
    for(j=0; j<=i; j++){
      fscanf(fin, " %d", &t);
      num[i][j] = (char)t;
    }
  
  for(i=0; i<=r; i++)
    soma[r][i] = 0;
  
  for(i=r-1; i>=0; i--)
    for(j=0; j<=i; j++)
      soma[i][j] = num[i][j] + max(soma[i+1][j], soma[i+1][j+1]);
  
  fprintf(fout, "%d\n", soma[0][0]);

  return 0;
}
