/*
 * http://acm.uva.es/p/v3/350.html
*/


#include <stdio.h>

#define MAX 10000

unsigned int usado[MAX];

int main()
{
  unsigned int z, i, m, l;
  int h, k;
  unsigned int tam;

  for(h=1; ; h++){
    scanf(" %u %u %u %u", &z, &i, &m, &l);
    if(z == 0 && i == 0 && m == 0 && l == 0)
      break;
    for(k=0; k<MAX; k++)
      usado[k] = 0;
    tam = 1;
    while(!usado[l]){
      usado[l] = tam++;
      l *= z;
      l += i;
      l %= m;
    }
    printf("Case %d: %u\n", h, tam - usado[l]);
  }
  return 0;
}
