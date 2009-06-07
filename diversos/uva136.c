/*
 * http://acm.uva.es/p/v1/136.html
 */

#include <stdio.h>

#define MAX 1500

int feios[MAX+1];
int conta;
int ultfeio[3] = {0, 0, 0};
int primos[3] = {2, 3, 5};


int main()
{
  int i, prox;
  int at, min;
  feios[0] = 1;
  conta = 1;
  while(conta < MAX)
    {
      at = feios[ultfeio[0]] * 2;
      while(at <= feios[conta-1]){
	ultfeio[0]++;
	at = feios[ultfeio[0]] * 2;
      }
      prox = 0;
      min = at;
      for(i=1; i<3; i++){
	at = feios[ultfeio[i]] * primos[i];
	while(at <= feios[conta-1]){
	  ultfeio[i]++;
	  at = feios[ultfeio[i]] * primos[i];
	}
	if(at < min){
	  prox = i;
	  min = at;
	}
      }
      feios[conta] = feios[ultfeio[prox]] * primos[prox];
      ultfeio[prox]++;
      conta++;
    }

  printf("The %d'th ugly number is %u.\n", MAX, feios[MAX-1]);
  /*
  for(i=0; i<conta; i++)
    printf("%d ", feios[i]);
  printf("\n");
  */
  return 0;
}
