/*
 * Problema: paises em guerra (da maratona)
 * Versao 2: usando um algoritmo para encontrar componentes fortemente
 * conexos em um grafo direcionado em tempo linear (o outro q eu coloquei
 * era O(n^3) ). Esse eu achei no Cormen, cap 23, p 488 do livro c/ capa
 *  vermelha da biblioteca.
 * Esse aqui ta rodando no meu PC em 0,5s (o anterior rodava em 3,5s).
 * Acho que deve tar dentro dos limites.
 * PS: se o anterior desse TL mesmo, entendi pq os kras ficaram taum
 * surpresos da gente ter feito essa merda, PQP, nunca que ia ter
 * pensado nisso (ainda nem tenho certeza que entendi...).
 */

#include <stdio.h>
#include <stdlib.h>

int arestas[500][500];
int dist[500][500];
char visitado[500];
int n, e;

typedef struct{
  int v;
  int tempofim;
} vertices;

vertices cheguei[500];
int infi = 5000000;
int tempo = 0;

void DFS(int p)
{
  int i;
  if(cheguei[p].v != -1)
    return;
  cheguei[p].v = p;
  for(i=0; i<n; i++)
    if(arestas[p][i] < infi && cheguei[i].v == -1)
      DFS(i);
  cheguei[p].tempofim = ++tempo;
}

int compara(const void *a, const void *b)
{
  return ((vertices *)b)->tempofim - ((vertices *)a)->tempofim;
}


void montar(int p)
{
  int i;
  if(visitado[p])
    return;
  visitado[p] = 1;
  for(i=0; i < n; i++)
    if(arestas[i][p] < infi && !visitado[i]){
      arestas[p][i] = arestas[i][p] = 0;
      montar(i);
    }
}

int main()
{
  int i, j, k, h;
  int o, d;

  while(1){
    scanf(" %d %d", &n, &e);
    if(n == 0)
      return 0;

    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
	arestas[i][j] = infi;
	dist[i][j] = infi;
      }
      cheguei[i].v = -1;
      visitado[i] = 0;
    }

    for(k=0; k<e; k++){
      scanf(" %d %d %d", &i, &j, &h);
      arestas[--i][--j] = h;
    }

    tempo = 0;
    for(i=0; i<n; i++)
      DFS(i);

    qsort(cheguei, n, sizeof(vertices), compara);

    for(i=0; i<n; i++)
      montar(cheguei[i].v);

    scanf(" %d", &h);
    for(k=0; k<h; k++){
      scanf(" %d %d", &o, &d);
      o--; d--;
      if(dist[o][o] == 0){
	if(dist[o][d] == infi)
	  printf("Nao e possivel entregar a carta\n");
	else
	  printf("%d\n", dist[o][d]);
	continue;
      }

      for(i=0; i<n; i++)
	visitado[i] = 0;
      dist[o][o] = 0;
      while(42){
	j = 0;
	while(j < n && visitado[j])
	  j++;
	for(i = j + 1; i < n; i++)
	  if((!visitado[i]) && dist[o][i] < dist[o][j])
	    j = i;
	if(j >= n || dist[o][j] == infi)
	  break;

	visitado[j] = 1;
	for(i=0; i<n; i++)
	  if(dist[o][i] > dist[o][j] + arestas[j][i])
	    dist[o][i] = dist[o][j] + arestas[j][i];
      }
      if(dist[o][d] == infi)
	printf("Nao e possivel entregar a carta\n");
      else
	printf("%d\n", dist[o][d]); 
    }
    putchar('\n');
  }

  return 0;
}
