/* UVA 10004 - BICOLORING
   Accepted */

#include <stdio.h>

char grafo[200][200];
char cor[200];
int n;

int tentar(int p, char c)
{
  int i;
  if(cor[p] == c)
    return 1;
  if(cor[p] != -1 && cor[p] != c)
    return 0;
  cor[p] = c;
  for(i=0; i < n; i++)
    if(grafo[p][i] && (!tentar(i, 1-c))){
      cor[p] = -1;
      return 0;
    }
  return 1;
}


int main()
{
  int i, j;
  int l;
  while(scanf(" %d", &n) && n)
    {
      for(i=0; i<n; i++){
	for(j=0; j<n; j++)
	  grafo[i][j] = 0;
	cor[i] = -1;
      }
      scanf(" %d", &l);
      while(l--){
	scanf(" %d %d", &i, &j);
	grafo[i][j] = 1;
      }

      for(i=0; i<n; i++)
	if(tentar(i, 0) == 0 && tentar(i, 1) == 0)
	  break;
      if(i == n)
	printf("BICOLORABLE.\n");
      else
	printf("NOT BICOLORABLE.\n");
    }
  return 0;
}
