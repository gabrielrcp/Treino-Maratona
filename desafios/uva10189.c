/* Minesweeper */
/* UVA 10189 */
/* Accepted */

#include <stdio.h>

#define MAX 102

char campo[MAX][MAX];

int calcula(int a, int b)
{
  int r = 0;
  int i, j;

  for(i=a-1; i<=a+1; i++)
    for(j=b-1; j<=b+1; j++)
      if((i != a || j != b) && campo[i][j])
	r++;

  return r; 
}


int main()
{
  int n, m;
  int i, j;
  char c;
  int h;

  for(h=1; ; h++)
    {
      scanf(" %d %d", &n, &m);
      if(n == m && m == 0)
	break;
      for(i=0; i<=n+1; i++){
	campo[i][0] = 0;
	campo[i][m+1] = 0;
      }
      for(j=0; j<=m+1; j++){
	campo[0][j] = 0;
	campo[n+1][j] = 0;
      }
      for(i = 1; i <= n; i++)
	for(j = 1; j <= m; j++)
	  {
	    do{
	      c = getchar();
	    }while(c != '*' && c != '.');
	    campo[i][j] = ((c == '*') ? 1 : 0);
	  }

      if(h != 1)
	putchar('\n');
      printf("Field #%d:\n", h);
      for(i = 1; i <= n; i++){
	for(j = 1; j <= m; j++)
	  if(campo[i][j])
	    putchar('*');
	  else
	    printf("%d", calcula(i, j));
	putchar('\n');
      } 
    }

  return 0;
}
