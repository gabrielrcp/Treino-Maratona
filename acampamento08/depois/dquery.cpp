#include <cstdio>
#include <algorithm>

using namespace std;

#define XMAX 1000010
#define MAX 30010


struct query{
  int ind;
  int j;
  struct query *prox;
};

int posx[XMAX];
int prox[MAX];

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
    for(int i = 0; i < XMAX; i++)
      posx[i] = -1;
    for(int i = 0; i <= n; i++){
      tree[i] = 0;
      quer[i].prox = NULL;
    }  
    cntq = 0;
    for(int i = 1; i <= n; i++){
      int x;
      scanf(" %d", &x);
      if(posx[x] == -1)
	atualiza(i, 1);
      else
	prox[posx[x]] = i;

      posx[x] = i;
      prox[i] = -1;
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
      atualiza(i, -1);
      if(prox[i] != -1)
	atualiza(prox[i], 1);
    }
        
    for(int i = 0; i < q; i++)
      printf("%d\n", resp[i]);
     
  }
  return 0;
}
