/*
 * Primeira fase da maratona 2014
 * Problema RSA
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4664
 * Resposta: AC
 */

#include <cstdio>
#include <cassert>
#include <iostream>

typedef long long ll;
using namespace std;

ll potencia(ll x, ll e, ll m)
{
  if(e == 0) return 1;
  ll t = potencia(x, e/2, m);
  t *= t;
  t %= m;
  if(e % 2 == 1)
    t *= x;
  return t % m;
}

ll gcd(ll a, ll b, ll &x, ll &y)
{
  if(a == 0){
    x = 0; y = 1;
    assert(x*a + y*b == b);
    //printf("%lld * %lld + %lld * %lld == 1\n", x, a, y, b);
    return b;
  }
  ll d = gcd(b%a, a, x, y);
  ll nx = y - x * (b/a);
  ll ny = x;
  x = nx;
  y = ny;
  assert(x*a + y*b == d);
  //printf("%lld * %lld + %lld * %lld == 1\n", x, a, y, b);
  return d;
}


ll solve(ll n, ll e, ll c)
{
  for(ll p = 3; p*p <= n; p += 2){
    if(n % p != 0) continue;
    ll q = n/p;
    ll f = (p-1) * (q-1);
    if(f <= e) continue;

    ll x, y;
    if(gcd(e, f, x, y) != 1) continue;
    ll d = ((x % f) + f)%f;

    assert((d*e) % f == 1);

    ll m = potencia(c, d, n);
    //cout << m << endl;
    if(potencia(m, e, n) == c)
      return m;
  }
  assert(false);
}

int main()
{
  ll n, c, e;
  while(scanf(" %lld %lld %lld", &n, &e, &c) == 3){
    printf("%lld\n", solve(n, e, c));
  }
  return 0;
}
