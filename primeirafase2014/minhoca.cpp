/*
 * Primeira fase da maratona 2014
 * Problema: minhoca
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4659
 * Resposta: AC
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXV (10010)
#define MAXE (4*MAXV)

#define INF (1<<20)

int grafo[MAXV];
int next[MAXE];
int vert[MAXE];
int cost[MAXE];
int N;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

void add_edge(int i, int j, int c, int e)
{
  vert[e] = j;
  next[e] = grafo[i];
  cost[e] = c;
  grafo[i] = e;
}

int dist[MAXV];
int ciclo[MAXV];

void dfs(int i, int p)
{
  if(dist[i] == -1)
    dist[i] = 0;

  for(int e = grafo[i]; e != -1; e = next[e]){
    int j = vert[e];
    if(j == p) continue;
    if(dist[j] == -1){
      dist[j] = dist[i] + cost[e];
      dfs(j, i);
    } else {
      ciclo[j] = dist[i] - dist[j] + cost[e];
    }
  }
}


int solve(int x, int m)
{
  memset(dist, -1, sizeof dist);
  memset(ciclo, -1, sizeof ciclo);
  dfs(x, -1);

  memset(dist, -1, sizeof dist);
  dist[x] = 0;
  priority_queue< pii, vpii, greater<pii> > Q;
  Q.push(make_pair(0, x));
  int r = INF;
  while(!Q.empty()){
    int i = Q.top().second;
    //    printf("-- %d %d\n", i, Q.top().first);
    Q.pop();
    if(ciclo[i] >= m)
      r = min(r, 2*dist[i] + ciclo[i]);

    for(int e = grafo[i]; e != -1; e = next[e]){
      int j = vert[e];
      if(dist[j] == -1 || dist[j] > dist[i] + cost[e]){
	dist[j] = dist[i] + cost[e];
	Q.push(make_pair(dist[j], j));
      }
    }
  }

  if(r == INF)
    return -1;
  return r;
}

int main()
{
  int M;
  while(scanf(" %d %d", &N, &M) == 2){

    memset(grafo, -1, sizeof grafo);
    for(int e = 0; e < M; e++){
      int i, j, c;
      scanf("%d %d %d", &i, &j, &c);
      add_edge(i-1, j-1, c, 2*e);
      add_edge(j-1, i-1, c, 2*e+1);
    }

    int q;
    scanf(" %d", &q);
    while(q--){
      int x, m;
      scanf(" %d %d", &x, &m);
      printf("%d\n", solve(x-1, m));
    }
  }
  return 0;
}
