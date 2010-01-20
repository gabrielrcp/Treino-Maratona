// Presentation Error! :(

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 210

int n, m;
vector<int> G[4*MAX];
int diag[MAX];
int linha[2*MAX][MAX];
char setado[2*MAX];

int nao(int i)
{
  if(i < m) return i+m;
  return i-m;
}

void ou(int i, int j)
{
  G[nao(i)].push_back(j);
  G[nao(j)].push_back(i);
}

int vis[4*MAX];
int mark;
char dentro[4*MAX];

void dfs(int i)
{
  if(vis[i] == mark) return;
  vis[i] = mark;
  for(int k = 0; k < (int)G[i].size(); k++)
    dfs(G[i][k]);
}

void marca(int i)
{
  if(dentro[i]) return;
  dentro[i] = 1;
  for(int k = 0; k < (int)G[i].size(); k++)
    marca(G[i][k]);
}

bool confere()
{
  for(int j = 0; j < m; j++){
    if(vis[j] == mark && vis[nao(j)] == mark)
      return false;
    if(vis[j] == mark && dentro[nao(j)])
      return false;
    if(vis[nao(j)] == mark && dentro[j])
      return false;
  }
  return true;
}


bool resolve()
{

  for(int i = 0; i < n; i++){
    int a = -1, b = -1;
    for(int j = 0; j < m; j++){
      if(linha[j][i] == diag[i]){
	if(a == -1) a = j;
	else b = j;
      }
    }
    if(a == -1)
      return false;
    if(b == -1)
      ou(a, a);
    else
      ou(a, b);
  }

  for(int i = 0; i < m; i++)
    for(int j = i+1; j < m; j++){
      int k = 0;
      while(k < n && linha[i][k] != linha[j][k])
	k++;
      if(k < n)
	ou(nao(i), nao(j));
    }
  
  memset(dentro, 0, sizeof dentro);
  memset(vis, 0, sizeof vis);
  mark = 1;

  for(int i = 0; i < m; i++){
    if((!dentro[i]) && (!dentro[nao(i)])){
      mark++;
      dfs(i);
      if(confere()){
	marca(i);
	continue;
      }

      mark++;
      dfs(nao(i));
      if(confere()){
	marca(nao(i));
	continue;
      }
      return false;
    }
  }
  return true;
}

int main() 
{
  freopen("show.in","r",stdin);
  freopen("show.out","w",stdout);

  scanf(" %d", &n);
  for(int i = 0; i < n; i++)
    scanf(" %d", diag+i);

  scanf(" %d", &m);
  for(int i = 0; i < 4*m; i++)
    G[i].clear();

  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      scanf(" %d", &linha[i][j]);

  if(!resolve()){
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  bool pri = true;
  for(int i = 0; i < m; i++){
    if(dentro[i]){
      if(!pri)
	printf(" ");
      else
	pri = false;
      printf("%d", i+1);
    }
  }
  printf("\n");

  return 0;
}
