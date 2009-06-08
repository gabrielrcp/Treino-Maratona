#include <cstdio>
#include <vector>
#include <cstdlib>

#define MAX 1000010

using namespace std;

bool crivo[MAX];
vector<int> primos;

int p[200];
int np;

struct node{
  int conta;
  struct node *prox[20];
};


void geraprimos()
{
  primos.clear();
  for(int i = 0; i <=MAX; i++)
    crivo[i] = true;
  for(int i = 2; i*i <= MAX; i++){
    if(!crivo[i]) continue;
    primos.push_back(i);
    for(int j = i+i; j <= MAX; j += i)
      crivo[j] = false;
  }
}

node *novo()
{
  node *arv = (node *)malloc(sizeof(node));
  for(int i = 0; i < 20; i++)
    arv->prox[i] = NULL;
  arv->conta = 0;
  return arv;
}

void fatora(int x)
{
  np = 0;
  for(int i = 0; x > 1; i++){
    p[i] = 0;
    int y = primos[i];
    while(x % y == 0){
      x /= y;
      p[i]++;
    }
    np++;
  }
}

void insere(int x, node *arv)
{
  fatora(x);
  node *at = arv;
  node *px;
  for(int i = 0; i < np; i++){
    if(at->prox[p[i]] == NULL)
      at->prox[p[i]] = novo();
    px = at->prox[p[i]];
    px->conta++;
    at = px;
  }
}

long long procura(int j, node *arv)
{
  if(arv == NULL)
    return 0LL;
  
  if(j == np)
    return arv->conta;

  long long r = 0;
  for(int i = p[j]; i < 20; i++)
    r += procura(j+1, arv->prox[i]);
  return r;
}


int main()
{
  int n, m;
  geraprimos();
  //printf("%d\n", primos.size());

  while(scanf(" %d", &n) == 1){
    node *arv = novo();
    int x;
    for(int i = 0; i < n; i++){
      scanf(" %d", &x);
      if(x != 1)
	insere(x, arv);
    }
    scanf(" %d", &m);
    long long r = 0;
    for(int i = 0; i < m; i++){
      int b;
      scanf(" %d", &b);
      if(b == 1)
	r += (long long)n;
      else{
	fatora(b);
	long long t = procura(0, arv);
	
	r += t;
      }
    }
    printf("%lld\n", r);

  }
  return 0;
}
