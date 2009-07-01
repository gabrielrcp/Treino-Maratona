#include <cstdio>
#include <cstdlib>

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

    int n;
    scanf(" %d", &n);
    int x = 0, y = 0;
    int e = 0, a = 0;
    for(int i = 1; i <= n; i++){
      int dx, dy;

      scanf(" %d %d", &dx, &dy);
      e += mdc(abs(dx), abs(dy));

      int z = x + dx;
      int w = y + dy;

      a += z*y - w*x;
      
      x = z;
      y = w;
    }
    a = abs(a);
    int i = (a - e + 2) / 2;

    printf("Scenario #%d:\n", h);
    printf("%d %d ", i, e);
    if(a % 2 == 1)
      printf("%d.5", a/2);
    else
      printf("%d.0", a/2); 
    printf("\n\n");
  }
  return 0;
}
