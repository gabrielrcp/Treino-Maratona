/* Diagonal */
/* UVA 10784 */
/* Accepted */

#include <stdio.h>

#define MAX 100000000

typedef long long int tipo;

int calcula(tipo t)
{
  int e, d, m;
  tipo v;
  e = 4; d = MAX -1;
  while(e < d){
    m = (e+d)/2;
    v = (tipo)m*(m-3)/2;
    if(v > t)
      d = m;
    else if(v < t)
      e = m + 1;
    else
      return m;
  }

  if(v > t)
    return e;
  return d;
}


int main()
{
  tipo i;
  int h;
  for(h=1; ; h++){
    scanf(" %lld", &i);
    if(i == 0)
      break;
    printf("Case %d: %d\n", h, calcula(i));
  }

  return 0;
}
