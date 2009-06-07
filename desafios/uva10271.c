/* UVA 10271 - Chopsticks
   Accepted */

#include <stdio.h>

#define MAXN 1020
#define MAXM 5010

#define INFI 2147448648

int n, m;

int comp[MAXM];
int memoriza[MAXN][MAXM];

int calcula(int conj, int ini)
{
  /*int i;*/
  int a, b;

  if(conj == 0)
    return 0;
  if(ini >= m)
    return INFI;

  if(m - ini < 3 * conj)
    return INFI;

  if(memoriza[conj][ini] != -1)
    return memoriza[conj][ini];

  
  a = (comp[ini] - comp[ini+1]);
  a *= a;
  a += calcula(conj-1, ini+2);

  b = calcula(conj, ini+1);
  if(a < b)
    memoriza[conj][ini] = a;
  else
    memoriza[conj][ini] = b;
  return memoriza[conj][ini];
}


int main()
{
  int casos;
  int i, j;

  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d", &n, &m);
    n += 8;
    for(i = 0; i < m; i++)
      scanf(" %d", comp+i);
    for(i = 0; i <=n; i++)
      for(j = 0; j <= m; j++)
	memoriza[i][j] = -1;
    printf("%d\n", calcula(n, 0));
  }
  return 0;
}
