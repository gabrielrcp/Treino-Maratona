#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 210
#define INF (1<<30)

int n;

int unica[MAX][MAX];
int dupla[MAX][MAX];


int fluxo[MAX][MAX];
int ant[MAX];

bool acha_caminho(int s, int t)
{
  for(int i = 0; i <= n+1; i++)
    ant[i] = -1;

  ant[s] = s;
  queue<int> Q;
  Q.push(s);
  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int j = 0; j <= n+1; j++){
      if(i == j) continue;
      if(ant[j] == -1 && fluxo[i][j] < dupla[i][j]){
	Q.push(j);
	ant[j] = i;
      }
    }
  }
  return (ant[t] != -1);
}


void incrementa_fluxo(int s, int t)
{
  int m = INF;
  int i, j;

  j = t; i = ant[t];
  while(j != s){
    m = min(m, dupla[i][j] - fluxo[i][j]);
    j = i;
    i = ant[i];
  }

  j = t; i = ant[t];
  while(j != s){
    fluxo[i][j] += m;
    fluxo[j][i] -= m;
    j = i;
    i = ant[i];
  }
}

bool fluxo_maximo(int s, int t)
{
  for(int i = 0; i <= n+1; i++)
    for(int j = 0; j <= n+1; j++)
      fluxo[i][j] = 0;

  
  while(1){
    if(!acha_caminho(s, t))
      break;
    incrementa_fluxo(s, t);
  }
  
  for(int j = 1; j <= n; j++){
    if(fluxo[s][j] < dupla[s][j])
      return false;
    if(fluxo[j][t] < dupla[j][t])
      return false;
  }
  
  return true;
}

bool alcanca1[MAX], alcanca2[MAX];

int lbl[MAX], low[MAX];
int vis[MAX];
int conta;



void dfs(int i)
{
  vis[i] = true;
  lbl[i] = conta++;
  low[i] = lbl[i];
  for(int j = 1; j <= n; j++){
    if(i == j)
      continue;
    if(unica[i][j] == 0 && fluxo[i][j] == dupla[i][j])
      continue;

    if(!vis[j]){
      dfs(j);
      low[i] = min(low[i], low[j]);
    }
    else
      low[i] = min(low[i], lbl[j]);
  }
}


bool vai()
{
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++)
      dupla[0][i] += unica[i][j] - unica[j][i];
    dupla[i][n+1] = -min(dupla[0][i], 0);
    dupla[0][i] = max(dupla[0][i], 0);    
  }
  
  if(!fluxo_maximo(0, n+1))
    return false;

  for(int i = 1; i <= n; i++){
    int s = 0;
    for(int j = 1; j <= n; j++)
      s += dupla[i][j] - abs(fluxo[i][j]);
    if(s % 2 == 1)
      return false;
  }
    
  for(int i = 1; i <= n; i++)
    vis[i] = false;

  conta = 0;
  dfs(1);

  /*
  for(int i = 1; i <= n; i++)
    printf("%d ", low[i]);
  printf("\n");
  */


  for(int i = 1; i <= n; i++)
    if((!vis[i]) || (low[i] > 0 && low[i] == lbl[i]))
      return false;
  
  return true;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int m;
    scanf(" %d %d", &n, &m);
    for(int i = 0; i  <= n + 1; i++)
      for(int j = 0; j <= n + 1; j++)
	unica[i][j] = dupla[i][j] = 0;
    while(m--){
      int i, j, r;
      scanf(" %d %d %d", &i, &j, &r);
      if(r == 1)
	unica[i][j]++;
      else{
	dupla[i][j]++;
	dupla[j][i]++;
      }
    }
    
    if(vai())
      printf("possible\n");
    else
      printf("impossible\n");
    
  }
  return 0;
}
