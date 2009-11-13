#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100010

typedef long long ll;

ll pontos[MAX][2];
int ordem[MAX];

struct node{
  ll pt[2];
  node *esq, *dir;
};

bool cmpx(const int &a, const int &b)
{
  return pontos[a][0] < pontos[b][0];
}

bool cmpy(const int &a, const int &b)
{
  return pontos[a][1] < pontos[b][1];
}

node _nos[MAX];
int contano;


node *novo()
{
  node *nv = &_nos[contano++];
  return nv;
}

node *monta(int *v, int n, int ct)
{

  if(n == 0)
    return NULL;

  int k = n/2;
  /*
  if(ct == 0)
    sort(v, v+n, cmpx);
  else
    sort(v, v+n, cmpy);
  */
  if(ct == 0)
    nth_element(v, v+k, v+n, cmpx);
  else
    nth_element(v, v+k, v+n, cmpy);


  node *nv = novo();
  nv->pt[0] = pontos[v[k]][0];
  nv->pt[1] = pontos[v[k]][1];

  nv->esq = monta(v, k, 1-ct);
  nv->dir = monta(v+k+1, n-k-1, 1-ct);
  return nv;
}

ll pt[2];
ll md;

void vai(node *arv, int ct)
{
  if(arv == NULL)
    return;

  ll dx = arv->pt[0] - pt[0];
  ll dy = arv->pt[1] - pt[1];

  ll d = dx*dx + dy*dy;
  if(d > 0 && md > d)
    md = d;

  ll dist = pt[ct] - arv->pt[ct];
  dist *= dist;
  if(pt[ct] > arv->pt[ct]){
    vai(arv->dir, 1-ct);
    if(dist <= md)
      vai(arv->esq, 1-ct);
  } else{
    vai(arv->esq, 1-ct);
    if(dist <= md)
      vai(arv->dir, 1-ct);
  }
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %lld %lld", &pontos[i][0], &pontos[i][1]);
      ordem[i] = i;
    }

    contano = 0;
    node *arv = monta(ordem, n, 1);
    for(int i = 0; i < n; i++){
      md = (1LL << 62);
      pt[0] = pontos[i][0];
      pt[1] = pontos[i][1];
      vai(arv, 1);
      printf("%lld\n", md);
    }
  }
  return 0;
}
