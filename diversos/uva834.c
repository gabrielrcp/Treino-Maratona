#include <stdio.h>


int main()
{
  int n, d, t;
  char prim;
  while(scanf(" %d %d", &n, &d) > 0)
    {
      printf("[%d;", n/d);
      n %= d;
      t = n;
      n = d;
      d = t;
      prim = 1;
      while(n % d != 0)
	{
	  if(prim)
	    prim = 0;
	  else
	    putchar(',');
	  printf("%d", n/d);
	  n %= d;
	  t = n;
	  n = d;
	  d = t;
	}
      if(!prim)
	putchar(',');
      printf("%d]\n", n/d);
    }
  return 0;
}
