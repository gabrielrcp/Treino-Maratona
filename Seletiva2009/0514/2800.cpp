#include <cstdio>
#include <algorithm>

using namespace std;

inline long long soma(long long a, long long b)
{
  return (a+b)*(b-a+1LL) / 2LL;
}

long long vai(long long n, long long k)
{
  long long resp = n * k;
  long long i, j, r, lim;

  i = 1;
  lim = min(n, k);
  while(i <= lim){
    r = k / i;
    j = (k / r) + 1LL;
    if(j > lim)
      j = lim+1LL;
    resp -= soma(i, j-1) * r;
    i = j;
  }
  return resp;
}

long long fb(long long n, long long k)
{
  long long resp = 0;
  for(long long i = 1; i <= n; i++)
    resp += k % i;
  return resp;
}

int main()
{
  long long n, k;
  /*
  for(n = 1; n <= 100; n++)
    for(k = 1; k <= 100; k++)
      if(vai(n, k) != fb(n, k))
	printf(" -- %lld %lld\n", n, k);
  */
  scanf(" %lld %lld", &n, &k);
  printf("%lld\n", vai(n, k));
  return 0;
}
