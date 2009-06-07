#include <stdio.h>
#include <string.h>


char apagada[100];

int main()
{
  int n, m;
  int numap, at;
  int i;

  while(1)
    {
      scanf(" %d", &n);
      if(n == 0)
	break;

      for(m = 1; ; m++){
	memset(apagada, 0, n*sizeof(char));
	at = numap = 0;
	while(at != 12){
	  apagada[at] = 1;
	  numap++;
	  for(i=0; i < m; i++){
	    do{
	      at++;
	      if(at >= n)
		at -= n;
	    }while(apagada[at]);
	  }
	}
	if(numap == n - 1){
	  printf("%d\n", m);
	  break;
	}
      }

    }
  return 0;
}
