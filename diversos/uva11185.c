#include <stdio.h>


void imprime(long long n)
{
  if(n >= 3)
    imprime(n / 3LL);
  printf("%lld", n % 3LL);
}

int main()
{
  long long n;
  while(1)
    {
      scanf("%lld", &n);
      if(n < 0) break;
      imprime(n);
      putchar('\n');
    }
  return 0;
}
