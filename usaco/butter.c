/*
ID: gabriel9
LANG: C
TASK: butter
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
  struct _no *prox;
  int vert;
  int peso;
} No;

int nocows[800]; /* numero de vacas no pasto i */
int dist[800][800];
No al[800];

int HEAP[800];
int tam;
int pos[800];


void insere(int n, int o)
{
  int p, f;
  int t;

  f = tam;
  tam++;

  HEAP[f] = n;
  pos[HEAP[f]] = f;
  p = (f-1)/2;
  while(p >= 0 && dist[o][HEAP[p]] > dist[o][HEAP[f]]){
    t = HEAP[p];
    HEAP[p] = HEAP[f];
    HEAP[f] = t;
    pos[HEAP[p]] = p;
    pos[HEAP[f]] = f;
    f = p;
    p = (f-1)/2;
  }
}

int retira(int o)
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
    if(f + 1 < tam && dist[o][HEAP[f]] > dist[o][HEAP[f+1]])
      f++;
    if(dist[o][HEAP[f]] >= dist[o][HEAP[p]])
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


void atualiza(int p, int o)
{
  int f, t;

  while(2*p+1 < tam){
    f = 2*p+1;
    if(f + 1 < tam && dist[o][HEAP[f]] > dist[o][HEAP[f+1]])
      f++;
    if(dist[o][HEAP[f]] >= dist[o][HEAP[p]])
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
  while(p >= 0 && dist[o][HEAP[p]] > dist[o][HEAP[f]]){
    t = HEAP[p];
    HEAP[p] = HEAP[f];
    HEAP[f] = t;
    pos[HEAP[p]] = p;
    pos[HEAP[f]] = f;
    f = p;
    p = (f-1)/2;
  }
}


int calcula(int o, int p)
{
  int i, soma = 0;
  for(i=0; i<p; i++)
    if(nocows[i] > 0)
      soma += nocows[i]*dist[i][o];
  return soma;
}

int main()
{
  int n, p, c;
  int i, j, k, d;
  int infi = 200000;
  No *temp;
  int min;

  FILE *fin = fopen("butter.in", "r");
  FILE *fout = fopen("butter.out", "w");
  
  fscanf(fin, " %d %d %d", &n, &p, &c);

  for(i=0; i<n; i++){
    fscanf(fin, " %d", &j);
    nocows[--j]++;
  }

  for(i=0; i < p; i++)
    al[i].prox = NULL;
  

  for(k = 0; k < c; k++){
    fscanf(fin, " %d %d %d", &i, &j, &d);
    i--; j--;
    temp = (No *)malloc(sizeof(No));
    temp->vert = j;
    temp->peso = d;
    temp->prox = al[i].prox;
    al[i].prox = temp;

    temp = (No *)malloc(sizeof(No));
    temp->vert = i;
    temp->peso = d;
    temp->prox = al[j].prox;
    al[j].prox = temp;
  }

  for(i=0; i<p; i++)
    for(j=0; j<p; j++)
      dist[i][j] = infi;

  /*
  for(i=0; i<p; i++){
    printf("%d: ", i);
    for(temp = al[i].prox; temp != NULL; temp = temp->prox)
      printf("%d ", temp->vert);
    printf("\n");
  }
  */

  for(k = 0; k < p; k++){
    if(nocows[k] == 0)
      continue;

    for(i = 0; i < p; i++)
      pos[i] = -1;

    dist[k][k] = 0;
    tam = 0;
    insere(k, k);

    while(tam > 0){
      i = retira(k);
      /*
      for(j=0; j<tam; j++)
	if(dist[k][HEAP[j]] < dist[k][i])
	  fprintf(stderr, "Opaaaaa!\n");
      */
      /*
      if(dist[k][i] == infi){
	fprintf(stderr, "Opaaaaaa!\n");
	break;
      }
      */
      for(temp = al[i].prox; temp != NULL; temp = temp->prox){
	j = temp->vert;
	if(dist[k][j] > dist[k][i] + temp->peso){
	  dist[k][j] = dist[k][i] + temp->peso;
	  if(pos[j] == -1)
	    insere(j, k);
	  else
	    atualiza(pos[j], k);
	}
      }
    }
  }
  /*
  for(i=0; i<p; i++)
    if(nocows[i] > 0)
      printf("Pasto %d: %d vacas\n", i, nocows[i]);
  */

  /*
  for(i=0; i<p; i++){
    if(nocows[i] == 0)
      continue;
    printf("%d: ", i);
    for(j=0; j<p; j++)
      printf("%3d ", dist[i][j]);
    printf("\n");
  }
  */
  min = calcula(0, p);
  /*printf("Pasto %d: %d\n", 0, min);*/
  for(i=1; i<p; i++){
    d = calcula(i, p);
    /*printf("Pasto %d: %d\n", i, d);*/
    if(d < min)
      min = d;
  }
  fprintf(fout, "%d\n", min);
  return 0;
}
