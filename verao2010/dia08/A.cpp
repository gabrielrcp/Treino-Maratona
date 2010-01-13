#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define MAX 100010

vector<pii> G[MAX];

ll dist[MAX];
int n;
ll S[MAX], V[MAX];

ll resp[MAX];

struct reta{
  ll a, b;
  ll x0;
};

reta pilha[MAX];
int topo;


ll busca(ll x)
{
  int e = 1, d = topo - 1;
  int r = 0;
  while(e <= d){
    int m = (d+e)/2;
    if(pilha[m].x0 <= x){
      r = m;
      e = m + 1;
    } else
      d = m - 1;
  }
  //printf("--%d %lld %lld\n", r, pilha[r].a, pilha[r].b);
  return (pilha[r].a * x + pilha[r].b);
}

ll cruza(reta x, reta y)
{
  ll num = y.b - x.b;
  ll den = x.a - y.a;
  if(den < 0){
    den = -den;
    num = -num;
  }
  if(num < 0)
    return num;
  ll r = num/den;
  if(num % den != 0) r++;
  return r;
}

int busca2(reta nova)
{
  int e = 0, d = topo-1;
  int r = topo;
  while(e <= d){
    int m = (e+d)/2;
    ll c = cruza(nova, pilha[m]);
    if(pilha[m].x0 < c){ // mantem a reta m
      e = m + 1;
    } else{
      r = m;
      d = m - 1;
    }
  }
  return r;
}


void dfs(int i, int p)
{
  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k].first;
    if(j == p) continue;
    int d = G[i][k].second;
    dist[j] = dist[i] + d;
  }


  if(i == 0){
    for(int k = 0; k < (int)G[i].size(); k++){
      int j = G[i][k].first;
      if(j == p) continue;
      dfs(j, i);
    }
    return;
  }

  //busca pela resposta
  resp[i] = (ll)S[i] + dist[i] * V[i];
  if(topo > 0){
    //printf("%d ", i);
    resp[i] = min(resp[i], (ll)S[i] + V[i]*dist[i] + busca(V[i]));
    //printf("%d %lld\n", i, resp[i]);
  }

  if(G[i].size() == 0) return;

  //insere a resposta na estrutura
  reta nova = (reta){-dist[i], resp[i], 0};
  int vltopo = topo;
  topo = busca2(nova);
  if(topo > 0)
    nova.x0 = cruza(nova, pilha[topo-1]);
  reta velha = pilha[topo];
  pilha[topo] = nova;
  topo++;

  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k].first;
    if(j == p) continue;
    dfs(j, i);
  }

  // retira da estrutura
  topo--;
  pilha[topo] = velha;
  topo = vltopo;
}


int main()
{
  int casos = 1;
  //scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      G[i].clear();
    for(int i = 1; i < n; i++){
      int a, b, d;
      scanf(" %d %d %d", &a, &b, &d);
      a--; b--;
      G[a].push_back(make_pair(b, d));
      G[b].push_back(make_pair(a, d));
    }
    for(int i = 1; i < n; i++)
      scanf(" %lld %lld", S+i, V+i);

    topo = 0;
    dist[0] = resp[0] = 0;
    dfs(0, -1);
    for(int i = 1; i < n; i++){
      if(i != 1)
	putchar(' ');
      printf("%lld", resp[i]);
    }
    puts("");
  }
  return 0;
}
