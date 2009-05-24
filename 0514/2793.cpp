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
      a = i;
      while(a != j){
	b = pai[a];
	if(!ehponte(a, b)){
	  return false;
	}
	marcar(a, b);
	a = b;
      }
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

vector<int> euler;

void constroi_euler(int i)
{
  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k];
    if(ehponte(i, j)) continue;
    apaga(i, j);
    constroi_euler(j);
    euler.push_back(j);
    euler.push_back(i);
  }
}


long long calcula()
{

  conta = 0;
  for(int i = 0; i < n; i++){
    vis[i] = false;
    pai[i] = -1;
  }

  if((!dfs(0)) || (!conexo()))
    return 0;

  for(int i = 0; i < n; i++)
    vis[i] = false;
  
  long long r = 1;

  for(int i = 0; i < n; i++){
    if(vis[i])
      continue;

    euler.clear();
    constroi_euler(i);
    
    if(euler.size() == 0) continue;
    reverse(euler.begin(), euler.end());
    
    stack<int> P;
    for(int k = 0; k <= euler.size(); k+=2){
      int j;
      if(k == euler.size())
	j = euler[k-1];
      else
	j = euler[k];
      if(vis[j]){
	int conta = 1;
	while(P.top() != j){
	  vis[P.top()] = false;
	  P.pop();
	  conta++;
	}
	P.pop();
	r *= (long long)(conta + 1);
      }
      P.push(j);
      vis[j] = true;
    }
    for(int k = 0; k < euler.size(); k++)
      vis[euler[k]] = true; 
  }

  return r;
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
