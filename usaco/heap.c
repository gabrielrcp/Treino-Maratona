/*
ID: gabriel9
LANG: C
TASK: butter
*/

#include <stdio.h>
#include <stdlib.h>

int HEAP[800];
int tam;
int pos[800];


void insere(int n)
{
  int p, f;
  int t;

  f = tam;
  tam++;

  HEAP[f] = n;
  pos[HEAP[f]] = f;
  p = (f-1)/2;
  while(p >= 0 && HEAP[p] > HEAP[f]){
    t = HEAP[p];
    HEAP[p] = HEAP[f];
    HEAP[f] = t;
    pos[HEAP[p]] = p;
    pos[HEAP[f]] = f;
    f = p;
    p = (f-1)/2;
  }
}

int retira()
{
  int r = HEAP[0];
  int p, f, t;

  tam--;
  HEAP[0] = HEAP[tam];
  pos[r] = -1;
  pos[HEAP[0]] = 0;

  p = 0;
  while(2*p+1 < tam){
    f = 2*p+1;
    if(f + 1 < tam && HEAP[f] > HEAP[f+1])
      f++;
    if(HEAP[f] >= HEAP[p])
      return r;
    t = HEAP[p];
    HEAP[p] = HEAP[f];
    HEAP[f] = t;
    pos[HEAP[p]] = p;
    pos[HEAP[f]] = f;
    p = f;
  }
  return r;
}


void atualiza(int p)
{
  int f, t;

  while(2*p+1 < tam){
    f = 2*p+1;
    if(f + 1 < tam && HEAP[f] > HEAP[f+1])
      f++;
    if(HEAP[f] >= HEAP[p])
      break;
    t = HEAP[p];
    HEAP[p] = HEAP[f];
    HEAP[f] = t;
    pos[HEAP[p]] = p;
    pos[HEAP[f]] = f;
    p = f;
  }

  f = p;
  p = (f-1)/2;
  while(p >= 0 && HEAP[p] > HEAP[f]){
    t = HEAP[p];
    HEAP[p] = HEAP[f];
    HEAP[f] = t;
    pos[HEAP[p]] = p;
    pos[HEAP[f]] = f;
    f = p;
    p = (f-1)/2;
  }
}

int main()
{

  int i;

  tam = 0;
  do{
    scanf(" %d", &i);
    insere(i);
  }while(i != -1);

  for(i=0; i<tam; i++)
    printf("%d ", HEAP[i]);
  printf("\n");

  HEAP[3] = 200;
  atualiza(3);

  for(i=0; i<tam; i++)
    printf("%d ", HEAP[i]);
  printf("\n");

  while(tam > 0)
    printf("%d ", retira());
  printf("\n");
  return 0;
}
