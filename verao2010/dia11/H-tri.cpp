#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 100010
typedef long long ll;

struct ponto{
  int x, y;
};

ponto pts[MAX];

int vetorzao[30*MAX];
int vlivre;

struct node{
  node *esq, *dir;
  int ini, fim;
  int *fecho;
  int tam;
};

node _nos[5*MAX];
int numno;


ponto novopt(int x, int y)
{
  ponto p;
  p.x = x;
  p.y = y;
  return p;
}

ll left(ponto a, ponto b)
{
  return ((ll)a.x*b.y - (ll)b.x*a.y);
}

ll left(int i, int j, int k)
{
  ponto a, b;
  a.x = pts[j].x - pts[i].x;
  a.y = pts[j].y - pts[i].y;
  b.x = pts[k].x - pts[j].x;
  b.y = pts[k].y - pts[j].y;
  return left(a, b);
}

bool comp (const ponto &a, const ponto &b)
{
  return left(a, b) > 0;
}


node *monta(int i, int j)
{
  if(i > j) return NULL;
  
  int tam = 1;
  int *fecho = vetorzao + vlivre;
  fecho[0] = i;
  for(int k = i+1; k <= j; k++){
    while(tam > 1 && left(fecho[tam-2], fecho[tam-1], k) >= 0){
      tam--;
    }
    fecho[tam++] = k;
  }
  vlivre += tam;
  /*
  printf("%d %d\n", i, j);
  for(int k = 0; k < tam; k++)
    printf("%d %d\n", pts[fecho[k]].x, pts[fecho[k]].y);
  printf("\n");
  */
  node *arv = &_nos[numno++];
  arv->esq = arv->dir = NULL;
  arv->ini = i;
  arv->fim = j;
  arv->fecho = fecho;
  arv->tam = tam;

  if(i < j){
    int m = (i+j)/2;
    arv->esq = monta(i, m);
    arv->dir = monta(m+1, j);
  }

  return arv;
}

bool dentro(ponto a, ponto b, ponto c)
{
  b.x -= a.x;
  b.y -= a.y;
  c.x -= a.x;
  c.y -= a.y;
  return (left(b, c) >= 0);
}

bool busca(ponto aa, ponto bb, int *fecho, int tam)
{

  //printf("%d %d\n", fecho[0], fecho[tam-1]);
  ponto a = aa, b = bb;

  if(tam == 1)
    return dentro(a, b, pts[fecho[0]]);
  if(tam == 2)
    return (dentro(a, b, pts[fecho[0]]) || dentro(a, b, pts[fecho[1]]));

  b.x -= a.x;
  b.y -= a.y;  
  int e = 0, d = tam-1;
  int r = d;
  while(e < d){
    int m = (e+d)/2;
    a.x = pts[fecho[m+1]].x - pts[fecho[m]].x;
    a.y = pts[fecho[m+1]].y - pts[fecho[m]].y;
    if(left(b, a) < 0){
      r = m;
      d = m - 1;
    }else
      e = m + 1;
  }

  //printf("%d\n", fecho[r]);
  for(int k = max(0, r-5); k < min(tam, r+6); k++)
    if(dentro(aa, bb, pts[fecho[k]]))
       return true;
  return false;
}

bool resolve(ponto a, ponto b, node *arv)
{
  if(arv == NULL) return false;

  //printf("%d %d\n", arv->ini, arv->fim);
  if(left(a, pts[arv->ini]) >= 0 && left(pts[arv->fim], b) >= 0){
    //printf("entrei!\n");
    return busca(a, b, arv->fecho, arv->tam);
  }

  //printf("%d %d\n", arv->ini, arv->fim);
  if(left(b, pts[arv->ini]) > 0 || left(pts[arv->fim], a) > 0){
    //printf("sai!\n");
    return false;
  }
  return (resolve(a, b, arv->esq) || resolve(a, b, arv->dir));
}


int main()
{
  int casos;
  scanf(" %d", &casos);

  while(casos--){
    int N, M;
    scanf(" %d %d", &N, &M);
    
    for(int i = 0; i < N; i++){
      int x, y;
      scanf(" %d %d", &x, &y);
      pts[i] = novopt(x, y);
    }

    sort(pts, pts+N, comp);
    numno = 0;
    vlivre = 0;

    node *arv = monta(0, N-1);

    while(M--){
      int x1, y1, x2, y2;
      scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
      ponto a = novopt(x1, y1);
      ponto b = novopt(x2, y2);
      if(comp(b, a)) swap(a, b);
      printf("%c\n", (resolve(a, b, arv) ? 'Y' : 'N'));
    }
  }
  return 0;
}
