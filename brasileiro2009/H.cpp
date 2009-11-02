#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, m;

int jogou[50][50];
int pontos[50];

#define MAXV 100000
#define MAXE 100000

int prim[MAXV];
int prox[MAXE];
int vert[MAXE];
int cap[MAXE];

int contae;
int mark;
int vis[MAXV];
int ant[MAXV];


bool encontra()
{
  queue<int> Q;

  vis[0] = mark;
  Q.push(0);

  while(!Q.empty()){
    int i = Q.front(); Q.pop();
    
    for(int e = prim[i]; e != -1; e = prox[e]){
      int j = vert[e];
      if(vis[j] == mark || cap[e] <= 0) continue;
      vis[j] = mark;
      ant[j] = e;
      if(j == 1) return true;
      Q.push(j);
    }
  }
  return false;
}

int aumenta_fluxo()
{
  int j = 1;
  int r = (1<<30);
  while(j != 0){
    r = min(r, cap[ant[j]]);
    j = vert[ant[j]^1];
  }

  j = 1;
  while(j != 0){
    cap[ant[j]] -= r;
    cap[ant[j]^1] += r;
    j = vert[ant[j]^1];
  }
  return r;
}

int fluxo_maximo()
{
  int resp = 0;
  memset(vis, 0, sizeof(vis));
  mark = 1;
  while(encontra()){
    resp += aumenta_fluxo();
    mark++;
  }
  return resp;
}


void insere(int i, int j, int ci, int cj)
{
  int e1 = contae++;
  int e2 = contae++;

  prox[e1] = prim[i];
  vert[e1] = j;
  prim[i] = e1;
  cap[e1] = ci;

  prox[e2] = prim[j];
  vert[e2] = i;
  prim[j] = e2;
  cap[e2] = cj;
}


bool resolve()
{
  int g;
  scanf(" %d", &g);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      jogou[i][j] = 0;
    pontos[i] = 0;
  }

  while(g--){
    int i, j;
    char c;
    scanf(" %d %c %d", &i, &c, &j);
    jogou[i][j]++; jogou[j][i]++;
    if(c == '<')
      pontos[j]+= 2;
    else{
      pontos[i]++;
      pontos[j]++;
    }
  }

  for(int j = 1; j < n; j++){
    if(jogou[j][0] < m){
      pontos[0] += 2*(m - jogou[j][0]);
      jogou[j][0] = jogou[0][j] = m;
    }
  }

  for(int j = 1; j < n; j++)
    if(pontos[j] >= pontos[0])
      return false;
    else
      pontos[j] = pontos[0] - pontos[j] - 1;

  contae = 0;
  for(int i = 0; i <= n; i++)
    prim[i] = -1;
  
  for(int i = 1; i < n; i++)
    insere(i+1, 1, pontos[i], 0);
  
  int at = n+1;
  int faltam = 0;
  for(int i = 1; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(jogou[i][j] == m) continue;
      prim[at] = -1;
      insere(0, at, 2*(m-jogou[i][j]), 0);
      insere(at, i+1, 2000, 0);
      insere(at, j+1, 2000, 0);
      faltam += 2 * (m-jogou[i][j]);
      at++;
    }
  }

  return (fluxo_maximo() == faltam);

}

int main()
{
  while(scanf(" %d %d", &n, &m) && n)
    printf("%c\n", (resolve() ? 'Y' : 'N'));
  return 0;
}
