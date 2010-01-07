#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int d, n;
typedef long long ll;

inline int teto(int k)
{
  if(d % k == 0) return d/k;
  return d/k+1;
}

int main()
{
  while(scanf(" %d %d", &d, &n) && d && n){
    ll resp = 0;

    int k = 1;
    while(n > 0){
      int t = teto(k);
      if(n >= t){
	resp += (n - t+1) * k;
	n = t - 1;
      }
      if(n > 0)
	k = teto(n);
    }
    printf("%lld\n", resp);
  }
  return 0;
}
