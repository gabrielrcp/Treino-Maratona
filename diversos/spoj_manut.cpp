#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 400

vector<int> G[MAX];
bool articula[MAX];
int low[MAX];
int pai[MAX];
int lbl[MAX];
int tempo;
int n;

void dfs(int i)
{
  int f = 0;
  lbl[i] = low[i] = tempo++;
  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k];
    if(pai[i] == j)
      continue;
    if(pai[j] == -1){
      pai[j] = i;
      dfs(j);
      f++;
      if(pai[i] != i && low[j] >= lbl[i])
	articula[i] = true;
      low[i] = min(low[i], low[j]);
    }
    else
      low[i] = min(low[i], lbl[j]);
  }
  if(i == pai[i] && f > 1)
    articula[i] = true;
}

void resolve()
{
  for(int i = 0; i < n; i++){
    articula[i] = false;
    pai[i] = -1;
  }
  tempo = 0;
  pai[0] = 0;
  dfs(0);
}


int main()
{
  int m;
  for(int h = 1; ; h++){
    scanf(" %d %d", &n, &m);
    if(n == m && m == 0)
      break;
    for(int i = 0; i < n; i++)
      G[i].clear();
    while(m--){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      G[i].push_back(j);
      G[j].push_back(i);
    }

    resolve();

    printf("Teste %d\n", h);
    int conta = 0;
    for(int i = 0; i < n; i++)
      if(articula[i]){
	conta++;
	printf("%d ", i+1);
      }
    if(conta == 0)
      printf("nenhum");
    printf("\n\n");
  }
  return 0;
}
