#include <stdio.h>

int fat[13];

int main()
{
  int i;
  int n, k;
  int saida;

  fat[0] = 1;
  for(i=1; i<13; i++)
    fat[i] = fat[i-1] * i;
  

  while(scanf(" %d %d", &n, &k) != EOF)
    {
      saida = fat[n];
      for(i=0; i<k; i++){
	scanf(" %d", &n);
	saida /= fat[n];
      }
      printf("%d\n", saida);
    }
  return 0;
}
