#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 5010
#define INF (1LL<<60)

long long x[MAX], y[MAX];
int n;
long long l, l2;
//long long area[MAX][MAX];

inline long long distancia(int i, int j)
{
  return (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
}

typedef pair<long long, long long> frac;

inline bool menor(frac x, frac y)
{
  return x.first*y.second <= x.second*y.first;
}


long long vai()
{

  long long maximo = 0;
  frac minimo, atual;
  long long t, u;
  long long a, b, c, d;

  for(int i = 0; i+1 < n; i++){
    minimo = make_pair(y[i+1]-y[i], x[i+1]-x[i]);
    t = 0;
    for(int j = i+2; j < n; j++){
      atual = make_pair(y[j] - y[i], x[j] - x[i]);

      a = x[j-1] - x[i];
      b = y[j-1] - y[i];
      c = x[j] - x[i];
      d = y[j] - y[i];
      t += a*d - c*b;
      if(menor(atual, minimo)){
	if(distancia(i, j) <= l2){
	  u = ((t >= 0LL) ? t : -t);
	  if(u > maximo)
	    maximo = u;
	}
	minimo = atual;
      }
    }
  }
  return maximo;
}

int main()
{
  scanf(" %d %lld", &n, &l);
  l2 = l*l;
  for(int i = 0; i < n; i++)
    scanf(" %lld  %lld", x+i, y+i);
  /*
  for(int i = 0; i < n; i++)
    for(int j = i+2; j < n; j++)
      area[i][j] = INF;
  */
  long long r = vai();

  if(r&1LL)
    printf("%lld.5\n", (r>>1));
  else
    printf("%lld\n", r>>1);

  return 0;
}
