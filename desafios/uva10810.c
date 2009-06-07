/* Ultra-Quicksort */
/* UVA 10810 */
/* Accepted  */

#include <stdio.h>

#define MAX 500000

typedef long long int tipo;

unsigned int vetor[MAX];
unsigned int aux[MAX];


tipo conta(int ini, int fim)
{
  tipo saida;
  int m;
  int i, j, k;

  if(fim - ini <= 1)
    return 0;

  m = (ini + fim) / 2;
  saida =  conta(ini, m);
  saida += conta(m, fim);

  i = ini;
  j = m;
  k = ini;
  while(i < m && j < fim)
    {
      if(vetor[i] <= vetor[j]){
	aux[k] = vetor[i];
	i++; k++;
      }
      else{
	aux[k] = vetor[j];
	saida += (tipo)(m - i);
	k++; j++;
      }
    }
  while(i < m){
    aux[k] = vetor[i];
    i++; k++;
  }
  while(j < fim){
    aux[k] = vetor[j];
    j++; k++;
  }
  for(i=ini; i<fim; i++)
    vetor[i] = aux[i];

  return saida;
}



int main()
{
  int i, n;

  while(42)
    {
      scanf(" %d", &n);
      if(n == 0)
	break;
      for(i=0; i<n; i++)
	scanf(" %u", vetor+i);
      printf("%lld\n", conta(0, n));
      /*
      for(i=0; i<n; i++)
	printf("%d ", vetor[i]);
      printf("\n");
      */
    }  
  return 0;
}
