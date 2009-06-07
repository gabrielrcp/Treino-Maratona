/* Serving Stations */
/* UVA 10160 */
/* Accepted */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _v_ {
  int v;
  struct _v_ *prox;
}Vizinho;

typedef struct __v{
  int v;
  int noviz;
  int servido;
  char est;
  int comp;
  Vizinho *prox; 
}Vert;

int n;

Vert vert[35];
int indice[35];
int nocomp;

int melhor[35];
int tcomp[35];

int faltamat,  melhorat;

void tentar(int usei, int iniat, int fimat)
{
  Vizinho *t;
  int i, j, tirei;

  if(faltamat == 0){
    if(melhorat > usei)
      melhorat = usei;
    return;
  }

  if(usei + 1 >= melhorat) /* && faltamat > 0*/
    return;

  for(j = iniat; j < fimat; j++){
    i = indice[j];
    if(vert[i].est == 1 || vert[i].noviz <= 1)
      continue;
    
    tirei = 0;
    if(vert[i].servido == 0)
      tirei++;
    vert[i].servido++;

    for(t = vert[i].prox; t != NULL; t = t->prox){
      if(vert[t->v].servido == 0)
	tirei++;
      vert[t->v].servido++;
    }
    
    vert[i].est = 1;
    faltamat -= tirei;

    if(tirei > 0)
      tentar(usei + 1, j + 1, fimat);

    vert[i].est = 0;
    faltamat += tirei;

    vert[i].servido--;  
    for(t = vert[i].prox; t != NULL; t = t->prox){
      vert[t->v].servido--;
    }

    if(usei + 1 >= melhorat)
      return;
  }
}


int compara(const void *x, const void *y)
{
  Vert *a, *b;
  a = (Vert *)&vert[*(int *)x];
  b = (Vert *)&vert[*(int *)y];
  if(a->comp == b->comp)
    return b->noviz - a->noviz;
  return a->comp - b->comp;
}

void preeche(int ini)
{
  Vizinho *t;
  vert[ini].comp = nocomp;
  tcomp[nocomp-1]++;
  for(t = vert[ini].prox; t != NULL; t = t->prox)
    if(vert[t->v].comp == 0)
      preeche(t->v);
}


void destroi(Vizinho *v)
{
  if(v == NULL)
    return;
  destroi(v->prox); 
  free(v);
}


int main()
{
  int m;
  int i, j;
  Vizinho *novo;

  while(scanf(" %d %d", &n, &m) && (n || m))
    {
      for(i = 0; i < n; i++){
	vert[i].prox = NULL;
	vert[i].v = i;
	indice[i] = i;
	vert[i].comp = 0;
	vert[i].noviz = 0;
	vert[i].servido = 0;
	vert[i].est = 0;
      }
      
      while(m--){
	scanf(" %d %d", &i, &j);
	i--; j--;

	novo = malloc(sizeof(Vizinho));
	novo-> v = i;
	novo->prox = vert[j].prox;
	vert[j].prox = novo;
	vert[j].noviz++;

	novo = malloc(sizeof(Vizinho));
	novo-> v = j;
	novo->prox = vert[i].prox;
	vert[i].prox = novo;
	vert[i].noviz++;
	
      }
      
      nocomp = 0;
      for(i=0; i<n; i++)
	if(vert[i].comp == 0){
	  tcomp[nocomp] = 0;
	  nocomp++;
	  preeche(i);
	}

      qsort(indice, n, sizeof(int), compara);
      

      j = 0;
      for(i = 0; i < nocomp; i++){
	if(tcomp[i] > 3){
	  melhorat = tcomp[i]/2;
	  faltamat = tcomp[i];
	  tentar(0, j, j + tcomp[i]);
	  melhor[i] = melhorat;
	}
	else
	  melhor[i] = 1;
	j += tcomp[i];
      }
      
      j = 0;
      for(i=0; i<nocomp; i++)
	j += melhor[i];
      printf("%d\n", j);
    
      for(i=0; i<n; i++)
	destroi(vert[i].prox);
    }
  return 0;
}
