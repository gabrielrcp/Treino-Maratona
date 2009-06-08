#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i;
  printf("%d\n%d %d\n", 1, 100000, 100000);
  for(i = 0; i < 100000; i++)
    printf("%d %d\n", rand()%100000, rand()%100000);
  return 0;
}
