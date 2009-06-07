/* Stacks of Flapjacks */
/* UVA 120 */
/* Accepted */

#define DEBUG 1
#if DEBUG
#define debug(x) x
#else
#define debug(x)
#endif

#include <stdio.h>
#include <ctype.h>


int vetor[32];
int n;
#if DEBUG
int conta, contamax;
#endif


void vira(int p)
{
  int i=0;

  while(i < p){
    int t = vetor[i];
    vetor[i] = vetor[p];
    vetor[p] = t;
    i++; p--;
  }
  debug(conta++;)
}

int ler()
{
  char buffer[500];
  char *c;

  if(fgets(buffer, 490, stdin) == NULL)
    return 0;

  for(c=buffer; *c != '\0'; c++)
    if(*c == '\n'){
      *c = '\0';
      break;
    }

  c = buffer;
  while(isspace(*c))
    c++;
  if(*c == '\0')
    return 0;

  n = 1;
  sscanf(c, "%d", vetor);
  while(42)
    {
      while(*c >= '0' && *c <= '9')
	c++;
      while(isspace(*c))
	c++;
      if(*c == '\0')
	return 1;
      sscanf(c, " %d", vetor+n);
      n++;
    }
}

int ordenado()
{
  int i;
  for(i=1; i<n; i++)
    if(vetor[i-1] > vetor[i])
      return 0;
  return 1;
}

int main()
{
  int i, max;
  int passos;

  debug(contamax = 0;)
  while(ler())
    {
      printf("%d", *vetor);
      for(i=1; i<n; i++)
	printf(" %d", vetor[i]);
      putchar('\n');
      passos = 0;
      debug(conta = 0;)
      while(!ordenado())
	{
	  max = 0;
	  for(i=1; i < n; i++)
	    if(vetor[i] > vetor[max])
	      max = i;
	  if(max != n - 1)
	    {
	      if(max != 0){
		printf("%d ", n-max+passos);
		vira(max);
	      }
	      printf("%d ", passos+1);
	      vira(n-1);
	    }
	  n--;
	  passos++;
	}
      printf("0\n");
#if DEBUG
      if(conta > contamax)
	contamax = conta;
#endif
    } 
  debug(fprintf(stderr, "Máximo de viradas: %d\n", contamax);) 
  return 0;
}
