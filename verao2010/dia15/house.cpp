#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 50010

struct aresta{
  int d;
  int a, b;
};

vector<aresta> G[MAX];
int n;

int lbl[MAX], low[MAX];
int tempo;

void dfs(int i, int p)
{
  lbl[i] = tempo++;
  low[i] = lbl[i];

  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k].d;
    if(j == p) continue;
    if(lbl[j] == -1){
      dfs(j, i);
      if(low[j] >= lbl[j])
	printf("%d %d\n", G[i][k].a, G[i][k].b);
      low[i] = min(low[i], low[j]);
    } else{
      low[i] = min(low[i], lbl[j]);
    }
  }
}

int main()
{
  freopen("house.in", "r", stdin);
  freopen("house.out", "w", stdout);

  while(1){
    int m;
    scanf(" %d %d", &n, &m);
    if(n == 0 && m == 0)
      break;
    for(int i = 0; i < n; i++)
      G[i].clear();

    while(m--){
      int a, b;
      aresta e;
      scanf("%d %d", &a, &b);
      e.a = a; e.b = b;
      a--; b--;
      e.d = b; G[a].push_back(e);
      e.d = a; G[b].push_back(e);
    }
    scanf(" - ");

    tempo = 0;
    memset(lbl, -1, sizeof lbl);
    dfs(0, -1);
    printf("0 0\n");
  }

  return 0;
}
