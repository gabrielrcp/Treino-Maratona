#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct aresta{
  int i, j, c;
};

vector<aresta> grafo;

inline aresta nova(int i, int j, int c)
{
  aresta a;
  a.i = i; a.j = j; a.c = c;
  return a;
}

int dist[1010];
char chega[1010];

int main()
{
  int n, ml, md;
  scanf(" %d %d %d", &n, &ml, &md);

  for(int i = 0; i+1 < n; i++)
    grafo.push_back(nova(i+1, i, 0));

  while(ml--){
    int i, j, c;
    scanf(" %d %d %d", &i, &j, &c);
    i--; j--;
    grafo.push_back(nova(i, j, c));
  }
  while(md--){
    int i, j, c;
    scanf(" %d %d %d", &i, &j, &c);
    i--; j--;
    grafo.push_back(nova(j, i, -c));
  }

  memset(dist, 0x3f, sizeof dist);
  memset(chega, 0, sizeof chega);
  chega[0] = 1;
  dist[0] = 0;

  bool cont = true;
  for(int k = 0; k <= n && cont; k++){
    cont  = false;

    for(int l = 0; l < (int)grafo.size(); l++){
      int i = grafo[l].i;
      int j = grafo[l].j;
      int c = grafo[l].c;

      chega[j] = (chega[i] || chega[j]);
      if(dist[j] > dist[i] + c){
	dist[j] = dist[i] + c;
	cont = true;
      }
    }
  }
  if(cont)
    printf("-1\n");
  else if(!chega[n-1])
    printf("-2\n");
  else
    printf("%d\n", dist[n-1] - dist[0]);

  return 0;
}
