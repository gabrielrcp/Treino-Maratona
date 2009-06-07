/* Rails */
/* UVA 514 */
/* Accepted */

#include <stdio.h>

#define MAX 1000

int pilha[MAX];
int topo;

int sai[MAX];

int proximo;
int indat;

int n;

void empilha(int x)
{
  pilha[topo++] = x;
}


int desempilha()
{
  topo--;
  return pilha[topo];
}

int vazia()
{
  return (topo == 0);
}

int main()
{
  int i;

  while(42)
    {
      scanf(" %d", &n);
      if(n == 0)
	break;

      while(42)
	{
	  scanf(" %d", sai);
	  if(*sai == 0)
	    break;
	  for(i=1; i<n; i++)
	    scanf(" %d", &sai[i]);
	  topo = 0;
	  indat = 0;
	  proximo = 1;
	  while(indat < n)
	    {
	      while(sai[indat] >= proximo && proximo <= n){
		empilha(proximo);
		proximo++;
	      }
	      if(sai[indat] == desempilha())
		indat++;
	      else
		break;
	    }
	  if(indat == n)
	    printf("Yes\n");
	  else
	    printf("No\n");
	    
	}
      putchar('\n');
    }
  return 0;  
}
