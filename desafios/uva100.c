/* The 3n+1 Problem */
/* UVA 100 */
/* Accepted */

#include <stdio.h>

#define MAX 1000000

int resp[MAX];

int calc(unsigned int n)
{

  int saida;

  if(n < MAX && resp[n] != -1)
    return resp[n];

  if(n % 2 == 0)
    saida = calc(n/2) + 1;
  else
    saida = (calc(3*n+1) + 1);

  if(n < MAX)
    resp[n] = saida;

  return saida;
}


int main()
{

  int i, j, t, k;
  int max;

  resp[1] = 1;
  for(i = 2; i < MAX; i++)
    resp[i] = -1;


  while(scanf(" %d %d", &i, &j) != EOF)
    {
      max = 1;
      printf("%d %d ", i, j);
      if(i > j){
	t = i;
	i = j;
	j = t;
      }
      for(k = i; k <= j; k++)
	if(calc(k) > max)
	  max = resp[k];
      printf("%d\n", max);
    }

  return 0;
}
