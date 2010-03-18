#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <list>

using namespace std;

#define MAXV (220)
#define MAXE (MAXV*MAXV)

list<int> horarios[1440];

int grafo[MAXV];
int vert[MAXE];
int prox[MAXE];
int cap[MAXE];
int fluxo[MAXE];
int nume;


void _add_edge(int i, int j, int cp)
{
  int e = nume++;
  prox[e] = grafo[i];
  grafo[i] = e;
  vert[e] = j;
  cap[e] = cp;
  fluxo[e] = 0;
}

void add_edge(int i, int j, int cp)
{
  _add_edge(i, j, cp);
  _add_edge(j, i, 0);
}

int lerhora()
{
  int a, b;
  scanf(" %d:%d", &a, &b);
  return 60*a+b;
}

int capat;
int vis[MAXV];
int mark;

bool dfs(int i)
{
  if(vis[i] == mark)
    return false;
  vis[i] = mark;
  if(i == 1) return true;
  for(int e = grafo[i]; e != -1; e = prox[e]){
    int j = vert[e];
    int c = (cap[e] == -1 ? capat : cap[e]);
    if(fluxo[e] < c && dfs(j)){
      fluxo[e]++;
      fluxo[e^1]--;
      return true;
    }
  }
  return false;
}

int vai(int n)
{
  memset(vis, 0, sizeof vis);
  mark = 1;
  int atual = 0;
  capat = 1;
  while(1){
    while(dfs(0) && atual < n){
      atual++;
      mark++;
    }
    mark++;
    if(atual == n) break;
    capat++;
  }
  return capat;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    nume = 0;
    memset(grafo, -1, sizeof grafo);

    int n, m;
    scanf(" %d %d", &n, &m);
 
    for(int t = 0; t < 1440; t++){
      horarios[t].clear();
    }

    for(int i = 0; i < m; i++){
      int t = lerhora();
      horarios[t].push_back(i+n+2);
      add_edge(i+n+2, 1, -1);
    }
   

    for(int i = 0; i < n; i++){
      int k;
      scanf(" %d", &k);
      add_edge(0, i+2, 1);
      while(k--){
	int t = lerhora();
	for(list<int>::iterator it = horarios[t].begin(); it != horarios[t].end(); it++){
	  add_edge(i+2, *it, 1);
	}
      }
    }
    
    printf("%d\n", vai(n));
  }
  return 0;
}
