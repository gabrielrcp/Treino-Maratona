#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 20010

vector< vector<int> > G;
vector< vector<bool> > ponte;

int n;
bool vis[MAX];
int lbl[MAX];
int low[MAX], pai[MAX];
int conta;

bool ehcacto;
//int tamcomp[MAX];


void marcar(int i, int j)
{
  for(int k = 0; k < ponte[i].size(); k++)
    if(G[i][k] == j){
      ponte[i][k] = true;
      return;
    }
}

void dfs(int i)
{
  if(vis[i]) return;
  vis[i] = true;
  lbl[i] = ++conta;
  low[i] = lbl[i];

  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k];
    if(!vis[j]){
      pai[j] = i;
      dfs(j);
      if(low[i] < lbl[i] && low[j] < lbl[i])
	ehcacto = false;
      low[i] = min(low[i], low[j]);
      ponte[i].push_back(low[j] > lbl[i]);
      if(low[j] > lbl[i])
	marcar(j, i);
    }
    else{
      ponte[i].push_back(false);
      if(pai[i] != j){
	if(low[i] < lbl[i] && lbl[j] < lbl[i])
	  ehcacto = false;
	low[i] = min(low[i], lbl[j]);

      }
    }
  }
}

/*
void dfs2(int i)
{
  if(vis[i]) return;
  vis[i] = true;
  lbl[i] = ++conta;
  low[i] = lbl[i];

  for(int k = 0; k < G[i].size(); k++){
    if(ponte[i][k]) continue;
    int j = G[i][k];
    if(!vis[j]){
      pai[j] = i;
      dfs2(j);
      low[i] = min(low[i], low[j]);
    }
    else if(pai[i] != j)
      low[i] = min(low[i], lbl[j]);
  }
}
*/

bool conexo()
{
  for(int i = 0; i < n; i++)
    if(!vis[i])
      return false;
  return true;
}

long long calcula()
{

  conta = 0;
  for(int i = 0; i < n; i++){
    vis[i] = false;
    pai[i] = -1;
  }
  ehcacto = true;
  dfs(0);
  /*
  for(int i = 0; i < n; i++)
    printf("%d %d\n", i, pai[i]);
  */

  if(!(ehcacto && conexo()))
    return 0;

  /*
  conta = 0;
  for(int i = 0; i < n; i++){
    vis[i] = false;
    pai[i] = -1;
  } 

  for(int i = 0; i < n; i++)
    dfs2(i);

  for(int i = 0; i < n; i++)
    tamcomp[i] = 0;
  for(int i = 0; i < n; i++)
    tamcomp[low[i]]++;
  for(int i = 0; i < n; i++)
    if(tamcomp[lbl[i]] > 0 && lbl[i] != low[i])
      tamcomp[lbl[i]]++;
  */


  //Construir circuito euleriano e dai fica facil.

  return 1;
}


int main()
{
  int m;
  scanf(" %d %d", &n, &m);
  G = vector < vector<int> > (n, vector<int> ());
  ponte = vector < vector<bool> > (n, vector<bool> ());

  while(m--){
    int k, i, j;
    scanf(" %d %d", &k, &i);
    k--; i--;
    while(k--){
      scanf(" %d", &j);
      j--;
      G[i].push_back(j);
      G[j].push_back(i);
      i = j;
    }
  }

  printf("%lld\n", calcula());

  return 0;
}
