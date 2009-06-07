/* UVA 10003 - Cutting Sticks
   Accepted */

#include <stdio.h>

#define MAX 1010
#define MAXN 55

#define INFI 1073741824

int l, n;
int c[MAXN];

int memoriza[MAXN][MAXN];

int calcula(int ini, int fim)
{
  int i;
  int min, t;

  if(ini + 1>= fim)
    return 0;

  if(memoriza[ini][fim] != -1)
    return memoriza[ini][fim];

  min = INFI;

  for(i = 1; i < fim - ini; i++){
    t = calcula(ini, ini + i) + calcula(ini + i, fim);
    if(t < min)
      min = t;
  }

  memoriza[ini][fim] = min + c[fim] - c[ini];
  return memoriza[ini][fim];
}



int main()
{
  int i, j;

  while(scanf(" %d", &l) && l){
    scanf(" %d", &n);
    c[0] = 0;
    for(i = 1; i <= n; i++)
      scanf(" %d", c+i);

    for(i = 0; i <= n + 1; i++)
      for(j = 0; j <= n + 1; j++)
	memoriza[i][j] = -1;

    c[n+1] = l;
    printf("The minimum cutting is %d.\n", calcula(0, n+1));
  }
  return 0;
}
