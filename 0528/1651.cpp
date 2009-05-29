#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 110

int n;
int v[MAX];

long long memo[MAX][MAX];

long long resolve(int i, int j)
{
  if(i + 1 >= j)
    return 0;
  if(i + 1 == j - 1)
    return v[i] * v[i+1] * v[j];

  long long &r = memo[i][j];
  if(r != -1)
    return r;

  long long t;
  r = 1LL << 60;
  /*
resolve(i+1, j) + v[i] * v[i+1] * v[j];
  t = reslve(i, j-1) + v[i] * v[j-1] * v[j];
  r = min(r, t);
  */
  for(int k = i+1; k < j; k++){
    t = resolve(i, k) + resolve(k, j) + 
      v[i] * v[k] * v[j];
    r = min(r, t);
  }
  //printf("%d %d %d %d %lld\n", i, j, e, d, r);

  return r;
}

int main()
{
  scanf(" %d", &n);
  for(int i = 0; i < n; i++)
    scanf(" %d", v+i);

  for(int i = 0; i <= n+1; i++)
    for(int j = 0; j <= n+1; j++)
      memo[i][j] = -1;

  printf("%lld\n", resolve(0, n-1));

  return 0;
}
