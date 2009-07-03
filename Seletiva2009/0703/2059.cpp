#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 50

int n;
int lado;
int x[MAX], y[MAX];


int dist_queda(int i, int j)
{
  int d = min(min(i, j), min(lado-i, lado-j));
  return d*d;
}

int dist_abert(int i, int j)
{
  int d = -1;
  int t;
  for(int k = 0; k < n; k++){
    t = (x[k]-i)*(x[k]-i) + (y[k]-j)*(y[k]-j);
    d = max(t, d);
  }
  return d;
}


bool pode(int i, int j)
{
  for(int k = 0; k < n; k++)
    if(x[k] == i && y[k] == j)
      return false;
  return (dist_abert(i, j) <= dist_queda(i, j));
}


pair<int, int> resolve()
{
  for(int i = 0; i <= lado; i++)
    for(int j = 0; j <= lado; j++)
      if(pode(i, j))
	return make_pair(i, j);
  return make_pair(-1, -1);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d", &lado, &n);
    for(int i = 0; i < n; i++)
      scanf(" %d %d", x+i, y+i);
    pair<int, int> p = resolve();
    if(p.first == -1)
      printf("poodle\n");
    else
      printf("%d %d\n", p.first, p.second);
   }
  return 0;
}
