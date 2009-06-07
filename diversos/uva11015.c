#include <stdio.h>

#define INFI 100000

char nome[30][15];
int matriz[30][30];
/*int dist[30][30];*/



int main()
{
  int n, m;
  int i, j, k;
  int at, min, imin;
  int h;

  for(h=1; ;h++)
    {
      scanf(" %d", &n);
      if(n == 0)
	break;
      scanf(" %d", &m);

      for(i=0; i<n; i++)
	for(j=0; j<n; j++)
	  matriz[i][j] = INFI;

      for(i=0; i<n; i++)
	scanf(" %s", nome[i]);

      while(m--){
	scanf(" %d %d %d", &i, &j, &k);
	i--; j--;
	matriz[i][j] = matriz[j][i] = k;
	/*dist[i][j] = dist[j][i] = k;*/
      }

      for(i=0; i<n; i++)
	matriz[i][i] = 0;

      for(k=0; k<n; k++)
	for(i=0; i<n; i++)
	  for(j=0; j<n; j++)
	    if(matriz[i][j] > matriz[i][k] + matriz[k][j])
	      matriz[i][j] = matriz[i][k] + matriz[k][j];

      imin = 0;
      min = 0;
      for(j=1; j<n; j++)
	min += matriz[0][j];

      for(i=1; i < n; i++){
	at = 0;
	for(j=0; j<n; j++)
	  at += matriz[i][j];
	if(at < min){
	  min = at;
	  imin = i;
	}
      }
      printf("Case #%d : %s\n", h, nome[imin]);
    }
  return 0;
}
