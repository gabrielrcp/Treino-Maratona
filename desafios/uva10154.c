/* UVA 10154 - Weights and Measures
   Accepted */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#define MAX 6000

typedef struct {
  int peso;
  int forca;
} Tart;

Tart tart[MAX];

int compara(const void *a, const void *b)
{
  if(((Tart *)a)->forca == ((Tart *)b)->forca)
    return(((Tart *)a)->peso - ((Tart *)b)->peso);
  return(((Tart *)a)->forca - ((Tart *)b)->forca);
}

int main()
{
  int n;
  int i, j, k, l;
  int maior;
  int *at, *ant, *tmp;
  int resp;

  n = 0;
  maior = 0;
  
  while(!feof(stdin)){
    if(scanf(" %d %d", &tart[n].peso, &tart[n].forca) != 2)
      break;
    if(tart[n].forca >= tart[n].peso){
      if(tart[n].forca > maior)
	maior = tart[n].forca;
      n++;
    }
  }

  qsort(tart, n, sizeof(Tart), compara);

  at  = (int *)malloc((maior+1)*sizeof(int));
  ant = (int *)malloc((maior+1)*sizeof(int));

  bzero(at, (maior+1)*sizeof(int));

  /*resp = 0;*/
  for(i = 0; i < n; i++){
    tmp = ant; ant = at; at = tmp;
    l = tart[i].forca - tart[i].peso;
    k = tart[i].peso;
    memcpy(at, ant, k * sizeof(int));
    for(j = 0; j <= l && k <= maior; j++){
      if(ant[j] + 1 > ant[k] && (ant[j] != 0 || j == 0))
	at[k] = ant[j] + 1;
      else
	at[k] = ant[k];
      /*
      if(at[k] > resp)
	resp = at[k];
      */
      k++;
    }
    if(k < maior)
      memcpy(at+k, ant+k, (maior-k)*sizeof(int));
  }
  
  resp = 0;
  for(i = 0; i <= maior; i++)
    if(at[i] > resp)
      resp = at[i];

  free(ant);
  free(at);

  printf("%d\n", resp);
  return 0;
}
