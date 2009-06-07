#include <cstdio>

int main()
{
  int t, v;
  while(!feof(stdin) && scanf(" %d %d", &v, &t) > 0){
    printf("%d\n", 2*v*t);
  }
  return 0;
}
