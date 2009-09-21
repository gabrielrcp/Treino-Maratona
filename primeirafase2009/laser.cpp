#include <cstdio>

#define MAX 10010

int n, h;

int v[MAX];

int resolve()
{
  int r = 0;
  for(int i = 1; i < n; i++)
    if(v[i] > v[i-1])
      r += v[i] - v[i-1];
  r += h - v[n-1];
  return r;
}

int main()
{
  while(scanf(" %d %d", &h, &n) && n && h){
    for(int i = 0; i < n; i++)
      scanf(" %d", v+i);
    printf("%d\n", resolve());
  }
  return 0;
}
