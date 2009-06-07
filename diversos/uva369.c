#include <stdio.h>

unsigned long combi[101][101];

int main()
{
  int n, m;

  for(n=0; n<=100; n++)
    combi[n][0] = combi[n][n] = 1;

  for(n=1; n<=100; n++)
    for(m=1; m < n; m++)
      combi[n][m] = combi[n-1][m-1] + combi[n-1][m];

  while(42)
    {
      scanf(" %d %d", &n, &m);
      if(n == m && m == 0)
	break;
      printf("%d things taken %d at a time is %lu exactly.\n"
	     , n, m, combi[n][m]);
    }
  return 0;
}
