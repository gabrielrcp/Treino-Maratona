#include <stdio.h>

#define BASE 1000
#define DIGI 1000

typedef int tipo;

tipo vetor[1001][DIGI];


void multiplica(int n, int o, int d)
{
  int i;
  tipo result, resto;

  resto = 0;
  for(i=0; i < DIGI; i++){
    result = resto;
    result += vetor[o][i] * n;
    vetor[d][i] = result % BASE;
    resto = result / BASE;
  }
  if(resto != 0)
    fprintf(stderr, "Oooopppsss!\n");
}


void imprime(int n)
{
  int i;
  i = DIGI - 1;
  while(vetor[n][i] == 0 && i > 0)
    i--;
  
  printf("%d", vetor[n][i]);
  i--;
  for(; i >=0; i--){
    /* Ajeitar isso depois para qualquer base... */
    if(vetor[n][i] < 100)
      putchar('0');
    if(vetor[n][i] < 10)
      putchar('0');
    printf("%d", vetor[n][i]);
  }
  putchar('\n');
}


int main()
{
  int i, n;


  vetor[0][0] = 1;
  for(i=1; i<DIGI; i++)
    vetor[0][i] = 0;


  for(n = 1; n < 1001; n++){
    multiplica(n, n-1, n);
  }


  while(scanf(" %d", &n) != EOF)
    {
      printf("%d!\n", n);
      imprime(n);
    }
  return 0;
}
