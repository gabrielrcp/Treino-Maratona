#include <stdio.h>

#define MAX 5001
#define DIGI 1000
#define BASE 1000000

int grande[MAX][DIGI];


void imprime(int n)
{
  int i, b;
  i = DIGI - 1;
  while(i > 0 && grande[n][i] == 0)
    i--;

  printf("%d", grande[n][i]);
  i--;
  while(i >= 0){
    b = BASE / 10;
    while(b > 1){
      if(grande[n][i] < b)
	putchar('0');
      else
	break;
      b /= 10;
    }
    printf("%d", grande[n][i]);
    i--;
  }
}

int main()
{
  int i, n;
  int resto;

  for(i=0; i<DIGI; i++){
    grande[0][i] = 0;
    grande[1][i] = 0;
  }
  grande[1][0] = 1;


  for(n = 2; n < MAX; n++){
    resto = 0;
    for(i=0; i<DIGI; i++){
      grande[n][i] = grande[n-1][i] + grande[n-2][i] + resto;
      resto = grande[n][i] / BASE;
      while(grande[n][i] >= BASE)
	grande[n][i] -= BASE;
    }
  }


  while(scanf(" %d", &n) != EOF){
    printf("The Fibonacci number for %d is ", n);
    imprime(n);
    putchar('\n');
  }


  return 0;
}
