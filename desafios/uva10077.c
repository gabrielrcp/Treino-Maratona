/* The Stern-Brocot Number System */
/* UVA 10077 */
/* Accepted */

#include <stdio.h>

int n, d;


int compara(int n1, int d1, int n2, int d2)
{
  return (n1*d2 - n2*d1);
}


void imprime(int n1, int d1, int n2, int d2)
{
  int nm, dm;

  nm = n1 + n2;
  dm = d1 + d2;
  if(nm == n && dm == d)
    return;
  if(compara(n, d, nm, dm) <  0){
    putchar('L');
    imprime(n1, d1, nm, dm);
  }
  else{
    putchar('R');
    imprime(nm, dm, n2, d2);
  }
}



int main()
{
  while(42)
    {
      scanf(" %d %d", &n, &d);
      if(n == d && d == 1)
	break;
      if(n == d)
	putchar('I');
      else
	imprime(0, 1, 1, 0);
      putchar('\n');
	
    }
  return 0;
}
