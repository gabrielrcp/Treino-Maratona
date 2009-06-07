/* Reverse and Add */
/* UVA 10018 */
/* Accepted */


#include <stdio.h>


unsigned int inverte(unsigned int n)
{
  unsigned int r = 0;

  while(n > 0)
    {
      r *= 10;
      r += n % 10;
      n /= 10;
    }
  return r;
}



int main()
{
  int casos;
  unsigned int n, t;
  int conta;

  scanf(" %d", &casos);
  while(casos--)
    {
      scanf("%u", &n);
      conta = 0;
      while(42)
	{
	  t = inverte(n);
	  if(t == n){
	    printf("%d %u\n", conta, n);
	    break;
	  }
	  n += t;
	  conta++;
	}
    }
  return 0;
}
