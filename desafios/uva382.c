/* UVA 382 - Perfection */
/* Accepted */

#include <stdio.h>

int soma(int n)
{
  int i, l, s=0;
  l = n/2;
  for(i=1; i<=l; i++)
    if(n % i == 0)
      s += i;
  return s;
}


int main()
{
  int n, s;

  printf("PERFECTION OUTPUT\n");
  for(scanf(" %d", &n); n != 0; scanf(" %d", &n))
    {
      printf("%5d  ", n);
      s = soma(n);
      if(s < n)
	printf("DEFICIENT\n");
      else if(s > n)
	printf("ABUNDANT\n");
      else
	printf("PERFECT\n");
    }
  printf("END OF OUTPUT\n");
  return 0;
}
