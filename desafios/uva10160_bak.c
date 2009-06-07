#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#if DEBUG
#define D(x) x
#else
#define D(x)
#endif


typedef struct _v_ {
  int v;
  void *at;
  struct _v_ *prox;
}Vizinho;


typedef struct __v{
  int v;
  int noviz;
  char ativo;
  int comp;
  Vizinho *prox; 
}Vert;

int n;

Vert vert[35];
int nocomp;

int melhor[35];
int tcomp[35];

char aki[35][35];
int faltamat,  melhorat;
int iniat, fimat;


int guloso(int ini, int fim)
{
  int saida, i;
  Vizinho *t;

  saida = 0;
  for(i = ini; i < fim; i++){
    if(vert[i].ativo){
      saida++;
      vert[i].ativo = 0;
      for(t = vert[i].prox; t != NULL; t = t->prox)
	((Vert *)t->at)->ativo = 0; 
    }
  }

  for(i = ini; i < fim; i++)
    vert[i].ativo = 1;
  
  return saida;
}

void tentar(int usei)
{
  Vert *v;
  Vizinho *t;
  int i;

  if(faltamat <= 1){
    if(melhorat > usei + faltamat)
      melhorat = usei + faltamat;
    return;
  }

  if(usei + 1 >= melhorat)
    return;


  for(i = iniat; i < fimat; i++){
    if(vert[i].ativo == 1){
      vert[i].ativo = 0;
      faltamat--;

      for(t = vert[i].prox; t != NULL; t = t->prox){
	v = (Vert *)t->at;
	if(v->ativo){
	  aki[v->v][usei] = 1;
	  v->ativo = 0;
	  faltamat--;
	}
      }

      tentar(usei + 1);
      
      for(t = vert[i].prox; t != NULL; t = t->prox){
	v = (Vert *)t->at;
	if(aki[v->v][usei]){
	  aki[v->v][usei] = 0;
	  v->ativo = 1;
	  faltamat++;
	}
      }
      vert[i].ativo = 1;
      faltamat++;

      if(usei + 1 >= melhorat)
	return;
    }
  }
}

int compara(const void *x, const void *y)
{
  Vert *a, *b;
  a = (Vert *)x;
  b = (Vert *)y;

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

  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      aki[i][j] = 0;

  while(scanf(" %d %d", &n, &m) && (n || m))
    {
      for(i=0; i<n; i++){
	vert[i].prox = NULL;
	vert[i].v = i;
	vert[i].comp = 0;
	vert[i].noviz = 0;
	vert[i].ativo = 1;
      }
      
      while(m--){
	scanf(" %d %d", &i, &j);
	i--; j--;
	
	novo = malloc(sizeof(Vizinho));
	novo-> v = i;
	novo->at = &vert[i];
	novo->prox = vert[j].prox;
	vert[j].prox = novo;
	vert[j].noviz++;

	novo = malloc(sizeof(Vizinho));
	novo-> v = j;
	novo->at = &vert[j];
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

      qsort(vert, n, sizeof(Vert), compara);

      j = 0;
      for(i=0; i < nocomp; i++){
	if(tcomp[i] <= 3)
	  melhor[i] = 1;
	else{
	  melhor[i] = guloso(j, j + tcomp[i]);
	  if(melhor[i] > tcomp[i]/2)
	    melhor[i] = tcomp[i]/2;
	  
	} 
	j += tcomp[i];
      }

      fimat = 0;
      for(i=0; i<nocomp; i++){
	faltamat = tcomp[i];
	melhorat = melhor[i];
	iniat = fimat;
	fimat += faltamat;
	tentar(0);
	melhor[i] = melhorat;
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
