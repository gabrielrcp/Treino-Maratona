#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAXV (155)
#define MAXE (MAXV*MAXV)

int grafo[MAXV];
int prox[MAXE];
int vert[MAXE];
int nume;
int n;

int memo[MAXV];
int alt[MAXV];

void add_edge(int i, int j)
{
  int e = nume++;
  prox[e] = grafo[i];
  grafo[i] = e;
  vert[e] = j;
}

int vai(int i)
{
  int &r = memo[i];
  if(r != -1) return r;
  r = 0;

  for(int e = grafo[i]; e != -1; e = prox[e]){
    int j = vert[e];
    r = max(r, vai(j)+1);
  }
  return r;
}

int main()
{
  for(int h = 1; scanf(" %d", &n) && n; h++){
    int m, ini;
    scanf(" %d %d", &m, &ini);
    ini--;

    for(int i = 0; i < n; i++)
      scanf(" %d", alt+i);

    nume = 0;
    memset(grafo, -1, sizeof grafo);

 
    while(m--){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      if(alt[i] > alt[j])
	add_edge(i, j);
    }

    memset(memo, -1, sizeof memo);
    printf("Teste %d\n%d\n\n", h, vai(ini));

  }

  return 0;
}
