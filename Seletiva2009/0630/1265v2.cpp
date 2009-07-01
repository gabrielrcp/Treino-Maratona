#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int mat[220][220];



int n;
int x[110], y[110];

int area()
{
  int r = 0;
  for(int i = 1; i <= n; i++)
    r += x[i-1]*y[i] - y[i-1]*x[i];
  if(r < 0)
    return -r;
  return r;
}

int mdc(int a, int b)
{
  if(a > b) return mdc(b, a);
  if(a == 0) return b;
  return mdc(b%a, a);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    printf("Scenario #%d:\n", h);

    int e = 0;
    scanf(" %d", &n);
    x[0] = y[0] = 110;
    for(int i = 1; i <= n; i++){
      int dx, dy;
      scanf(" %d %d", &dx, &dy);
      x[i] = x[i-1] + dx;
      y[i] = y[i-1] + dy;
      e += mdc(abs(dx), abs(dy));
    }





    printf("%d ", e);

    int a = area();
    if(a % 2 == 0)
      printf("%d.0\n\n", a/2);
    else
      printf("%d.5\n\n", a/2);
  }
  return 0;
}
