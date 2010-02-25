#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXV (5010)
#define MAXE (60010)
const int INF = ((1<<31)-1);

typedef long long ll;

int grafo[MAXV];
int vert[MAXE];
int cap[MAXE];
int prox[MAXE];
int nume;
int n;

int pai[MAXV];
int dist[MAXV];
int atual[MAXV];

inline void _add_edge(int i, int j, int cp)
{
  int e = nume++;
  prox[e] = grafo[i];
  grafo[i] = e;
  cap[e] = cp;
  vert[e] = j;
}

inline void add_edge(int i, int j, int cp)
{
  _add_edge(i, j, cp);
  _add_edge(j, i, cp);
}

int Q[MAXV];

bool calc_dist(int s, int t)
{
  memset(dist, 0, n * sizeof(int));
  dist[t] = n;
  int ini = 0, fim = 1;
  Q[0] = t;
  while(ini < fim){
    int j = Q[ini++];
    for(int e = grafo[j]; e  != -1; e = prox[e]){
      int i = vert[e];
      if(cap[e^1] <= 0) continue;
      if(dist[j] - dist[i] > 1){
	dist[i] = dist[j] - 1;
	Q[fim++] = i;
      }
    }
  }
  return (dist[s] != 0);
}

int aumenta_fluxo(int s, int t, int val = INF)
{
  if(s == t)
    return val;
  int e = pai[t];
  int j = vert[e^1];

  val = aumenta_fluxo(s, j, min(val, cap[e]));

  cap[e] -= val;
  cap[e^1] += val;

  return val;
}

int P[MAXV];

int dfs(int i, int s, int t)
{
  if(i == t)
    return aumenta_fluxo(s, t);

  for(int &e = atual[i]; e != -1; e = prox[e]){
    int j = vert[e];
    if(cap[e] <= 0 || dist[j] - dist[i] != 1)
      continue;
    pai[j] = e;
    int tt = dfs(j, s, t);
    if(tt > 0) return tt;
  }
  return 0;
}

ll dinits(int s, int t)
{
  ll inten = 0;

  while(calc_dist(s, t)){
    memcpy(atual, grafo, n * sizeof(int));
    while(1){
      int tt = dfs(s, s, t);
      if(tt == 0) break;
      inten += tt;
    }
  }
  return inten;
}


int main()
{

  int s, t, m;
  scanf(" %d %d", &n, &m);
  nume = 0;
  memset(grafo, -1, n * sizeof(int));

  s = 0;
  t = n-1;

  while(m--){
    int i, j, cp;
    scanf(" %d %d %d", &i, &j, &cp);
    i--; j--;
    if(i == j) continue;
    add_edge(i, j, cp);
  }

  printf("%lld\n", dinits(s, t));

  return 0;
}
