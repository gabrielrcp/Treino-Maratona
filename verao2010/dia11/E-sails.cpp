// errado/incompleto

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100050
typedef long long ll;
typedef pair<int, int> pii;

int N;
pii valores[MAX];

struct node{
  ll v;
  int mx;
  int a, b;
  node *esq, dir;
};

node _nos[5*MAX];
int numno;

node *monta(int i, int j)
{
  if(i > j) return NULL;
  node *arv = &_nos[numno++];
  arv->v = 0;
  arv->a = i;
  arv->b = j;
  arv->esq = arv->dir = NULL;
  if(i < j){
    int m = (i+j)/2;
    arv->esq = monta(i, m);
    arv->dir = monta(m+1, j);
  }
  return arv;
}

void update(int i, int j, int v, node *arv)
{
  if(arv == NULL) return;
  if(i <= arv->a && arv->b <= j){
    arv->v += v;
    return;
  }
  if(arv->a <= i && j <= arv->b)
    arv->v += v;
  if(arv->a > j || i > arv->b)
    return;
  update(i, j, v, arv->esq);
  update(i, j, v, arv->dir);
}

int get(int i, int j, node *arv)
{
  if(arv == NULL) return 0;
  if(i <= arv->a && arv->b <= j){
    return arv->v;
  }
  if(arv->a > j || i > arv->b)
    return 0;
  return update(i, j, v, arv->esq) + update(i, j, v, arv->dir);
}

int inicio(int x, node *arv)
{
  if(arv->v < x
}

int maior;

void adiciona(int k, int h, node *arv)
{
  //printf("%d -- ", maior);
  int p = maior;
  if(p + k-1 <= h){
    update(p, p+k-1, 1);
    update(pos(p-1), -1);
    maior = p + k;
    //printf("\n");
    return;
  }
  p = h - (k-1);
  int x = get(p, p);

  int p1 = inicio(x);
  int p2 = min(inicio(x-1), h+1);

  int k2 = h - p2+1;
  int k1 = k - k2;

  update(pos(p2+k2-1), 1);
  update(pos(p2-1), -1);
  update(pos(p1+k1-1), 1);
  update(pos(p1-1), -1);
  maior = h + 1;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &N);
    for(int i = 0; i < N; i++)
      scanf(" %d %d", &valores[i].first, &valores[i].second);
    sort(valores, valores+N);

    numno = 0;
    maior = 1;
    node *arv = monta(1, N);
    for(int i = 0; i < N; i++){
      int k = v[i].second, h = v[i].first;
      adiciona(k, h, arv);
    }
    
    ll r = 0;
    for(int x = 1; x <= 100000; x++){
      ll at = get(x, x);
      //printf("%d %lld\n", x, at);
      r += at * (at-1)/2;
    }
    printf("%lld\n", r);

  }
  return 0;
}
