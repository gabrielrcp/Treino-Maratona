#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 500010

vector<int> T[MAX];
int tam[MAX];

char nehp[MAX];
int primos[50000];
int npr;


void crivo()
{
  memset(nehp, 0, MAX);
  for(int i = 2; i*i < MAX; i++){
    if(nehp[i])
      continue;
    for(int j = 2*i; j < MAX; j += i)
      nehp[j] = 1;
  }
  npr = 0;
  for(int i = 2; i < MAX; i++)
    if(!nehp[i])
      primos[npr++] = i;
}

int conta(int i)
{
  int r = 1;
  for(int k = 0; k < T[i].size(); k++)
    r += conta(T[i][k]);
  tam[i] = r;
  return r;
}

int n, m;
int potencias[MAX];


void fatorial(int num, int s)
{
  for(int k = 0; primos[k] <= num; k++){
    int pot = primos[k];
    int r = 0;
    while(pot <= num){
      r += num/pot;
      pot *= primos[k];
    }
    potencias[k] += s*r;
  }
}

long long potencia(int num, int pot)
{
  long long p = num;
  long long r = 1;
  for(int i = 0; (1 << i) <= pot; i++){
    if((1 << i) & pot)
      r = ((r*p)%m);
    p *= p;
  }
  return r;
}

long long coef(int i)
{
  memset(potencias, 0, npr*sizeof(int));
  fatorial(tam[i]-1, 1);
  for(int k = 0; k < T[i].size(); k++)
    fatorial(tam[T[i][k]], -1);

  long long r = 1;
  for(int k= 0; k < npr; k++)
    r = (r*potencia(primos[k], potencias[k]))%m;
  //printf("%d %lld\n", i, r);
  return r;
}


long long resolve(int i)
{
  
  if(T[i].size() <= 1)
    return 1;
  long long r = coef(i);

  for(int k = 0; k < T[i].size(); k++)
    r = (r*resolve(T[i][k]))%m;

  return r;
}


int main()
{
  int casos;
  crivo();

  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d", &n, &m);
    for(int i = 0; i < n; i++)
      T[i].clear();
    for(int k = 1; k < n; k++){
      int i;
      scanf(" %d", &i);
      T[i-1].push_back(k);
    }
    conta(0);
    printf("%lld\n", resolve(0));
  }
  
  return 0;
}
