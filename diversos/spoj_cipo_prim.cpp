// TLE sem fast input :(

#include <vector>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

#define MAXV 1010
#define MAXE 4000010

int grafo[MAXV];
int vert[MAXE];
int prox[MAXE];
int custo[MAXE];
int nume;
int dist[MAXV];

void _add_edge(int i, int j, int c)
{
  int e = nume++;
  prox[e] = grafo[i];
  vert[e] = j;
  custo[e] = c;
  grafo[i] = e;
}

void add_edge(int i, int j, int c)
{
  _add_edge(i, j, c);
  _add_edge(j, i, c);
}

int lista[MAXV][3];
int num[3];

int ler()
{
  char c;
  int r = 0;
  while(!isdigit(c = getchar_unlocked()));
  r = c - '0';
  while(isdigit(c = getchar_unlocked())){
    r = 10*r + c - '0';
  }
  return r;
}


inline int qual(int c)
{
  switch(c){
  case 1235:  return 0;
  case 8977:  return 1;
  case 10923: return 2; 
  }
}

int dd[3] = {1235, 8977, 10923};

int retira()
{
  for(int k = 0; k < 3; k++){
    while(num[k] > 0){
      num[k]--;
      int r = lista[num[k]][k];
      if(dist[r] == dd[k])
	return r;
    }
  }
  return -1;
}

void insere(int val)
{
  int k = qual(dist[val]);
  lista[num[k]][k] = val;
  num[k]++;
}

int main()
{
  for(int h = 1; ; h++){
    int n, m;
    if(feof(stdin))
      break;
    if(scanf(" %d %d", &n, &m) == 0)
      break;
    if(feof(stdin))
      break;

    memset(grafo, -1, n * sizeof(int));
    nume = 0;
    while(m--){
      int i, j, c;
      scanf(" %d %d %d", &i, &j, &c);
      //int i = ler(), j = ler(), c = ler();
      i--; j--;
      add_edge(i, j, c);
    }
    
    int resp = 0;
    
    memset(dist, 0x3f, n * sizeof(int));
    int conta = 0;
    memset(num, 0, sizeof num);


    int ult = 0;
    while(conta+1 < n){
      int i = ult;
      while(dist[i] == 0) i++;
      ult = i+1;

      dist[i] = 0;
      conta++;

      for(int e = grafo[i]; e != -1; e = prox[e]){
	int j = vert[e];
	if(dist[j] > custo[e]){
	  dist[j] = custo[e];
	  insere(j);
	}
      }

      while(1){
	i = retira();
	if(i == -1) break;
	resp += dist[i];
	dist[i] = 0;
	conta++;
      
	for(int e = grafo[i]; e != -1; e = prox[e]){
	  int j = vert[e];
	  if(dist[j] > custo[e]){
	    dist[j] = custo[e];
	    insere(j);
	  }
	}
      }
    }

    printf("Instancia %d\n%d\n\n", h, resp);
  }

  return 0;
}
