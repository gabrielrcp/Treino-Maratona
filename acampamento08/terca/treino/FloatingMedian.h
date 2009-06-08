#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class FloatingMedian {
 public:
  long long sumOfMedians(int, int, int, int, int);
};

#define MAXV 65540

int num[250010];
int tree[MAXV];
int K;

void atualiza(int i, int v)
{
  while(i < MAXV){
    tree[i] += v;
    i += i & (-i);
  }
}

int consulta(int i){
  int r = 0;
  while(i > 0){
    r += tree[i];
    i -= i & (-i);
  }
  return r;
}


long long mediana()
{
  int e = 1, d = MAXV-1;
  int med = (K+1) / 2;
  //printf("%d\n", med);
  while(e < d){
    int m = (e + d)/2;
    if(consulta(m) >= med)
      d = m;
    else
      e = m + 1;
  }
  //printf("%d ", e-1);
  return e;
}

long long FloatingMedian::sumOfMedians(int seed, int mul, int add, int N, int _K) {
  long long soma = 0;
  K = _K;

  num[0] = seed;
  for(int i = 1; i < N; i++)
    num[i] = (int)(((long long)num[i-1] * mul + add) % 65536);
  /*
  for(int i = 0; i < N; i++)
    printf("%d ", num[i]);
  printf("\n");
  */
  for(int i = 0; i < MAXV; i++)
    tree[i] = 0;

  for(int i = 0; i < K; i++)
    atualiza(num[i]+1, 1);
  /*
  for(int i = 0; i<K; i++)
    printf("%d\n", consulta(num[i]+1));
  */
  soma = mediana()-1;
  for(int i = K; i < N; i++){
    atualiza(num[i]+1, 1);
    atualiza(num[i-K]+1, -1);
    soma += mediana()-1;
  }
  //printf("\n");
  return soma;
}
