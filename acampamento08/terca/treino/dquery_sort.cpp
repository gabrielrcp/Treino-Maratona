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

int posx[XMAX];
no lista[MAX];
no temp[MAX];
int cnt;

int tree[MAX];
pair< pair<int, int>, int> querys[200010];
int resp[200010];


void atualiza(int i, int v)
{
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
    }
    
    cnt = 0;
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
    //printf("%d\n", q);
    
    for(int k = 0; k < q; k++){
      int i, j;
      scanf(" %d %d", &i, &j);
      querys[k] = make_pair(make_pair(i, j), k);
    }
    
    sort(querys, querys+q);
    /*
    for(int i = 0; i < q; i++)
      printf("--%d\n", querys[i].first.first);
    */

    int pri = 1;
    for(int i = 0; i < q; i++){
      while(pri < querys[i].first.first){
	no *at = lista[pri].prox;
	atualiza(pri, -1);
	//printf("saiu %d\n", pri);
	if(at->prox != NULL){
	  //printf("entrou %d\n", at->prox->v);
	  atualiza(at->prox->v, 1);
	  //printf("%d\n", at->prox->v);
	}
	pri++;
      }
      resp[querys[i].second] = consulta(querys[i].first.second);
    }
    
    for(int i = 0; i < q; i++)
      printf("%d\n", resp[i]);
     
  }
  return 0;
}
