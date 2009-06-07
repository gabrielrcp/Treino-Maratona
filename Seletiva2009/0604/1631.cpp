#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 40010

int v[MAX];
int n;

struct no{
  int a, b;
  int v;
  struct no *e;
  struct no *d;
};

no *tree;
int conta_no;
no _nos[3*MAX];

no *novo()
{
  return &_nos[conta_no++];
}


no *monta(int a, int b)
{
  no *x;

  if(a > b)
    return NULL;

  x = novo();
  x->a = a;
  x->b = b;
  x->v = 0;
  x->e = x->d = NULL;

  if(a == b)
    return x;

  int m = (a+b)/2;
  x->e = monta(a, m);
  x->d = monta(m+1, b);

  return x;
}

int maximo(int a, int b, no *arv)
{
  if(arv == NULL)
    return 0;
  if(b < arv->a || a > arv->b)
    return 0;
  if(a <= arv->a && b >= arv->b)
    return arv->v;

  return max(maximo(a, b, arv->e), maximo(a, b, arv->d));
}



void insere(int x, int i, no *arv)
{
  if(arv == NULL)
    return;

  if(arv->a <= i && i <= arv->b){
    arv->v = max(x, arv->v);
    insere(x, i, arv->e);
    insere(x, i, arv->d);
  }
}

int vai()
{
  int r = 1;
  
  conta_no = 0;
  tree = monta(0, n-1);

  for(int i = n-1; i >= 0; i--){
    int at = maximo(v[i], n-1, tree) + 1;
    insere(at, v[i], tree);
    r = max(r, at);
  }
  return r;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %d", v+i);
      v[i]--;
    }
    int r = vai();
    printf("%d\n", r);
  }
  
  return 0;
}
