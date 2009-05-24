#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define MAX 20010

vector< vector<int> > G;
set< pair<int,int> > circuito;

int n;
bool vis[MAX];
int lbl[MAX];
int pai[MAX];
int conta;
long long resposta = 1;


inline void marcar(int i, int j)
{
  circuito.insert(make_pair(min(i,j),max(i,j)));
}

inline bool ehponte(int i, int j)
{
  return (circuito.find(make_pair(min(i,j),max(i,j))) == circuito.end());
}

inline void apaga(int i, int j)
{
  circuito.erase(make_pair(min(i,j),max(i,j)));
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
      int a, b;
      int conta = 1;
      a = i;
      while(a != j){
	b = pai[a];
	if(!ehponte(a, b)){
	  resposta = 0;
	  return false;
	}
	marcar(a, b);
	a = b;
	conta++;
      }
      resposta *= (long long)conta + 1;
    }
  }
  return true;
}

bool conexo()
{
  for(int i = 0; i < n; i++)
    if(!vis[i]){
      return false;
    }
  return true;
}

long long calcula()
{

  conta = 0;
  for(int i = 0; i < n; i++){
    vis[i] = false;
    pai[i] = -1;
  }

  dfs(0);

  if(!conexo())
    return 0;

  return resposta;
}


int main()
{
  int m;
  scanf(" %d %d", &n, &m);
  G = vector < vector<int> > (n, vector<int> ());
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
  printf("%lld\n", calcula());
  return 0;
}
