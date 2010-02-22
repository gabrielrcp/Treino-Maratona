#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXV (3010)
#define MAXE (300100)

int grafo[MAXV];
int inv[MAXV];
int prox[MAXE];
int vert[MAXE];
int nume;
int n;

void _add_edge(int i, int j, int *g)
{
  int e = nume++;
  prox[e] = g[i];
  g[i] = e;
  vert[e] = j;
}

void add_edge(int i, int j)
{
  _add_edge(i, j, grafo);
  _add_edge(j, i, inv);
}

int termino[MAXV];
int tempo;
char vis[MAXV];

void dfs(int i, int *g)
{
  if(vis[i]) return;
  vis[i] = 1;
  for(int e = g[i]; e != -1; e = prox[e])
    dfs(vert[e], g);
  termino[tempo++] = i;
}


char resolve()
{
  tempo = 0;
  memset(vis, 0, sizeof vis);
  dfs(0, grafo);
  if(tempo < n) return 'N';

  tempo = 0;
  memset(vis, 0, sizeof vis);
  dfs(termino[n-1], inv);
  return(tempo < n ? 'N' : 'S');
}

int main()
{
  for(int h = 1; scanf(" %d", &n) && n; h++){
    nume = 0;
    memset(grafo, -1, sizeof grafo);
    memset(inv, -1, sizeof inv);

    int m;
    scanf(" %d", &m);
    while(m--){
      int x, y;
      scanf(" %d %d", &x, &y);
      x--; y--;
      add_edge(x, y);
    }

    printf("Teste %d\n%c\n\n", h, resolve());
  }
  return 0;
}
