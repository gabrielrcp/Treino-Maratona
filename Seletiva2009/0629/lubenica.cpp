#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100010
#define LMAX 20
#define INF (1<<30)

typedef pair<int, int> pii;

vector<pii> G[MAX];
pii pai[MAX];
int LCA[MAX][LMAX];
int mini[MAX][LMAX];
int maxi[MAX][LMAX];
int n;
int dist[MAX];

void dfs(int i)
{
  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k].first;
    if(pai[i].first != j && pai[j].first == -1){
      pai[j] = make_pair(i, G[i][k].second);
      dist[j] = dist[i] + 1;
      dfs(j);
    }
  }
}


void monta()
{
  pai[0] = make_pair(0, 0);
  for(int i = 1; i < n; i++)
    pai[i] = make_pair(-1, 0);
  dist[0] = 0;
  dfs(0);


  for(int i = 1; i < n; i++){
    LCA[i][0] = pai[i].first;
    mini[i][0] = maxi[i][0] = pai[i].second;
  }
  LCA[0][0] = 0;
  mini[0][0] = INF;
  maxi[0][0] = -1;

  for(int j = 1; (1 << j) <= n; j++){
    for(int i = 0; i < n; i++){
      LCA[i][j] = LCA[LCA[i][j-1]][j-1];
      mini[i][j] = min(mini[i][j-1], mini[LCA[i][j-1]][j-1]);
      maxi[i][j] = max(maxi[i][j-1], maxi[LCA[i][j-1]][j-1]);
    }
  }
}

pii vai(int p, int q)
{
  if(dist[p] < dist[q])
    return vai(q, p);

  int rma = -1, rmi = INF;
  
  int k = dist[p] - dist[q];
  for(int j = 0; (1 << j) <= k; j++)
    if((1 << j) & k){
      rma = max(rma, maxi[p][j]);
      rmi = min(rmi, mini[p][j]);
      p = LCA[p][j];
    }
  
  if(p == q)
    return make_pair(rmi, rma);

  k = 0;
  while(LCA[p][k] != LCA[q][k])
    k++;
  k--;

  for(int j = k; j >= 0; j--){
    if(LCA[p][j] != LCA[q][j]){
      rmi = min(rmi, min(mini[p][j], mini[q][j]));
      rma = max(rma, max(maxi[p][j], maxi[q][j]));
      p = LCA[p][j]; q = LCA[q][j];
    }
  }
  
  rmi = min(rmi, min(pai[p].second, pai[q].second));
  rma = max(rma, max(pai[p].second, pai[q].second));
  return make_pair(rmi, rma);
}


int main()
{

  scanf(" %d", &n);

  for(int i = 1; i < n; i++){
    int a, b, c;
    scanf(" %d %d %d", &a, &b, &c);
    a--; b--;
    G[a].push_back(make_pair(b, c));
    G[b].push_back(make_pair(a, c));
  }

  monta();
  int k;
  scanf(" %d", &k);
  while(k--){
    int i, j;
    scanf(" %d %d", &i, &j);
    i--; j--;
    pii p = vai(i, j);
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}
