/*
 * Primeira fase da maratona 2014
 * Problema: baralho
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4657
 * Resposta: AC
 */

#include <cstdio>
#include <cstring>

using namespace std;

#define MAX (200010)

typedef long long ll;

int v[MAX];
char vis[MAX];

ll gcd(ll a, ll b)
{
  if(a < b) return gcd(b, a);
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll mmc(ll a, ll b)
{
  return a*b/gcd(a, b);
}

int new_pos(int i, int n)
{
  if(i < n)
    return 2*i + 1;
  return 2*(i-n);
}

int go(int i)
{
  if(vis[i]) return 0;
  vis[i] = 1;
  return go(v[i]) + 1;
}

int main()
{
  int p;
  while(scanf(" %d", &p) == 1){
    for(int i = 0; i < p; i++)
      v[i] = new_pos(i, p/2);
    memset(vis, 0, p*sizeof(char));
    
    ll r = 1;
    for(int i = 0; i < p; i++){
      ll t = go(i);
      if(t != 0)
	r = mmc(r, t);
    }
    printf("%lld\n", r);
  }

  return 0;
}
