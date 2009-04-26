#include <cstdio>
#include <map>
#include <cstdlib>
#include <algorithm>

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
    int j = G[i][j];
    if(ordem[j] == -1){
      f++;
      pai[j] = i;
      dfs(j);
      low[i] = min(low[i], low[j]);
      if(low[j] >= ordem[i] && pai[i] != i)
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
    ordem[i] = low[i] = pai[MAX] = -1;
    articula[i] = false;
  }
  
  for(int i = 0; i < n; i++){
    if(ordem[i] == -1){
      pai[i] = i;
      dfs(i);
    }
  }
}


int main()
{
  int m;
  while(1){
    scanf(" %d %d", &n, &m);
    if(n == m && m == 0) break;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
	mat[i][j] = true;
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
  }
  return 0;
}
