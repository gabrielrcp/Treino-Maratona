#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 5010

vector<int> G[MAX];
int n;

int numcomp;
int comp[MAX];

int tempo;
int lbl[MAX], low[MAX];

int P[MAX];
int topo;
char empilhado[MAX];


void dfs(int i)
{
  if(lbl[i] != -1) return;
  lbl[i] = tempo++;
  low[i] = lbl[i];

  P[topo++] = i;
  empilhado[i] = 1;
  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k];
    if(lbl[j] == -1){
      dfs(j);
      low[i] = min(low[i], low[j]);
    } else if(empilhado[j]){
      low[i] = min(low[i], low[j]);
    }
  }

  if(low[i] != lbl[i]) return;

  while(1){
    int j = P[--topo];
    comp[j] = numcomp;
    empilhado[j] = 0;
    if(j == i) break;
  }
  numcomp++;
}

void encontra_componentes()
{
  memset(lbl, -1, n*sizeof(int));
  tempo = 0;
  numcomp = 0;
  memset(empilhado, 0, n);
  topo = 0;
  for(int i = 0; i < n; i++)
    dfs(i);
}

char ehfolha[MAX];

void imprime_folhas()
{
  memset(ehfolha, 1, numcomp);

  for(int i = 0; i < n; i++){
    if(!ehfolha[comp[i]]) continue;
    for(int k = 0; k < (int)G[i].size(); k++){
      int j = G[i][k];
      if(comp[i] != comp[j]){
	ehfolha[comp[i]] = 0;
	break;
      }
    }
  }

  bool prim = true;
  for(int i = 0; i < n; i++){
    if(ehfolha[comp[i]]){
      if(!prim)
	putchar(' ');
      printf("%d", i+1);
      prim = false;
    }
  }
  putchar('\n');
}


int main()
{
  while(1){
    scanf(" %d", &n);
    if(n == 0) break;
    for(int i = 0; i < n; i++)
      G[i].clear();

    int m;
    scanf(" %d", &m);
    while(m--){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      G[i].push_back(j);
    }

    encontra_componentes();
    imprime_folhas();
  }
  return 0;
}



