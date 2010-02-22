#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAXV 55
#define MAXE 5010

int grafo[MAXV];
int prox[MAXE];
int vert[MAXE];
int nume;
int n;

int dist[MAXV];

void _add_edge(int i, int j)
{
  int e = nume++;
  prox[e] = grafo[i];
  grafo[i] = e;
  vert[e] = j;
}

void add_edge(int i, int j)
{
  _add_edge(i, j);
  _add_edge(j, i);
}

int main()
{
  for(int h = 1; scanf(" %d", &n) && n; h++){
    int m, ini, p;
    scanf(" %d %d %d", &m, &ini, &p);
    ini--;
    nume = 0;
    memset(grafo, -1, sizeof grafo);
    while(m--){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      add_edge(i, j);
    }

    queue<int> Q;
    memset(dist, -1, sizeof dist);
    Q.push(ini);
    dist[ini] = 0;
    while(!Q.empty()){
      int i = Q.front();
      Q.pop();
      if(dist[i] >= p) break;
      for(int e = grafo[i]; e != -1; e = prox[e]){
	int j = vert[e];
	if(dist[j] != -1) continue;
	dist[j] = dist[i] + 1;
	Q.push(j);
      }
    }

    printf("Teste %d\n", h);
    bool pri = true;
    for(int i = 0; i < n; i++){
      if(dist[i] > p || dist[i] <= 0) continue;
      if(!pri) printf(" ");
      printf("%d", i+1);
      pri = false;
    }
    printf("\n\n");
  }

  return 0;
}
