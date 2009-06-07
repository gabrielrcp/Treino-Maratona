/* Counting */
/* UVA 10198 */
/* Accepted */

#include <stdio.h>


#define DIGI 100
#define BASE 100000

int vetor[1001][DIGI];


void zera(int n)
{
  int i;
  for(i=0; i<DIGI; i++)
    vetor[n][i] = 0;
}


void soma(int d, int o)
{
  int i, r = 0;
  for(i=0; i<DIGI; i++){
    vetor[d][i] += vetor[o][i] + r;
    r = 0;
    if(vetor[d][i] > BASE){
      r = vetor[d][i] / BASE;
      vetor[d][i] = vetor[d][i] % BASE;
    }
  }
}

void imprime(int n)
{
  int i, b;
  i = DIGI - 1;
  while(i > 0 && vetor[n][i] == 0)
    i--;
  printf("%d", vetor[n][i]);
  i--;
  while(i >= 0){
    b = BASE / 10;
    while(vetor[n][i] < b && b > 0){
      putchar('0');
      b /= 10;
    }
    printf("%d", vetor[n][i]);
    i--;
  }
  putchar('\n');
}

void calcula(int n)
{
  zera(n);
  soma(n, n - 1);
  soma(n, n - 1);
  soma(n, n - 2);
  soma(n, n - 3);
}

int main()
{
  int n;
  zera(0);
  zera(1);
  vetor[1][0] = 2;
  zera(2);
  vetor[2][0] = 5;
  zera(3);
  vetor[3][0] = 13;

  for(n = 4; n < 1001; n++)
    calcula(n);

  while(scanf(" %d", &n) != EOF)
    imprime(n);
  return 0;
}
