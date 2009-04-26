#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXV 35
#define MAXP 1010

long long memo[MAXV][MAXP][MAXV];
int n;
int preco[MAXV];

long long vai(int i, int d, int ultimo)
{
  if(i == n){
    if(ultimo == n || d < preco[ultimo])
      return 1;
    return 0;
  }

  long long &r = memo[i][d][ultimo];
  if(r != -1LL)
    return r;

  r = vai(i+1, d, i);
  if(preco[i] <= d)
    r += vai(i+1, d - preco[i], ultimo);

  return r;  
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int d;
    scanf(" %d %d", &n, &d);
    for(int i = 0; i < n; i++){
      scanf(" %d", preco+i);
      if(preco[i] > d){
	i--; n--;
      }
    }
    if(n > 0){
      sort(preco, preco+n);
      reverse(preco, preco+n);

      for(int i = 0; i <= n; i++)
	for(int j = 0; j <= d; j++)
	  for(int k = 0; k <= n; k++)
	    memo[i][j][k] = -1;
      printf("%d %lld\n", h, vai(0, d, n));
    }
    else
      printf("%d 0\n", h);
  }
  return 0;
}
