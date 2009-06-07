#include <stdio.h>
#include <string.h>

#define MAX 1000000

int main()
{
  int n;
  char s[MAX];
  int i, j, tam, k;
  char *c, *d;
  char padrao[12];
  int conta, max;
  char *saida;
  char visto[MAX];

  while(scanf(" %d", &n) > 0)
    {
      scanf(" %s", s);
      tam = strlen(s);

      memset(visto, 0, tam*sizeof(char));

      saida = NULL;
      max = 0;
      for(i=0; i+n <= tam; i++)
	{
	  
	  if(visto[i])
	    continue;
	  visto[i] = 1;
	  
	  c = s + i;
	  for(j=0; j<n; j++)
	    padrao[j] = c[j];
	  padrao[n] = '\0';

	  conta  = 1;
	  
	  while(1){
	    d = strstr(c, padrao);
	    if(d == NULL)
	      break;
	    
	    k = d - s;
	    visto[k] = 1;
	    
	    conta++;
	    c = ++d;
	  }
	  if(conta > max){
	    max = conta;
	    saida = s + i;
	  }	  
	}
      
      for(i=0; i<n; i++)
	putchar(saida[i]);
      putchar('\n');
      
      /*printf("%d\n", max);*/
    }
  return 0;
}
