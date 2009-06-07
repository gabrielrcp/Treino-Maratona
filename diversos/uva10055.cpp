#include <cstdio>

typedef long long ll;

int main()
{
  ll x, y;
  while(!feof(stdin) && scanf(" %lld %lld", &x, &y) > 0){
    x -= y;
    if(x < 0LL)
      x = -x;
    printf("%lld\n", x);
  }
  return 0;
}
