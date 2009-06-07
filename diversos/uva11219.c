#include <stdio.h>

typedef struct {
  int d, m, a;
} Data;

int dif(Data at, Data ns)
{
  if(ns.a > at.a || (ns.a == at.a && ns.m > at.m) ||
     (ns.a == at.a && ns.m == at.m && ns.d > at.d))
    return -1;

  ns.a++;
  return(dif(at, ns) + 1);
}

int main()
{
  int casos;
  int i;
  Data d[2];
  int x;
  int h;
  
  scanf(" %d", &casos);
  for(h = 1; h <= casos; h++){
    for(i = 0; i < 2; i++)
      scanf(" %d/%d/%d", &d[i].d, &d[i].m, &d[i].a);
    x = dif(d[0], d[1]);
    printf("Case #%d: ", h);
    if(x < 0)
      printf("Invalid birth date\n");
    else if(x > 130)
      printf("Check birth date\n");
    else
      printf("%d\n", x);
  }
  return 0;
}
