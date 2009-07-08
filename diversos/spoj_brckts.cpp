#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 30010
int n;
char expr[MAX];

struct node{
  struct node *pai;
  struct node *esq, *dir;
  int abreesq;
  int fechadir;
};

node _nos[3*MAX];
int contano;
node *pont[MAX];

node *novo()
{
  return &_nos[contano++];
}

node *monta(int e, int d)
{
  node *arv = novo();
  if(e == d){
    if(expr[e] == '('){
      arv->abreesq = 0;
      arv->fechadir = 1;
    }
    else{
      arv->abreesq = 1;
      arv->fechadir = 0;
    }
    arv->esq = arv->dir = NULL;
    pont[e] = arv;
    return arv;
  }

  int m = (e+d)/2;
  node *esq, *dir;

  esq = monta(e, m);
  esq->pai = arv;
  dir = monta(m+1, d);
  dir->pai = arv;

  arv->abreesq = esq->abreesq + max(0, dir->abreesq - esq->fechadir);
  arv->fechadir = dir->fechadir + max(0, esq->fechadir - dir->abreesq);
  arv->esq = esq;
  arv->dir = dir;

  return arv;
  
}

node *monta()
{
  contano = 0;
  node *arv = monta(0, n-1);
  arv->pai = NULL;
  return arv;
}

bool checa(node *arv)
{
  return (arv->abreesq == 0 && arv->fechadir == 0);
}


void muda(node *atual)
{
  atual->abreesq = 1 - atual->abreesq;
  atual->fechadir = 1 - atual->fechadir;

  for(atual = atual->pai; atual != NULL; atual = atual->pai){
    node *esq = atual->esq;
    node *dir = atual->dir;
    atual->abreesq = esq->abreesq + max(0, dir->abreesq - esq->fechadir);
    atual->fechadir = dir->fechadir + max(0, esq->fechadir - dir->abreesq);
  }
}

int main()
{
  for(int h = 1; ;h++){
    if(feof(stdin)) break;
    if(scanf("%d", &n) == 0) break;
    if(feof(stdin)) break;
    
    scanf(" %s", expr);
    node *arv = monta();

    printf("Test %d:\n", h);

    int m;
    scanf(" %d", &m);
    while(m--){
      int k;
      scanf(" %d", &k);
      if(k == 0)
	printf("%s\n", (checa(arv) ? "YES" : "NO"));
      else
	muda(pont[k-1]);
    }    
  }
  return 0;
}
