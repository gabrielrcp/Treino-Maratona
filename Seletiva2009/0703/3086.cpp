#include <cstdio>

long long memo[310];

inline long long T(int k)
{
  return k*(k+1) / 2;
}

int main()
{

  memo[0] = 0;
  for(long long n = 1; n <= 300; n++)
    memo[n] = memo[n-1] + n * T(n+1);

  int casos;
  int n;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &n);
    printf("%d %d %ld\n", h, n, memo[n]);
  }
  return 0;
}
