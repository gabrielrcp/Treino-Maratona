#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

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

void _add_edge(int i, int j, int cp)
{
  int e = nume++;
  prox[e] = grafo[i];
  grafo[i] = e;
  cap[e] = cp;
  vert[e] = j;
}


void add_edge(int i, int j, int cp)
{
  _add_edge(i, j, cp);
  _add_edge(j, i, cp);
}

bool calc_dist(int s, int t)
{
  memset(dist, 0, sizeof dist);
  dist[t] = n;
  queue<int> Q;
  Q.push(t);
  while(!Q.empty()){
    int j = Q.front(); Q.pop();
    for(int e = grafo[j]; e  != -1; e = prox[e]){
      int i = vert[e];
      if(cap[e^1] <= 0) continue;
      if(dist[j] - dist[i] > 1){
	dist[i] = dist[j] - 1;
	Q.push(i);
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

ll dinits(int s, int t)
{
  ll inten = 0;

  while(calc_dist(s, t)){

    memcpy(atual, grafo, n*sizeof(int));

    int topo = 0;
    P[topo++] = s;
    while(topo > 0){
      int i = P[topo-1];

      if(i == t){
	inten += aumenta_fluxo(s, t);
	topo = 0;
	P[topo++] = s;
	continue;
      }

      int &e = atual[i];
      while(e != -1){
	int j = vert[e];
	if(cap[e] > 0 && dist[j] - dist[i] == 1 && atual[j] != -1)
	  break;
	e = prox[e];
      }
      if(e == -1)
	topo--;
      else{
	int j = vert[e];
	P[topo++] = j;
	pai[j] = e;
      }
    }
    
  }
  return inten;
}


int main()
{

  int s, t, m;
  scanf(" %d %d", &n, &m);
  nume = 0;
  memset(grafo, -1, sizeof grafo);

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
