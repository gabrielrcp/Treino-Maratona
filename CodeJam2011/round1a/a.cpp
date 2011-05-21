#include <cstdio>

typedef long long ll;

ll mdc(ll a, ll b)
{
  if(a < b) return mdc(b, a);
  if(b == 0) return a;
  return mdc(b, a%b);
}

int resolve(ll n, ll p, ll q)
{

  int x, X;
  if(p != 0){
    x = p / mdc(100, p);
    X = 100LL*x/p;
  } else{
    x = 0;
    X = 1;
  }
  if(X > n) return 0;
  
  if(q == 100 && p != 100)
    return 0;
  if(q == 0 && p != 0)
    return 0;
  return 1;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    ll n, p, q;
    scanf(" %lld %lld %lld", &n, &p, &q);
    printf("Case #%d: %s\n", h, resolve(n, p, q) ? "Possible" : "Broken");
  }
  return 0;
}
