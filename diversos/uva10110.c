#include <stdio.h>


#define MAX 65536 /* 2^16 */

unsigned int qperf[MAX];


int acha(unsigned int v)
{
  int e, d, m;

  e = 0; d = MAX-1;
  while(e <= d)
    {
      m = (e+d)/2;
      if(qperf[m] == v)
	return 1;
      if(qperf[m] < v)
	e = m + 1;
      else
	d = m - 1;
    }
  return 0;
}

int main()
{
  unsigned int x;
  /*int i;*/
  for(x=1; x<MAX; x++)
    qperf[x-1] = x * x;
  
  /*
  for(i=0; i<10; i++)
    printf("%u\n", qperf[i]);
  */
  while(1)
    {
      scanf(" %u", &x);
      if(x == 0)
	break;
      if(acha(x))
	printf("yes\n");
      else
	printf("no\n");
    }
  return 0;
}
