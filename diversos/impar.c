#include <stdio.h>
#include <string.h>

#define MAX 100

int numm[MAX];
int numj[MAX];
char usado[MAX];

int main()
{
  int n;
  int i, j;
  int conta;
  while(42)
    {
      scanf(" %d", &n);
      if(n == 0)
	break;

      for(i=0; i<n; i++)
	usado[i] = 0;

      for(i=0; i<n; i++)
	scanf(" %d", numm+i);
      for(i=0; i<n; i++)
	scanf(" %d", numj+i);

      conta = 0;
      for(i=0; i<n; i++)
	for(j=0; j<n; j++)
	  if((!usado[j]) && (numj[i] + numm[j]) % 2 == 1){
	    usado[j] = 1;
	    conta++;
	    break;
	  }

	printf("%d\n", n-conta);
    }
  return 0;
}
