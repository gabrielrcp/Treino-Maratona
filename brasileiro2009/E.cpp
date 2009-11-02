#include <cstdio>
#include <algorithm>

using namespace std;

#define INF (1LL<<60)

typedef long long ll;

ll qtd[4] = {100, 10000-100, 1000000 - 10000, INF};
ll preco[4] = {2, 3, 5, 7};

ll gastei(ll pago)
{
  ll r = 0;
  for(int i = 0; i < 4; i++){
    //printf("%d %d\n", pago, r);
    if(preco[i]*qtd[i] >= pago){
      r += pago / preco[i];
      return r;
    }
    r += qtd[i];
    pago -= preco[i] * qtd[i];
  }
  return r;
}

ll pagar(ll gasto)
{
  ll r = 0;
  for(int i = 0; i < 4; i++){
    if(gasto > 0){
      r += preco[i] * min(gasto, qtd[i]);
      gasto = max(0LL, gasto - qtd[i]);
    }
  }
  return r;
}

ll resolve(ll a, ll b)
{
  ll soma = gastei(a);
  ll e = 0, d = soma;
  while(e <= d){
    ll meu = (e+d)/2;
    ll viz = soma - meu;
    ll dif = pagar(viz) - pagar(meu);
    
    if(dif == b) return pagar(meu);
    if(dif < b)
      d = meu - 1;
    else
      e = meu + 1;
  }
  return -1;
}

int main()
{
  int a, b;
  while(scanf(" %d %d", &a, &b) && a && b)
    printf("%lld\n", resolve(a, b));
  return 0;
}
