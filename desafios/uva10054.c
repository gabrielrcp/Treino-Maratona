/* UVA 10054 - The Necklace
   Accepted */

#include <stdio.h>
#include <stdlib.h>


typedef struct _v{
  int v;
  struct _v *prox;
}Vert;

#define MAXCOR 50

Vert vert[MAXCOR];
int grau[MAXCOR];
char vis[MAXCOR];

void destroi(Vert *v)
{
  if(v == NULL)
    return;
  destroi(v->prox);
  free(v);
}

void adiciona(int i, int j)
{
  Vert *novo;
  novo = malloc(sizeof(Vert));
  novo->v = j;
  novo->prox = vert[i].prox;
  vert[i].prox = novo;
  grau[i]++;
}

void remover(int i, int j)
{
  Vert *v, *w;
  for(v = &vert[i]; v->prox != NULL; v = v->prox)
    if(v->prox->v == j)
      break;
  if(v->prox->v != j)
    return;
  w = v->prox;
  v->prox = w->prox;
  free(w);
  grau[i]--;
}

void enche(int i)
{
  Vert *v;
  if(vis[i])
    return;
  vis[i] = 1;
  for(v = vert[i].prox; v != NULL; v = v->prox)
    enche(v->v);
}

int pode()
{
  int i;
  for(i = 0; i < MAXCOR; i++)
    if(grau[i] % 2 == 1)
      return 0;
  i = 0;
  while(grau[i] == 0)
    i++;
  enche(i);
  for(i = 0; i < MAXCOR; i++)
    if(vis[i] == 0 && grau[i] > 0)
      return 0;
  return 1;
}

void imprime(int i)
{
  int j;
  while(grau[i] > 0){
    j = (vert[i].prox)->v;
    remover(i, j);
    remover(j, i);
    imprime(j);
    printf("%d %d\n", j+1, i+1);
  }
}

int main()
{
  int casos, n, h;
  int i, j;

  for(i = 0; i < MAXCOR; i++)
    vert[i].prox = NULL;

  scanf(" %d", &casos);
  for(h = 1; h <= casos; h++){
    for(i = 0; i < MAXCOR; i++){
      destroi(vert[i].prox);
      vert[i].prox = NULL;
      grau[i] = 0;
      vis[i] = 0;
    }
    scanf(" %d", &n);
    while(n--){
      scanf(" %d %d", &i, &j);
      i--; j--;
      adiciona(i, j);
      adiciona(j, i);
    }
    printf("Case #%d\n", h);
    if(!pode())
      printf("some beads may be lost\n");
    else{
      i = 0;
      while(grau[i] == 0)
	i++;
      imprime(i);
    }
    if(h != casos)
      putchar('\n');
  }
  return 0;
}
