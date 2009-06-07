/* UVA 10104 - Euclid Problem */
/* Accepted */


#include <stdio.h>

typedef long long int tipo;


tipo mdc(tipo a, tipo b, tipo *x, tipo *y)
{
  tipo t, d;
  if(a % b == 0){
    *x = 0;
    *y = 1;
    return b;
  }
  d = mdc(b, a % b, x, y);
  t = *x;
  *x = *y;
  *y = t - *x *(a/b);
  return d;
}


int main()
{
  tipo a, b, x, y, d;
  char troca;

  while(scanf(" %lld %lld", &a, &b) != EOF)
    {
      troca = 0;
      if(a < b){
	x = a;
	a = b;
	b = x;
	troca = 1;
      }

      d = mdc(a, b, &x, &y);
      if(troca){
	a = x;
	x = y;
	y = a;
      }

      printf("%lld %lld %lld\n", x, y, d);
    }
  return 0;
}
