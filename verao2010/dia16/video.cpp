#include <cstdio>

typedef long long ll;

ll calcula(ll s, ll b, ll d, ll t)
{
  return (t*(b-d) + s-1) / s;
}

int main()
{
  
  freopen("video.in", "r", stdin);
  freopen("video.out", "w", stdout);
  
  ll d, b, t, p;
  scanf(" %lld %lld %lld %lld" , &d, &b, &t, &p);

  ll melhor = calcula(d*p, b, d, t);
  ll left = 1, right = d*p-1;
  ll resp = d*p;
  while(left <= right){
    ll m = (left+right)/2;
    ll n = calcula(m, b, d, t);
    if(n == melhor){
      resp = m;
      right = m - 1;
    } else
      left = m + 1;
  }
  printf("%lld\n", resp);
}
