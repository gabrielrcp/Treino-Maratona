/*
ID: gabriel9
LANG: C
TASK: game1
*/

#include <stdio.h>

int tab[200];
int maxpt[100][100];
char melhor[100][100];

int maxpontos(int e, int d)
{
  int p1, p2;

  if(e == d){
    return tab[e];
  }
  else if(e > d){
    return 0;
  }

  if(melhor[e][d] != 0)
    return maxpt[e][d];

  if(e + 1 == d){
    if(tab[e] < tab[d]){
      melhor[e][d] = 1;
      maxpt[e][d] = tab[d];
      return tab[d];
    }
    else{
      melhor[e][d] = -1;
      maxpt[e][d] = tab[e];
      return tab[e];
    }
  }

  p1 = maxpontos(e+1, d);
  p2 = maxpontos(e, d-1);

  if(p1 < p2){
    melhor[e][d] = -1;
    if(melhor[e+1][d] < 0)
      maxpt[e][d] = tab[e] + maxpontos(e+2, d);
    else
      maxpt[e][d] = tab[e] + maxpontos(e+1, d-1);
  }
  else{
    melhor[e][d] = 1;
    if(melhor[e][d-1] < 0)
      maxpt[e][d] = tab[d] + maxpontos(e+1, d-1);
    else
      maxpt[e][d] = tab[d] + maxpontos(e, d-2);
  }
  return maxpt[e][d];
}

int main()
{
  int n;
  int i;
  FILE *fin = fopen("game1.in", "r");
  FILE *fout = fopen("game1.out", "w");

  fscanf(fin, " %d", &n);
  for(i=0; i<n; i++)
    fscanf(fin, " %d", tab+i);

  maxpontos(0, n-1);
  if(melhor[0][n-1] < 0)
    fprintf(fout, "%d %d\n", maxpontos(0, n-1), maxpontos(1, n-1));
  else
    fprintf(fout, "%d %d\n", maxpontos(0, n-1), maxpontos(0, n-2));

  return 0;
}
