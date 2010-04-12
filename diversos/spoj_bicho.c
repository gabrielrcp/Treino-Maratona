#include <stdio.h>

int grupo(int x)
{
  x = ((x+99)%100);
  return x/4;
}

int main()
{
  double v, r;
  int n, m;

  while(1){
    scanf(" %lf %d %d", &v, &n, &m);
    if(v < 0.005 && n == 0 && m == 0) break;
    double r;

    if((n % 10000) == (m%10000))
      r = 3000.0*v;
    else if((n % 1000) == (m%1000))
      r = 500.0*v;
    else if((n % 100) == (m%100))
      r = 50.0*v;
    else if(grupo(n) == grupo(m))
      r = 16.0*v;
    else
      r = 0;
    printf("%.2f\n", r);
  }
  return 0;
}
