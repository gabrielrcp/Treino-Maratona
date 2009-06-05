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
no _nos[10*MAX];

no *novo()
{
  return &_nos[conta_no++];
}


void monta()
{
  no *at, *bt, *ct;
  conta_no = 0;
  queue<no *> Q;
  for(int i = 0; i < n; i++){
    at = novo();
    at->a = at->b = i;
    at->v = 0;
    at->e = at->d = NULL;
    Q.push(at);
  }

  while(1){
    at = Q.front(); Q.pop();
    if(Q.empty()){
      tree = at;
      return;
    }
    bt = Q.front(); Q.pop();
    ct = novo();
    ct->a = min(at->a, bt->a);
    ct->b = max(at->b, bt->b);
    ct->v = 0;
    ct->e = at;
    ct->d = bt;
    Q.push(ct);
  }
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

void imprime(no *arv)
{
  if(arv == NULL)
    return;

  printf("-- %d %d %d\n", arv->a, arv->b, arv->v);

  imprime(arv->e);
  imprime(arv->d);
}


int vai()
{
  int r = 1;

  monta();

  for(int i = n-1; i >= 0; i--){
    int at = maximo(v[i], n, tree) + 1;
    insere(at, v[i], tree);
      /*
    resp[i] = 1;
    for(int j = i + 1; j < n; j++)
      if(v[j] > v[i])
	resp[i] = max(resp[i], resp[j]+1);
      */
    r = max(r, at);
  }
  //imprime(tree);

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
