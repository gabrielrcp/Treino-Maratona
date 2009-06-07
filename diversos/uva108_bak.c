#include <stdio.h>


/* MEMMORY / TIME LIMIT */
#define MAX 100

int n;
int soma[MAX][MAX][MAX][MAX];
int matriz[MAX][MAX];

int main()
{
  int i, j, k, l;
  int max;
  while(scanf(" %d", &n) > 0)
    {
      for(i=0; i < n; i++)
	for(j=0; j < n; j++){
	  scanf(" %d", &(matriz[i][j]));
	  /*soma[i][j][0][0] = matriz[i][j];*/
	}

      for(k=0; k < n; k++)
	for(l=0; l < n; l++)
	  for(i=0; i + k < n; i++)
	    for(j=0; j + l < n; j++)
	      soma[i][j][k][l] = 0;
      
      max = matriz[0][0];

      for(k=0; k < n; k++)
	for(l=0; l < n; l++)
	  for(i=0; i + k < n; i++)
	    for(j=0; j + l < n; j++){
	      soma[i][j][k][l] = matriz[i][j] + soma[i+1][j][k-1][l] +
		soma[i][j+1][k][l-1] - soma[i+1][j+1][k-1][l-1];
	      if(soma[i][j][k][l] > max)
		max = soma[i][j][k][l];
	    }
      printf("%d\n", max);    
    }
  return 0;
}
