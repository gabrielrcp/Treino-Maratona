#include <cstdio>

int calcula(int n)
{
  int r = 0;
  for(int p = 5; p <= n; p *= 5){
    r += n / p;
  }
  return r;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %d", &n);
    printf("%d\n", calcula(n));
  }
}
