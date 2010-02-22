#include <cstdio>

int calc(int n)
{
  if(n == 0) return 4;
  int x = ((1<<n)+1);
  return x*x;
}

int main()
{
  int n;
  for(int h = 1; scanf(" %d", &n) && n >= 0; h++){
    printf("Teste %d\n%d\n\n", h, calc(n));
  }
  return 0;
}
