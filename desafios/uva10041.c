/* Vito's Family  */
/* UVA 10041 */
/* Accepted */

#include <stdio.h>
#include <stdlib.h>

#define MAX 500

int vetor[MAX];
int n;

int compara(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}


int calcula(int p)
{
  int i, s = 0;
  for(i=0; i<n; i++)
    
      if(p > vetor[i])
	s += p - vetor[i];
      else
	s += vetor[i] - p;
  return s;   
}

int mediana()
{
  int t;
  int x, y;
  if(n % 2 == 1)
    return calcula(vetor[n/2]);
  else{
    t = vetor[n/2-1] + vetor[n/2];
    t /= 2;
    x = calcula(t);
    y = calcula(t+1);
    if(x < y)
      return x;
    else
      return y;
  }
}

int main()
{
  int casos;
  int i;

  scanf(" %d", &casos);
  while(casos--)
    {
      scanf(" %d", &n);
      for(i=0; i < n; i++)
	scanf(" %d", vetor+i);
      qsort(vetor, n, sizeof(int), compara);
      printf("%d\n", mediana());
    }
  return 0;
}
