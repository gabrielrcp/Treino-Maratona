#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXB 22
#define MAXN 1010

int cap[MAXB];
int pref[MAXN][MAXB];
int n, b;

#define MAXV 1100
#define MAXE 50000

int grafo[MAXV];
int vertice[MAXE];
int fluxo[MAXE];
int proximo[MAXE];
int nume;

void add_edge(int i, int j, int cp)
{
  int e1 = nume++;
  int e2 = nume++;

  proximo[e1] = grafo[i];
  grafo[i] = e1;
  vertice[e1] = j;
  fluxo[e1] = cp;

  proximo[e2] = grafo[j];
  grafo[j] = e2;
  vertice[e2] = i;
  fluxo[e2] = 0;
}

void zera_grafo()
{
  memset(grafo, -1, sizeof grafo);
  nume = 0;

  for(int i = 0; i < n; i++)
    add_edge(0, i+2, 1);
  for(int i = 0; i < b; i++)
    add_edge(i+n+5, 1, cap[i]);
}

void adiciona(int p)
{
  for(int i = 0; i < n; i++)
    add_edge(i+2, pref[i][p]+n+5, 1);
}

int vis[MAXV];
int mark;

bool dfs(int i)
{
  if(i == 1) return true;
  if(vis[i] == mark) return false;
  vis[i] = mark;

  for(int e = grafo[i]; e != -1; e = proximo[e]){
    if(fluxo[e] <= 0) continue;
    if(dfs(vertice[e])){
      fluxo[e]--;
      fluxo[e^1]++;
      return true;
    }
  }
  return false;
}

int fluxo_maximo()
{
  mark++;
  int r = 0;
  while(dfs(0)){
    mark++;
    r++;
  }
  return r;
}

int main()
{
  scanf(" %d %d", &n, &b);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < b; j++){
      scanf(" %d", &pref[i][j]);
      pref[i][j]--;
    }
  }

  for(int i = 0; i < b; i++)
    scanf(" %d", cap+i);


  int resp = (1<<30);
  memset(vis, 0, sizeof vis);

  mark = 1;
  for(int i = 0; i < b; i++){
    zera_grafo();
    int j = i;
    int at = 0;
    while(j < b && j-i+1 < resp){
      adiciona(j);
      at += fluxo_maximo();
      if(at == n){
	resp = min(resp, j-i+1);
	break;
      }
      j++;
    }
  }

  printf("%d\n", resp);

  return 0;
}
