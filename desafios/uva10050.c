/* UVA 10050 - Hartals */
/* Accepted */


#include <stdio.h>

char livre[3660];
int h[100];

int main()
{
  int t, n, p;
  int i, j;
  int conta;


  scanf(" %d", &t);
  while(t--)
    {
      scanf(" %d %d", &n, &p);
      for(i=0; i<n; i++)
	if((i % 7 == 5) || (i % 7 == 6))
	  livre[i] = 0;
	else
	  livre[i] = 1;
      
      for(i=0; i<p; i++)
	scanf(" %d", h+i);

      conta = 0;
      for(i=0; i<p; i++)
	for(j=h[i] - 1; j < n; j += h[i])
	  {
	    if(livre[j]){
	      livre[j] = 0;
	      conta++;
	    }
	  }
      printf("%d\n", conta);
    }
  return 0;
}
