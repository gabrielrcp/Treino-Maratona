//errado!
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 100010
typedef long long ll;
#define INF (1<<30)

struct retangulo{
  int id;
  int x1, y1, x2, y2;
  ll v, resp;
};

retangulo rect[MAX];
int n;

struct node{
  int e, d;
  int im;
  node *esq, *dir;
};

node _nos[50*MAX];
int contano;

bool cmp_x(const retangulo &a, const retangulo &b)
{
  if(a.x1 == b.x1)
    return a.y1 < b.y1;
  return a.x1 < b.x1;
}

bool cmp_y(const retangulo &a, const retangulo &b)
{
  if(a.y1 == b.y1)
    return a.x1 < b.x1;
  return a.y1 < b.y1;
}

bool compara(const retangulo &a, const retangulo &b)
{
 
  if(a.x1 < b.x2 && a.y1 < b.y2)
    return true;
  if(b.x1 < a.x2 && b.y1 < a.y2)
    return false;

 if(a.y1 == b.y1)
    return a.x1 < b.x1;
  return a.y1 < b.y1;
}


node *monta(retangulo *v, int n, int k)
{
  if(n == 0)
    return NULL;

  node *arv = &_nos[contano++];
  if(n == 1){
    int x = ((k == 0) ? v[0].x1 : v[0].y1);
    arv->e = arv->d = x;
    arv->im = -1;
    arv->esq = arv->dir = NULL;
    return arv;
  }

  int m = n/2;
  arv->e = INF;
  arv->d = -INF;

  if(k == 0){
    for(int i = 0; i < n; i++){
      arv->e = min(arv->e, v[i].x1);
      arv->d = max(arv->d, v[i].x1);
    }
    nth_element(v, v+m, v+n, cmp_x);
  } else{
    nth_element(v, v+m, v+n, cmp_y);
    for(int i = 0; i < n; i++){
      arv->e = min(arv->e, v[i].y1);
      arv->d = max(arv->d, v[i].y1);
    }
  }

  arv->im = -1;
  arv->esq = monta(v, m, 1-k);
  arv->dir = monta(v+m, n-m, 1-k);
  return arv;
}

//buscar o indice do retangulo melhor
int busca(int x, int y, node *arv, int k, bool dx, bool dy)
{
  if(arv == NULL)
    return -1;

  int c = ((k == 0) ? x : y);

  if(arv->d <= c)
    return -1;
  if(c < arv->e){
    if(k == 0) dx = true;
    else dy = true;
    if(dx && dy)
      return arv->im;
  }

  if(arv->esq == NULL && arv->dir == NULL)
    return arv->im;

  int i = busca(x, y, arv->esq, 1-k, dx, dy);
  int j = busca(x, y, arv->dir, 1-k, dx, dy);
  if(i == -1) return j;
  if(j == -1) return i;
  if(rect[i].resp > rect[j].resp)
    return i;
  return j;
}

void insere(int i, node *arv, int k)
{
  if(arv == NULL) return;
  int x = ((k==0) ? rect[i].x1 : rect[i].y1);
  if(arv->e <= x && x <= arv->d){
    int &j = arv->im;
    if(j == -1 || (rect[j].resp < rect[i].resp))
      j = i;    
    insere(i, arv->esq, 1-k);
    insere(i, arv->dir, 1-k);
  }
}

void imprime(node *arv, int k)
{
  if(arv != NULL){
    printf("k=%d %d %d %d\n", k, arv->e, arv->d, arv->im);
    imprime(arv->esq, 1-k);
    imprime(arv->dir, 1-k);
  }
}

int proximo[MAX];

int main()
{
  //freopen("rects.in", "r", stdin);
  //freopen("rects.out", "w", stdout);
 
  contano = 0;
  scanf(" %d", &n);
  for(int i = 0; i < n; i++){
    scanf(" %d %d %d %d %lld", &rect[i].x1, &rect[i].y2,
	  &rect[i].x2, &rect[i].y1, &rect[i].v);
    rect[i].id = i;

    rect[i].y1 = -rect[i].y1;
    rect[i].y2 = -rect[i].y2;
  }

  node *arv = monta(rect, n, 0);
  sort(rect, rect+n, compara);

  memset(proximo, -1, sizeof proximo);
    
  for(int i = n-1; i>= 0; i--){
    int j = busca(rect[i].x2, rect[i].y2, arv, 0, false, false);
       
    if(j != -1)
      fprintf(stderr, "(%d, %d) -> (%d, %d)\n", rect[i].x2, rect[i].y2, 
	      rect[j].x1, rect[j].y1);
    
    rect[i].resp = rect[i].v;
    if(j != -1)
      rect[i].resp += rect[j].resp;
    insere(i, arv, 0);
    proximo[i] = j;
  }

  int i = arv->im;
  printf("%lld\n", rect[i].resp);
  for(; i != -1; i = proximo[i]){
    printf("%d", rect[i].id+1);
    if(proximo[i] != -1)
      printf(" ");
    //printf("%d %d %d %d\n", x1, y1, x2, y2);
  }
  printf("\n");

  return 0;
}
