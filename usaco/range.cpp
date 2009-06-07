/*
ID: gabriel9
LANG: C++
TASK: range
*/

#include <cstdio>

using namespace std;

char mapa[250][250][250];

inline char verifica(int i, int j, int t)
{
  t--;
  return (mapa[i][j][t] &&
	  mapa[i][j+1][t] &&
	  mapa[i+1][j][t] &&
	  mapa[i+1][j+1][t]);
}

int main()
{
  int n;
  int i, j, t;
  int conta;

  FILE *fin = fopen("range.in", "r");
  FILE *fout = fopen("range.out", "w");

  fscanf(fin, " %d", &n);

  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      do{
	mapa[i][j][0] = getc(fin);
	mapa[i][j][0] -= '0';
      }while(mapa[i][j][0] != 0 && mapa[i][j][0] != 1);
  fclose(fin);

  for(t = 1; t < n; t++){
    conta = 0;
    for(i = 0; i < n - t; i++)
      for(j = 0; j < n - t; j++)
	if(verifica(i, j, t))
	  {
	    conta++;
	    mapa[i][j][t] = 1;
	  }
    if(conta > 0)
      fprintf(fout, "%d %d\n", t + 1, conta);
    else
      break;
  }
  return 0;
}
