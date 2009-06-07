/*
 * http://acm.uva.es/p/v1/103.html
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int dim[10];
} CAIXA;

CAIXA caixa[30];
int k ,n;
char cabe[30][30];

int guarda[30];

int compint(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

char caixacabe(int a, int b)
{
  int i;
  for(i=0; i<n; i++)
    if(caixa[a].dim[i] >= caixa[b].dim[i])
      return 0;
  return 1;
}

int seqmax(int ini)
{
  int max = 0, at;
  int i;

  if(guarda[ini] > 0)
    return guarda[ini];

  for(i=0; i<k; i++)
    if(cabe[i][ini]){
      at = seqmax(i);
      if(at > max)
	max = at;
    }

  guarda[ini] = ++max;
  return max;
}

void imprime(int ini)
{
  int i;
  if(guarda[ini] == 1)
    printf("%d", ini+1);
  else
    for(i=0; i<k; i++)
      if(cabe[i][ini] && guarda[i] == guarda[ini] - 1){
	imprime(i);
	printf(" %d", ini+1);
	return;
      }
}

int main()
{
  int i, j;
  int max;

  while(scanf(" %d %d", &k, &n) > 0){
    for(i=0; i<k; i++){
      for(j=0; j<n; j++)
	scanf(" %d", &(caixa[i].dim[j]));
      qsort(caixa[i].dim, n, sizeof(int), compint);
    }

    for(i=0; i<k; i++)
      for(j=0; j<k; j++)
	if(i == j)
	  cabe[i][j] = 0;
	else
	  cabe[i][j] = caixacabe(i, j);

    for(i=0; i<k; i++)
      guarda[i] = 0;

    for(i=0; i<k; i++)
      seqmax(i);

    max = 0;
    for(i=1; i < k; i++)
      if(guarda[i] > guarda[max])
	max = i;

    printf("%d\n", guarda[max]);
    imprime(max);
    printf("\n");
  }
  return 0;
}
