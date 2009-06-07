/* The Priest Mathematician */
/* UVA 10254 */
/* Accepted */
/* Eu reescrevi completamente a versao que estava no paca antes
   Essa passa mais rapido, e o codigo esta muito mais limpo. */

#include <stdio.h>
#include <stdlib.h>

#define MAX4 10001
#define MAX3 300

#define BASE 100000

#define DEBUG 0
#if DEBUG
#define D(x) x
#else
#define D(x)
#endif

typedef struct{
  int digi;
  int *vetor;
}BigInt;

BigInt melhor3[MAX3];
BigInt melhor4[MAX4];
BigInt temp;

int kant;


void zerar(BigInt *b)
{
  int i;
  for(i = 0; i < b->digi; i++)
    b->vetor[i] = 0;
}

void soma(BigInt *d, BigInt *o)
{
  int i, r = 0;
  int min;
  min = ((d->digi < o->digi) ? d->digi : o->digi);
  for(i = 0; i < min; i++){
    d->vetor[i] += o->vetor[i] + r;
    r = d->vetor[i] / BASE;
    d->vetor[i] %= BASE;
  }
  for(; i < d->digi; i++){
    d->vetor[i] += r;
    r = d->vetor[i] / BASE;
    d->vetor[i] %= BASE;
  }
}

void somaesc(BigInt *b, int n)
{
  int i;
  for(i = 0; (i < b->digi && n != 0); i++){
    b->vetor[i] += n;
    n = b->vetor[i] / BASE;
    b->vetor[i] %= BASE;
  }
}

int compara(BigInt *a, BigInt *b)
{
  int i, j, min;

  i = a->digi;
  j = b->digi;
  i--; j--;

  min = ((i < j) ? i : j);


  while(i > min){
    if(a->vetor[i] != 0)
      return 1;
    i--;
  }

  while(j > min){
    if(b->vetor[j] != 0)
      return -1;
    j--;
  }

  while(i > 0){
    if(a->vetor[i] != b->vetor[i])
      return a->vetor[i] - b->vetor[i];
    i--;
  }

  return a->vetor[0] - b->vetor[0];  
}



void imprime(BigInt *a)
{
  int i, b;
  i = a->digi - 1;
  while(i > 0 && a->vetor[i] == 0)
    i--;
  printf("%d", a->vetor[i]);
  i--;
  while(i >= 0){
    b = BASE / 10;
    while(a->vetor[i] < b && b > 0){
      putchar('0');
      b /= 10;
    }
    printf("%d", a->vetor[i]);
    i--;
  }
  putchar('\n');
}

void calcula(int n)
{
  int k;

  k = kant;
  soma(melhor4+n, melhor4+k);
  soma(melhor4+n, melhor3+n-k);
  soma(melhor4+n, melhor4+k);
  
  k++;
  zerar(&temp);
  soma(&temp, melhor4+k);
  soma(&temp, melhor3+n-k);
  soma(&temp, melhor4+k);
  
  if(compara(&temp, melhor4+n) < 0){
    zerar(melhor4+n);
    soma(melhor4+n, &temp);
    kant = k;
  }
}


int main()
{
  int n;


  for(n=0; n<MAX3; n++){
    melhor3[n].digi = 50;
    melhor3[n].vetor = malloc(melhor3[n].digi*sizeof(int));
    zerar(melhor3+n);
  }
  for(n=0; n<MAX4; n++){
    melhor4[n].digi = 10;
    melhor4[n].vetor = malloc(melhor4[n].digi*sizeof(int));
    zerar(melhor4+n);
  }
  temp.digi = 10;
  temp.vetor = malloc(temp.digi*sizeof(int));

  for(n=1; n<MAX3; n++){
    soma(melhor3+n, melhor3+n-1);
    soma(melhor3+n, melhor3+n-1); 
    somaesc(melhor3+n, 1);
  }

  somaesc(melhor4+1, 1);
  somaesc(melhor4+2, 3);
  somaesc(melhor4+3, 5);
  somaesc(melhor4+4, 9);
  kant = 1;

  for(n=5; n<MAX4; n++)
    calcula(n);

  D(printf("Ultimo k=%d\n", kant);)

  while(scanf(" %d", &n) != EOF){
    D(if(n < MAX3) imprime(melhor3+n); putchar('\n');)
    imprime(melhor4+n);
  }
  return 0;
}
