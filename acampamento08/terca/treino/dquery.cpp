#include <cstdio>
#include <algorithm>

using namespace std;

#define XMAX 1000010
#define MAX 30010

struct no{
  int v;
  struct no *prox;
  struct no *ult;
};

struct query{
  int ind;
  int j;
  struct query *prox;
};

int posx[XMAX];
no lista[MAX];
no temp[MAX];
int cnt;

int tree[MAX];
int resp[200010];

query quer[MAX];
query tmpcon[200010];
int cntq;

void atualiza(int i, int v)
{
  /*
  if(v == 1)
    printf("entrou");
  else
    printf("saiu");
  printf(" %d\n", i);
  */
  while(i < MAX){
    tree[i] += v;
    i += i & (-i);
  }
}

int consulta(int i)
{
  int r = 0;
  while(i > 0){
    r += tree[i];
    i -= i & (-i);
  }
  return r;
}

no *novo()
{
  cnt++;
  return &temp[cnt-1];
}

query *novaq(int ind, int j)
{
  tmpcon[cntq].ind = ind;
  tmpcon[cntq].j = j;
  tmpcon[cntq].prox = NULL;
  cntq++;
  return &tmpcon[cntq-1];
}


int main()
{
  int n;
  while(scanf(" %d", &n) == 1){
    for(int i = 0; i < XMAX; i++){
      posx[i] = -1;
    }
    for(int i = 0; i <= n; i++){
      lista[i].prox = lista[i].ult = NULL;
      tree[i] = 0;
      quer[i].prox = NULL;
    }  
    cnt = 0; cntq = 0;
    for(int i = 1; i <= n; i++){
      int x;
      scanf(" %d", &x);
      if(posx[x] == -1){
	posx[x] = i;
	lista[i].v = x;
	lista[i].prox = novo();
	lista[i].ult = lista[i].prox;
	lista[i].prox->v = i;
	lista[i].prox->prox = NULL;
	atualiza(i, 1);
      }
      else{
	int j = posx[x];
	no *at = lista[j].ult;
	at->prox = novo();
	at->prox->v = i;
	at->prox->prox = NULL;
	lista[j].ult = at->prox;
	lista[i].prox = lista[i].ult = at->prox;
	lista[i].v = x;
      }
    }
    /*
    for(int i = 1; i <= n; i++){
      printf("%d -", i);
      no *at = lista[i].prox;
      while(at != NULL){
	printf(" %d", at->v);
	at = at->prox;
      }
      printf("\n");
      }
    */
    int q;
    scanf(" %d", &q);
    for(int k = 0; k < q; k++){
      int i, j;
      scanf(" %d %d", &i, &j);
      query *qr = quer[i].prox;
      quer[i].prox = novaq(k, j);
      quer[i].prox->prox = qr;
    }
    

    for(int i = 1; i <= n; i++){
      for(query *qr = quer[i].prox; qr != NULL; qr = qr->prox)
	resp[qr->ind] = consulta(qr->j);
      no *at = lista[i].prox;
      atualiza(i, -1);
      if(at->prox != NULL)
	atualiza(at->prox->v, 1);
    }
        
    for(int i = 0; i < q; i++)
      printf("%d\n", resp[i]);
     
  }
  return 0;
}
