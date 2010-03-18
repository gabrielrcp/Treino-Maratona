#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

#define MAXV 110
#define MAXE 10010
typedef pair<int,int> pii;

int grafo[MAXV];
int prox[MAXE];
int vert[MAXE];
int custo[MAXE];
int nume;
int n;

void add_edge()
{
  int i, j, c;
  scanf(" %d %d %d", &i, &j, &c);
  i--; j--;
  int e = nume++;

  prox[e] = grafo[i];
  grafo[i] = e;
  custo[e] = c;
  vert[e] = j;
}

int dist[MAXV];

int main()
{
  while(scanf(" %d", &n) && n){
    int m;
    scanf(" %d", &m);

    memset(grafo, -1, n*sizeof(int));
    nume = 0;

    while(m--)
      add_edge();

    int s, t;
    scanf(" %d %d", &s, &t);
    s--; t--;

    priority_queue< pii, vector<pii>, greater<pii> > Q;
    Q.push(make_pair(0, s));
    memset(dist, 0x3f, n*sizeof(int));
    dist[s] = 0;

    while(!Q.empty()){
      pii p = Q.top(); Q.pop();
      int i = p.second;
      int d = p.first;
      if(dist[i] < d) continue;
      
      for(int e = grafo[i]; e != -1; e = prox[e]){
	int j = vert[e];
	if(dist[j] > d + custo[e]){
	  dist[j] = d + custo[e];
	  Q.push(make_pair(dist[j], j));
	}
      }
    }

    printf("%d\n", (dist[t] == 0x3f3f3f3f ? -1 : dist[t]));

  }
  return 0;
}
