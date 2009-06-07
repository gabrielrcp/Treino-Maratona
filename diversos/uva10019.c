#include <stdio.h>

int main()
{
  int n;
  int m;
  int b1, b2;
  int t, d;

  scanf(" %d", &n);

  while(n--)
    {
      scanf(" %d", &m);
      b1 = 0; b2 = 0;

      t = m;
      while(t){
	if(t % 2)
	  b1++;
	t /= 2;
      }

      while(m){
	d = m % 10;
	m /= 10;
	while(d){
	  if(d % 2)
	    b2++;
	  d /= 2;
	}
      }
      printf("%d %d\n", b1, b2);
    }
  return 0;
}
