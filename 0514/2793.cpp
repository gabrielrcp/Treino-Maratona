#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define MAX 20010

#define DIGI 2010
#define MOD 10000


vector< vector<int> > G;
set< pair<int,int> > circuito;

int n;
bool vis[MAX];
int lbl[MAX];
int pai[MAX];
int conta;


int resposta[DIGI];

void setar(int x)
{
  for(int i = 0; i < DIGI; i++){
    resposta[i] = x % MOD;
    x /= MOD;
  }
}

void multiplica(int x)
{
  int sobra = 0;
  for(int i = 0; i < DIGI; i++){
    resposta[i] *= x;
    resposta[i] += sobra;
    sobra = resposta[i] / MOD;
    resposta[i] %= MOD;
  }
}

void imprime()
{
  int i = DIGI-1;
  while(i > 0 && resposta[i] == 0)
    i--;

  for(int j = i; j >= 0; j--){
    int pot = MOD;
    if(i != j)
      while(pot > 10){
	pot /= 10;
	if(resposta[j] < pot)
	  printf("0");
	else
	  break;
      }
    printf("%d", resposta[j]);
  }
  printf("\n");
}




inline void marcar(int i, int j)
{
  pair<int, int> P = make_pair(min(i,j), max(i,j));
  circuito.insert(P);
}

inline bool marcado(int i, int j)
{
  pair<int, int> P = make_pair(min(i,j), max(i,j));
  return (circuito.find(P) != circuito.end());
}

bool dfs(int i)
{
  vis[i] = true;
  lbl[i] = ++conta;

  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k];
    if(!vis[j]){
      pai[j] = i;
      if(!dfs(j))
	return false;
    }
    else if(pai[i] != j && lbl[j] < lbl[i]){
      marcar(i, j);
      int a = i;
      int c = 1;
      while(a != j){
	if(marcado(a, pai[a])){
	  setar(0);
	  return false;
	}
	marcar(a, pai[a]);
	a = pai[a];
	c++;
      }
      multiplica(c + 1);
    }
  }
  return true;
}

bool conexo()
{
  for(int i = 0; i < n; i++)
    if(!vis[i])
      return false;
  return true;
}

void calcula()
{

  conta = 0;
  for(int i = 0; i < n; i++){
    vis[i] = false;
    pai[i] = -1;
  }
  setar(1);

  dfs(0);
  if(!conexo())
    setar(0);
}


int main()
{
  int m;
  scanf(" %d %d", &n, &m);
  G = vector < vector<int> > (n);
  circuito.clear();

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

  calcula();
  imprime();
  return 0;
}
