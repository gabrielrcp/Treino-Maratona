#include <stdio.h>


/*TIME LIMIT!!*/

#define MAX 100

int n;
int ant[MAX][MAX][MAX];
int at[MAX][MAX][MAX];
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
	}
      
      max = matriz[0][0];
	
      for(l=0; l < n; l++)
	for(i=0; i <  n; i++)
	  for(j=0; j < n; j++)
	    at[i][j][l] = 0;
	
      for(k = 0; k < n; k++){
	
	for(l=0; l < n; l++)
	  for(i=0; i <  n; i++)
	    for(j=0; j < n; j++)
	      ant[i][j][l] = at[i][j][l];

	for(l = 0; l < n; l++)
	  for(i=0; i + k < n; i++)
	    for(j=0; j + l < n; j++){
	      at[i][j][l] = matriz[i][j] + ant[i+1][j][l] +
		at[i][j+1][l-1] - ant[i+1][j+1][l-1];
	      if(at[i][j][l] > max)
		max = at[i][j][l];
	    }
      }
      printf("%d\n", max);    
    }
  return 0;
}
