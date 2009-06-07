#include <stdio.h>

int main()
{
  long long n;
  long long t = (1 << 8) - 1;

  while(!feof(stdin) && scanf(" %d", &n) > 0){
    long long a, b, c, d;
    a = n & t;
    b = n & (t << 8);
    c = n & (t << 16);
    d = n & (t << 24);
    printf("%d converts to ", n);
    printf("%d\n", (a << 24) + (b << 8) + (c >> 8) + (d >> 24));
  }
  return 0;
}
