/*
 * Problema: paises em guerra (da maratona)
 * Dessa vez, resolvido sem trapaca :P
 * Eu to usando o algoritmo de Floyd-Warshall, do jeito q tah no Usaco 2.4
 * Nao entendi direito porque que isso funciona, mas funciona :P
 * (lah no usaco eles dizem que se vc quer entender o pq, eh para olhar no
 * Cormen, Cap 26,  coisa que eu pretendo fazer assim que sobrar um tempo....)
 * Ele tah meio lento ainda... rodando os casos de teste dos juizes em 4, 5s no
 * meu pc... talvez de para melhorar nao repetindo o Floyd-Warshall pela 2a vez
 * e usando ou o que fizemos da 1a vez, ou o Dijkstra (que eh quase a mesma
 * coisa)
 */

#include <stdio.h>

int arestas[500][500];
int dist[500][500];
char existe[500][500];
int n, e;
int o, d;
char visitado[500];

int main()
{
  int i, j, k, h;
  int infi = 5000000;

  while(1){
    scanf(" %d %d", &n, &e);
    if(n == 0)
      return 0;

    for(i=0; i<n; i++)
      for(j=0; j<n; j++){
	arestas[i][j] = infi;
	dist[i][j] = infi;
	existe[i][j] = 0;
      }

    for(k=0; k<e; k++){
      scanf(" %d %d %d", &i, &j, &h);
      arestas[--i][--j] = h;
      existe[i][j] = 1;
    }


    for(k=0; k<n; k++)
      for(i=0; i<n; i++)
	for(j=0; j<n; j++)
	  existe[i][j] = existe[i][j] || (existe[i][k] && existe[k][j]);

    for(i=0; i<n; i++)
      for(j=i+1; j<n; j++)
	if(existe[i][j] && existe[j][i])
	  arestas[i][j] = arestas[j][i] = 0;

    scanf(" %d", &h);
    for(k=0; k<h; k++){
      scanf(" %d %d", &o, &d);
      o--; d--;
      if(!existe[o][d]){
	printf("Nao e possivel entregar a carta\n");
	continue;
      }
      else if(dist[o][d] < infi){
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
      printf("%d\n", dist[o][d]);
    }
    putchar('\n');
  }

  return 0;
}
