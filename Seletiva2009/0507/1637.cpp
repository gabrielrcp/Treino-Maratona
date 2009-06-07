#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 210

int n;

int unica[MAX][MAX];
int dupla[MAX][MAX];


int fluxo[MAX][MAX];
int ant[MAX];

bool acha_caminho(int s, int t)
{
  for(int i = 0; i <= n+1; i++)
    ant[i] = -1;

  queue<int> Q;
  Q.push(s);
  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int j = 0; j <= n; j++){
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
  int m = 0;
  int i, j;

  j = t; i = ant[t];
  do{
    m = max(m, dupla[i][j] - fluxo[i][j]);
    j = i;
    i = ant[i];
  }while(i != s);

  j = t; i = ant[t];
  do{
    fluxo[i][j] += m;
    fluxo[j][i] -= m;
  }while(i != s);
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



bool conexos()
{
  int a = -1, b = -1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(unica[i][j] || fluxo[i][j])
	a = i;
    }
  }

  for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++)
      if(abs(fluxo[i][j]) < dupla[i][j])
	b = i;




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
