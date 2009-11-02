// Solucao usando vetor de sufixos com radix sort
// Complexidade O(n lg n )
// Usando o sort da STL e adicionando mais um log, levei TLE
// Mas o Ribas passou desse jeito.

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100010
#define LMAX 20

char S[MAX];
int n;

int P[LMAX][MAX];
int lim;
int sar[MAX];

struct node{
  int v;
  node *prox;
};

node buf[3*MAX];
int bufp;

node *lista[2][MAX];

inline int insere(int k, int i, int v)
{
  node *novo = &buf[bufp++];
  novo->v = v;
  novo->prox = lista[k][i];
  lista[k][i] = novo;
}

void monta()
{
  for(int i = 0; i < n; i++)
    P[0][i] = S[i] + 1;

  int pot = 1;
  bool para = false;
  int cnt = 300;
  for(lim = 1; !para; lim++){
    
    for(int i = 0; i <= cnt; i++)
      lista[0][i] = lista[1][i] = NULL;
    bufp = 0;

    for(int i = 0; i < n; i++){
      if(i + pot >= n)
	insere(0, 0, i);
      else
	insere(0, P[lim-1][i+pot], i);
    }

    for(int i = cnt; i >= 0; i--)
      for(node *it = lista[0][i]; it != NULL; it = it->prox)
	insere(1, P[lim-1][it->v], it->v);
	     
    para = true;
    int ncnt = 0;
    for(int i = 0; i <= cnt; i++){
      int ult = -1;
      for(node *it = lista[1][i]; it != NULL; it = it->prox){
	int at = ((it->v+pot>=n) ? 0 : P[lim-1][it->v + pot]);
	if(at != ult)
	  ncnt++;
	else
	  para = false;
	P[lim][it->v] = ncnt;
	ult = at;
      }
    }
    if(!para)
      cnt = ncnt;
    pot <<= 1;
  }

  //printf("%d\n", cnt);
  int k = 0;
  for(int i = 0; i <= cnt; i++)
    for(node *it = lista[1][i]; it != NULL; it = it->prox)
      sar[k++] = it->v;
}

int iguais(int i, int j)
{
  int k = lim - 1;
  int r = 0;
  while(k >= 0 && i < n && j < n){
    if(P[k][i] == P[k][j]){
      r += (1 << k);
      i += (1 << k);
      j += (1 << k);
    }
    k--;
  }
  return r;
}

int resolve()
{
  int r = 0;
  int ant = 0;
  for(int i = 0; i+1 < n; i++){
    int t = iguais(sar[i], sar[i+1]);
    if(t > ant)
      r += t - ant;
    ant = t;
  }
  return r;
}

int main()
{
  while(1){
    scanf(" %s", S);
    if(*S == '*')
      break;
    n = strlen(S);

    monta();
    /*
    for(int i = 0; i < n; i++)
      printf("%2d %s\n", sar[i], S+sar[i]);
    */
    printf("%d\n", resolve());
  }
  return 0;
}
