#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define MAX 20010

vector< vector<int> > G;
set< pair<int,int> > ponte;

int n;
bool vis[MAX];
int lbl[MAX];
int low[MAX], pai[MAX];
int conta;

bool ehcacto;


inline void marcar(int i, int j)
{
  ponte.insert(make_pair(min(i,j),max(i,j)));
}

inline bool ehponte(int i, int j)
{
  return (ponte.find(make_pair(min(i,j),max(i,j))) != ponte.end());
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
      if(low[j] > lbl[i])
	marcar(j, i);
    }
    else if(pai[i] != j){
      if(low[i] < lbl[i] && lbl[j] < lbl[i])
	ehcacto = false;
      low[i] = min(low[i], lbl[j]);

    }
  }
}

bool conexo()
{
  for(int i = 0; i < n; i++)
    if(!vis[i])
      return false;
  return true;
}

vector<int> euler;

void constroi_euler(int i)
{
  //int filhos = 0;
  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k];
    if(ehponte(i, j)) continue;
    marcar(i, j);
    constroi_euler(j);
    euler.push_back(j);
    euler.push_back(i);
    //printf("%d ", i+1);
    //filhos++;
  }
  /*  
  if(filhos == 0){
    //printf("%d ", i+1);
    euler.push_back(i);
  }
  */
  
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

  if(!(ehcacto && conexo()))
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
    /*    
    for(int k = 0; k < euler.size(); k++)
      printf("%d ", euler[k]+1);
    printf("\n");
    */
    
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
  ponte.clear();

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
