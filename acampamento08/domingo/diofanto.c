#include <stdio.h>

long long L = 1300031;

long long vai(long long n, long long k)
{
  long long a = 1LL, b = 1LL;
  long long i;
  if(2LL * k > n)
    k = n - k;
  /*
  for(i = 1; i <= k; i++){
    a *= n-i+1;
    a %= L;
    b *= i;
    b %= L;
    r *= n - i + 1;
    r %= L;
    while(r % i)
      r += L;
    r /= i;
    r %= L;
  }
  return r;
  */
  for(i = 1LL; i <= k; i++){
    a *= n - i + 1LL;
    a %= L;
    b *= i;
    b%= L;
  }
  while(a % b)
    a += L;
  return ((a/b)%L);
}

int main()
{
  int h, n, c;
  scanf(" %d", &h);
  while(h--){
    scanf(" %d %d", &n, &c);
    printf("%lld\n", vai(c+n-1, n-1));
  }
  return 0;
}
