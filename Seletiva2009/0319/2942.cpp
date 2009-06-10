#include <cstdio>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

#define MAX 1010

bool mat[MAX][MAX];
int n;

int G[MAX][MAX];
int num[MAX];

bool articula[MAX];


int conta;
int ordem[MAX], low[MAX], pai[MAX];

void dfs(int i)
{
  int f = 0;
  ordem[i] = conta++;
  low[i] = ordem[i];
  for(int k = 0; k < num[i]; k++){
    int j = G[i][k];
    if(ordem[j] == -1){
      f++;
      pai[j] = i;
      dfs(j);
      low[i] = min(low[i], low[j]);
      if(pai[i] != i && low[j] >= ordem[i])
	articula[i] = true;
    }
    else if(pai[i] != j)
      low[i] = min(low[i], ordem[j]);
  }
  if(pai[i] == i && f > 1)
    articula[i] = true;
}


void achaarticula()
{
  conta = 1;
  for(int i = 0; i < n; i++){
    ordem[i] = low[i] = pai[i] = -1;
    articula[i] = false;
  }
  
  for(int i = 0; i < n; i++){
    if(ordem[i] == -1){
      pai[i] = i;
      dfs(i);
    }
  }
}


int M[MAX][MAX];
char cor[MAX];

bool bicolore(int i, int v, char c)
{
  cor[i] = c;
  for(int k = 0; k < num[i]; k++){
    int j = G[i][k];
    if(v != -1 && M[i][j] != v)
      continue;
    if(cor[j] == cor[i])
      return false;
    if(cor[j] + cor[i] == 1)
      continue;

    if(!bicolore(j, M[j][i], 1 - c))
      return false;
  }
  return true;
}

void mapear(int art, int i, int v)
{
  M[art][i] = v;
  
  for(int k = 0; k < num[i]; k++){
    int j = G[i][k];
    if(j == art || M[art][j] != -1)
      continue;
    mapear(art, j, v);
  }
}


int resolve()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      M[i][j] = -1;

  for(int i = 0; i < n; i++)
    if(articula[i]){
      int s = 0;
      for(int k = 0; k < num[i]; k++){
	int j = G[i][k];
	if(M[i][j] == -1)
	  mapear(i, j, s++);
      }
    }

  int r = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      cor[j] = -1;
    if(bicolore(i, -1, 0))
      r++;
  }
  return r;
} 

int main()
{
  int m;
  while(1){
    scanf(" %d %d", &n, &m);
    if(n == m && m == 0) break;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
	mat[i][j] = (i != j);
    }
    
    while(m--){
      int i, j;
      scanf( " %d %d", &i, &j);
      i--; j--;
      mat[i][j] = mat[j][i] = false;
    }
    
    for(int i = 0; i < n; i++){
      num[i] = 0;
      for(int j = 0; j < n; j++)
	if(mat[i][j]){
	  G[i][num[i]] = j;
	  num[i]++;
	}
    }

    achaarticula();
    printf("%d\n", resolve());

  }
  return 0;
}
