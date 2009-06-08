#include <stdio.h>

int main()
{
  long long n, i, r;
  while(1){
    scanf(" %lld", &n);
    if(n == 0) return 0;
    r = 0;
    for(i = 0; i < n; i++)
      r += (n - i) * (n - i);
    printf("%lld\n", r);
  }
}
