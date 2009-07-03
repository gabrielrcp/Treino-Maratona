#include <cstdio>

long long limites[11] = {-1, 1000010, 1010, 500, 100, 100, 100, 100, 100, 100, 100};


long long potencia(int a, int n)
{
  long long r = 1;
  for(int i = 0; i < n; i++)
    r *= a;
  return r;
}

long long busca(int n, long long b)
{
  long long e = 0, d = limites[n]+1;
  while(e < d){
    long long m = (e+d)/2;
    if(potencia(m, n) > b)
      d = m;
    else
      e = m + 1;
  }
  return e-1;
}


int main()
{
  int n;
  long long a, b;

  while(1){
    scanf(" %lld %d", &b, &n);
    if(n == b && b == 0)
      break;

    a = busca(n, b);
    if(b - potencia(a, n) > potencia(a+1, n) - b)
      a++;
    printf("%lld\n", a);
  }


  return 0;
}
