#include <stdio.h>

typedef long long tipo;

tipo binomial(tipo n, tipo k)
{
  tipo i, b;
  if(2 * k > n)
    k = n - k;
  b = 1;
  for(i = 0; i < k; i++)
    b = ( b * (n - i)) / (i + 1);
  return b;
}

int main()
{
  tipo n, k;
  while(42)
    {
      scanf(" %lld %lld", &n, &k);
      if(n == k && k == 0)
	break;
      printf("%lld\n", binomial(n, k));
    }
  return 0;
}
