#include <stdio.h>

int main()
{
  int t, n;
  int s, x;
  char buf[20];

  while(scanf(" %d", &t) && t){
    scanf(" %d", &n);
    s = 0;
    while(t--){
      scanf(" %s %d", buf, &x);
      s += x;
    }
    printf("%d\n", 3*n-s);
  }
  return 0;
}
