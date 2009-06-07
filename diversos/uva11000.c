#include <stdio.h>

#define MAX 1000

unsigned int femeas[MAX];
unsigned int machos[MAX];


int main()
{
  int n;
  int i;

  femeas[0] = 1;
  machos[0] = 0;


  for(i=1; i<MAX; i++){
    /* F -> M
     * M -> M F
     */
    femeas[i] = machos[i] = 0;
    machos[i] = femeas[i-1] + machos[i-1];
    femeas[i] = machos[i-1] + 1;
  }

  while(1)
    {
      scanf(" %d", &n);
      if(n == -1)
	break;
      printf("%u %u\n", machos[n], machos[n] + femeas[n]);
    }
  
  return 0;
}
