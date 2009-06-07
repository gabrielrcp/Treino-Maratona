/* Bridge */
/* UVA 10037  */
/* Accepted */

#include <stdio.h>

int tp[1000];

int main()
{
  int casos;
  int n, faltam;
  int i;

  int a, b, c, d;
  int t1, t2;
  int total;

  scanf(" %d", &casos);

  while(casos--)
    {
      scanf(" %d", &n);
      for(i=0; i<n; i++)
	scanf(" %d", tp+i);
      total = 0;
      faltam = n;

      while(faltam > 0)
	{
	  if(faltam > 3){
	    a = tp[0]; b= tp[1]; c = tp[faltam-2]; d = tp[faltam-1];
	    t1 = b + a + d + b;
	    t2 = d + a + c + a;
	    if(t1 < t2)
	      total += t1;
	    else
	      total += t2;
	    faltam -= 2;
	  }
	  else if(faltam == 3){
	    total += tp[0] + tp[1] + tp[2];
	    faltam -= 3;
	  }
	  else if(faltam == 2){
	    total += tp[1];
	    faltam -= 2;
	  }
	  else{
	    total += tp[0];
	    faltam--;
	  }
	}
      
      printf("%d\n", total);
      faltam = n;

      while(faltam > 0)
	{
	  if(faltam > 3){
	    a = tp[0]; b= tp[1]; c = tp[faltam-2]; d = tp[faltam-1];
	    t1 = b + a + d + b;
	    t2 = d + a + c + a;
	    if(t1 < t2)
	      printf("%d %d\n%d\n%d %d\n%d\n", a, b, a, c, d, b);
	    else
	      printf("%d %d\n%d\n%d %d\n%d\n", a, d, a, a, c, a);
	    faltam -= 2;
	  }
	  else if(faltam == 3){
	    printf("%d %d\n%d\n%d %d\n", tp[0], tp[1], tp[0], tp[0], tp[2]);
	    faltam -= 3;
	  }
	  else if(faltam == 2){
	    printf("%d %d\n", tp[0], tp[1]);
	    faltam -= 2;
	  }
	  else{
	    printf("%d\n", *tp);
	    faltam--;
	  }
	}

      if(casos)
	putchar('\n');

    }
  return 0;
}
