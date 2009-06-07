/* A Multiplication Game */
/* UVA 847  */
/* Accepted */

#include <stdio.h>
#include <string.h>

#define MAX 16777216
char vence[MAX];
unsigned long long int n;

char ganha(unsigned long long int p)
{
  unsigned long long int i;

  if(p >= n)
    return 0;
  if(p < MAX && vence[p] != -1)
    return vence[p];

  for(i=2; i<10; i++)
    if(ganha(i*p) == 0){
      if(p < MAX)
	vence[p] = 1;
      return 1;
    }
  if(p < MAX)
    vence[p] = 0;
  return 0;
}




int main()
{
  unsigned int l;
  while(scanf(" %llu", &n) > 0)
    {
      l = (n < MAX ? n : MAX);
      memset(vence, -1, l*sizeof(char));
      if(ganha(1))
	printf("Stan wins.\n");
      else
	printf("Ollie wins.\n");
    }
  return 0;
}
