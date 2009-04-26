#include <cstdio>

int main()
{
  int n = 40;
  printf("%d %d\n", n*n*(n-1), n);
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      for(int k = 1; k < n; k++)
	printf("%d %d %d\n", i, j, k);
  printf("%d %d\n", 0, 0);
  return 0;
}
