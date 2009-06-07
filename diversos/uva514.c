#include <stdio.h>


int PILHA[1000];
int topo;

int main()
{
  int n;
  int vetor[1000];
  int i;
  int prox, at;

  while(42)
    {
      scanf(" %d", &n);
      if(n == 0)
	break;

      while(42)
	{

	  scanf(" %d", vetor);
	  if(*vetor == 0){
	    putchar('\n');
	    break;
	  }

	  for(i=1; i<n; i++)
	    scanf(" %d", vetor+i);

	  prox = 1;
	  topo = 0;
	  at = 0;

	  while(42){
	    for(;prox <= vetor[at]; prox++)
	      PILHA[topo++] = prox;
	    if(PILHA[topo-1] == vetor[at]){
	      topo--;
	      at++;
	      if(at == n){
		printf("Yes\n");
		break;
	      }
	    }
	    else{
	      printf("No\n");
	      break;
	    }
	  }
	}
    }
  return 0;
}
