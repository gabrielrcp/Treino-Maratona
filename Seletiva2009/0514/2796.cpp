#include <cstdio>

#define MAX 100010

int PILHA[MAX];
int numel;

inline void insere(int x)
{
  PILHA[numel] = x;
  numel++;
}

inline bool vazia()
{
  return numel == 0;
}

inline int topo()
{
  return PILHA[numel-1];
}

inline int retira()
{
  numel--;
  return PILHA[numel];
}

int n;
int v[MAX];

int dir[MAX], esq[MAX];
long long somacum[MAX];


inline long long soma(int i, int j)
{
  return somacum[j] - somacum[i-1];
}

int main()
{
  scanf(" %d", &n);
  for(int i = 1; i <= n; i++)
    scanf(" %d", v+i);
  v[0] = v[n+1] = -1;

  numel = 0;
  for(int i = 1; i <= n; i++){
    while((!vazia()) && v[topo()] > v[i]){
      int j = retira();
      dir[j] = i;
    }
    insere(i);
  }
  while(!vazia()){
    int j = retira();
    dir[j] = n+1;
  }

  for(int i = n; i >= 1; i--){
    while((!vazia()) && v[topo()] > v[i]){
      int j = retira();
      esq[j] = i;
    }
    insere(i);
  }
  while(!vazia()){
    int j = retira();
    esq[j] = 0;
  }


  somacum[0] = 0;
  for(int i = 1; i <= n; i++)
    somacum[i] = somacum[i-1] + v[i];

  long long m = -1;
  int e, d;
  for(int i = 1; i <= n; i++){
    long long r = soma(esq[i]+1, dir[i]-1) * (long long)v[i];
    if(m < r){
      m = r;
      e = esq[i] + 1;
      d = dir[i] - 1;
    }
  }

  printf("%lld\n%d %d\n", m, e, d);
  return 0;
}
