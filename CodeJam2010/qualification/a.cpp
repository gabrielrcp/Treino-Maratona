#include <cstdio>

bool estado(int n, int k)
{
  k %= (1<<n);
  return (k == ((1<<n)-1));
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int n, k;
    scanf(" %d %d", &n, &k);
    printf("Case #%d: %s\n", h, (estado(n, k) ? "ON" : "OFF"));
  }
  return 0;
}
