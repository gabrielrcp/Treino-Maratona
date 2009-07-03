#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define EPS 1.0e-12

double calc(int n, int d, double a)
{
  double x = (double)n / d;
  x -= a;
  if(x < 0.0)
    x = -x;
  return x;
}

int main()
{
  double a;
  int l;
  scanf(" %lf %d", &a, &l);


  int rn = 1, rd = 1;
  int n;
  double erro = 1e100;
  double x;
  for(int d = 1; d <= l; d++){
    x = a * d;
    n = (int) (x+EPS);
    for(int t = max(1,n-1); t <= min(n+1, l); t++){
      if(calc(t, d, a) < erro){
	erro = calc(t, d, a);
	rd = d;
	rn = t;
      }
    }
  }

  printf("%d %d\n", rn, rd);

  return 0;
}
