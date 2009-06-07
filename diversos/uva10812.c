#include <stdio.h>

int main()
{
  int s, d, n;

  scanf(" %d", &n);
  while(n--)
    {
      scanf(" %d %d", &s, &d);
      if(s < d || (s + d) % 2 == 1 || (s - d) % 2 == 1)
	printf("impossible\n");
      else
	printf("%d %d\n", (s+d)/2, (s-d)/2);
    }
  return 0;
}
