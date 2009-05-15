#include <cstdio>
#include <algorithm>

using namespace std;


long long ler()
{
  long long a, b, c, d;
  scanf(" %lld.%lld.%lld.%lld", &a, &b, &c, &d);
  return ((a << 24) | (b << 16) | (c << 8) | d);
}

void imprime(long long x, int k)
{
  if(k != 0)
    imprime(x >> 8, k-1);
  long long mask = (1LL << 8) - 1LL;
  long long y = x & mask;  

  printf("%lld", y);
  if(k == 3)
    printf("\n");
  else
    printf(".");
}


void vai(long long a, long long b)
{

  if(a == b){
    imprime(a, 3);
    printf("255.255.255.255\n");
    return;
  }
  long long i;

  i = 1LL << 31;
  while((a & i) == (b & i))
    i = i | (i >> 1);
  i = i << 1;

  imprime(a & i,3);
  imprime(i, 3);
}

int main()
{
  int m;
  long long a, b;

  scanf(" %d", &m);

  b = -1;
  a = 1LL << 60;
  while(m--){
    long long x = ler();
    a = min(x, a);
    b = max(x, b);
  }
  vai(a, b);
  return 0;

}
