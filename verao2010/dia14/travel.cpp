#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 20010

vector<int> G[MAX];
int n;
int conta[MAX], tam[MAX];
int lbl[MAX], low[MAX];
int tempo;

void dfs(int i, int p)
{
  lbl[i] = tempo++;
  low[i] = lbl[i];
  tam[i] = 1;

  int tot = n-1;
  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k];
    if(j == p) continue;
    if(lbl[j] != -1){
      low[i] = min(low[i], lbl[j]);
    } else{
      dfs(j, i);
      low[i] = min(low[i], low[j]);
      tam[i] += tam[j];
      if(low[j] >= lbl[i]){
	tot -= tam[j];
	conta[i] += tam[j] * tot;
      }
    }
  }
}

void dfs_r(int i)
{
  lbl[i] = tempo++;
  low[i] = lbl[i];
  tam[i] = 1;

  int tot = n-1;
  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k];
    if(lbl[j] != -1){
      low[i] = min(low[i], lbl[j]);
    } else{
      dfs(j, i);
      low[i] = min(low[i], low[j]);
      tam[i] += tam[j];
      tot -= tam[j];
      conta[i] += tam[j] * tot;
      //printf("--%d\n", tam[j]);
    }
  }

}


int main()
{
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  int m;
  scanf(" %d %d", &n, &m);
  for(int i = 0; i < n; i++){
    G[i].clear();
    conta[i] = n-1;
  }
  while(m--){
    int i, j;
    scanf(" %d %d", &i, &j);
    i--; j--;
    G[i].push_back(j);
    G[j].push_back(i);
  }
  tempo = 0;
  
  memset(lbl, -1, sizeof lbl);
  dfs_r(0);
  for(int i = 0; i < n; i++)
    printf("%d\n", conta[i]);
  /*
  for(int i = 0; i < n; i++)
    printf("-- %d %d %d\n", i+1, lbl[i], low[i]);
  */
  return 0;
}
