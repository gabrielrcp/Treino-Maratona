#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
  node *esq, *dir;
};

node _nos[2000];
int contano;

node *novo()
{
  node *nv = &_nos[contano++];
  nv->esq = nv->dir = NULL;
  return nv;
}

long long mask;
int at;

node *monta()
{
  node *nv = novo();
  if(at >= 0 && (mask & (1LL<<at))){
    at--;
    nv->esq = monta();
    nv->dir = monta();
  }
  else
    at--;
  return nv;
}

pair<long long, int> codifica(node *arv)
{
  if(arv->esq == NULL)
    return make_pair(0LL, 1);

  pair<long long, int> a1 = codifica(arv->esq);
  pair<long long, int> a2 = codifica(arv->dir);

  int t1 = a1.second;
  int t2 = a2.second;

  long long n1 = a1.first;
  long long n2 = a2.first;

  return make_pair((1LL<<(t1+t2)) + (n1<<t2) + n2, t1+t2+1);
}


node *primeiro(int n)
{
  node *nv = novo();
  if(n == 1)
    return nv;
  nv->esq = novo();
  nv->dir = primeiro(n-2);
  return nv;
}



bool proximo_menos(node *arv)
{
  if(arv->esq == NULL)
    return false;

  if(proximo_menos(arv->dir))
    return true;

  if(arv->dir->esq == NULL)
    return proximo_menos(arv->esq);
 
  arv->dir = novo();

  node *mudar = arv->esq;
  while(mudar->dir != NULL)
    mudar = mudar->dir;
  mudar->esq = novo();
  mudar->dir = novo();

  return true;
}

bool proximo(node *arv)
{
  if(arv->esq == NULL)
    return false;

  if(proximo(arv->dir))
    return true;

  if(arv->dir->esq == NULL){
    int n = codifica(arv->esq).second;
    if(!proximo_menos(arv->esq))
      return false;
    arv->dir = primeiro(n - codifica(arv->esq).second +1);
    return true;
  }

  arv->dir = primeiro(codifica(arv->dir).second - 2);
  node *mudar = arv->esq;
  while(mudar->dir != NULL)
    mudar = mudar->dir;
  mudar->esq = novo();
  mudar->dir = novo();

  return true;
}

int maissig(long long num)
{
  int r = 0;
  while(num){
    num >>= 1;
    r++;
  }
  r--;
  return r;
}

int main()
{
  
  int casos;
  scanf(" %d", &casos);
  while(casos--){
  
    contano = 0;

    scanf(" %lld", &mask);
    at = maissig(mask);

    node *arv = monta();
    int n = codifica(arv).second;
    if(!proximo(arv))
      arv = primeiro(n);

    printf("%lld\n", codifica(arv).first);
    if(casos)
      printf("\n");

  }
    
  return 0;
}
