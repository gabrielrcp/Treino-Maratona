#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1100

int p[MAX][MAX];
int a[MAX];
int n;
int vai(int l, int r)
{
  //printf("%d %d\n", l, r);
  if(l + 1 == r)
    return max(a[l], a[r]);
  if(p[l][r] != -1)
    return p[l][r];

  int x = a[l], y = a[r];
  if(a[l+1] >= a[r])
    x += vai(l+2, r);
  else
    x += vai(l+1, r-1);

  if(a[l] >= a[r-1])
    y += vai(l+1, r-1);
  else
    y += vai(l, r-2);

  p[l][r] = max(x, y);
  return p[l][r];
}


int main()
{
  for(int h = 1; ; h++){
    scanf(" %d", &n);
    if(n == 0)
      break;

    for(int i = 0; i < n; i++)
      scanf(" %d", a+i);

    for(int i = 0; i  < n; i++)
      for(int j = 0; j < n; j++)
	p[i][j] = -1;

    int x = 0;
    for(int i = 0; i < n; i++)
      x += a[i];

    x -= vai(0, n-1);
    x = vai(0, n-1) - x;
    printf("In game %d, ", h);
    printf("the greedy strategy might lose by as many as %d points.\n", x);
  }
  return 0;
}
