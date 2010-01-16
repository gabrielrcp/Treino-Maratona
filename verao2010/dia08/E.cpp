// errado, olhar o certo no dia 11

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
#define MAX 100010

struct ponto{
  int x, y;
  double ang;
};

int N;
ponto pts[MAX];

bool comp(const ponto &a, const ponto &b)
{
  return a.ang < b.ang;
}

struct node{
  double ini, fim;
  node *esq, *dir;
  int *fecho;
  int tam;
};

node _nos[3*MAX];
int numno;

int vetorzao[30*MAX];
int vlivre;

node *novo()
{
  node *arv = &_nos[numno++];
  arv->esq = arv->dir = NULL;
  return arv;
}

ll prod(int i, int j, int k)
{
  ll x1 = pts[j].x - pts[i].x;
  ll y1 = pts[j].y - pts[i].y;
  ll x2 = pts[k].x - pts[i].x;
  ll y2 = pts[k].y - pts[i].y;
  return x1*y2 - x2*y1;
}

ll prod(ponto a, ponto b)
{
  return (ll)a.x*b.y - (ll)b.x*a.y; 
}

bool dentro(ponto a, ponto b, ponto c)
{
  if(a.ang > b.ang)
    swap(a, b);
  b.x -= a.x;
  b.y -= a.y;
  c.x -= a.x;
  c.y -= a.y;
  return (prod(b, c) > 0);
}

node *monta(int i, int j)
{
  if(i > j) return NULL;
  node *arv = novo();
  int tam = 1;
  int *fecho = vetorzao+vlivre;
  fecho[0] = i;
  for(int k = i+1; k <= j; k++){
    while(tam > 1 && prod(fecho[tam-1], fecho[tam-2], k) <= 0)
      tam--;
    fecho[tam++] = k;
  }
  vlivre += tam;
  /*
  printf("%d-%d\n",i, j);
  for(int k = 0; k < tam; k++)
    printf("%d %d\n", pts[fecho[k]].x, pts[fecho[k]].y);
  printf("\n");
  */

  arv->fecho = fecho;
  arv->tam = tam;
  arv->ini = pts[i].ang;
  arv->fim = pts[j].ang;
  if(i < j){
    int meio = (i + j) / 2;
    arv->esq = monta(i, meio);
    arv->dir = monta(meio+1, j);
  }
  return arv;
}

bool busca(ponto a, ponto b, int *fecho, int tam)
{
  /*
  for(int i = 0; i < tam; i++)
    printf("%d %d\n", pts[fecho[i]].x, pts[fecho[i]].y);
  */
  if(dentro(a, b, pts[*fecho]))
    return true;
  if(tam >= 2)
    return dentro(a, b, pts[fecho[1]]);

  int e = 0, d = tam-1;
  int r = 0;
  ponto inc = (ponto){b.x-a.x, b.y-a.y};
  while(e < d){
    int m = (e+d)/2;
    ponto aa = pts[fecho[m]];
    ponto bb = pts[fecho[m+1]];
    ponto at = (ponto){bb.x-aa.x, bb.y-aa.y};
    if(prod(inc, at) < 0){
      r = m;
      d = m - 1;
    }else
      e = m + 1;
  }
  //printf("%d %d\n", pts[fecho[r]].x, pts[fecho[r]].y);
  return dentro(a, b, pts[fecho[r]]);
}

bool resolve(ponto a, ponto b, node *arv)
{
  if(arv == NULL) return false;
  if(arv->fim < a.ang || arv->ini > b.ang) return false;
 
  if(a.ang < arv->ini && arv->fim < b.ang)
    return busca(a, b, arv->fecho, arv->tam);
  else{
    if(resolve(a, b, arv->esq))
      return true;
    return resolve(a, b, arv->dir);
  }
}


int main()
{
  int M;
  scanf(" %d %d", &N, &M);
  for(int i = 0; i < N; i++){
    scanf(" %d %d", &pts[i].x, &pts[i].y);
    pts[i].ang = atan2(pts[i].y, pts[i].x);
  }
  sort(pts, pts+N, comp);
  numno = 0;
  vlivre = 0;
  node *arv = monta(0, N-1);

  while(M--){
    ponto a, b;
    scanf(" %d %d %d %d", &a.x, &a.y, &b.x, &b.y);
    a.ang = atan2(a.y, a.x);
    b.ang = atan2(b.y, b.x);
    if(comp(b, a))
      swap(a, b);
    printf("%c\n", (resolve(a, b, arv) ? 'Y' : 'N'));
  }
  
  return 0;
}
