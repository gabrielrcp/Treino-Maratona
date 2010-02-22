#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXV (110)
#define MAXE (2*MAXV)

int grafo[MAXV];
int prox[MAXE];
int vert[MAXE];
int nume;
int n;

void _add_edge(int i, int j)
{
  int e = nume++;
  prox[e] = grafo[i];
  grafo[i] = e;
  vert[e] = j;
}
void add_edge(int i, int j)
{
  _add_edge(i,  j);
  _add_edge(j,  i);
}

int vai(int i, int p)
{
  int r = 0;
  for(int e = grafo[i]; e != -1; e = prox[e]){
    int j = vert[e];
    if(j == p) continue;
    r = max(r, vai(j, i)+1);
  }
  return r;
}

int main()
{
  for(int h = 1; scanf(" %d", &n) && n; h++){
    nume = 0;
    memset(grafo, -1, sizeof grafo);
    for(int i = 1; i < n; i++){
      int x, y;
      scanf(" %d %d", &x, &y);
      x--; y--;
      add_edge(x, y);
    }

    int resp = -1;
    int melhor = (1<<30);

    for(int i = 0; i < n; i++){
      int t = vai(i, -1);
      if(t < melhor){
	resp = i;
	melhor = t;
      }
    }
    printf("Teste %d\n%d\n\n", h, resp+1);
  }
  return 0;
}
