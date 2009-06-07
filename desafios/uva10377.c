/* Maze Transversal */
/* UVA 10377 */
/* Accepted */

#include <stdio.h>


char labirinto[60][60];
int l, c;

int la, ca; /*linha e coluna atual*/
int da; /* direcao atual {0, 1, 2, 3} = {N, W, S, E} */
char direcoes[4] = {'N', 'W', 'S', 'E'};

int main()
{
  int n;
  int i, j;
  char temp;


  scanf(" %d", &n);

  while(n--)
    {
      scanf(" %d %d", &l, &c);
      for(i = 0; i < l; i++)
	for(j = 0; j < c; j++){
	  do{
	    temp = getchar();
	  }while(temp != ' ' && temp != '*');
	  labirinto[i][j] = temp;
	}

      scanf(" %d %d", &la, &ca);
      la--; ca--;
      da = 0;


      do{
	temp = getchar();
	switch(temp)
	  {
	  case 'R':
	    da--;
	    if(da == -1)
	      da = 3;
	    break;
	  case 'L':
	    da++;
	    if(da == 4)
	      da = 0;
	    break;
	  case 'F':
	    switch(da)
	      {
	      case 0:
		if(la > 0 && labirinto[la-1][ca] == ' ')
		  la--;
		break;
	      case 1:
		if(ca > 0 && labirinto[la][ca-1] == ' ')
		  ca--;
		break;
	      case 2:
		if(la + 1 < l && labirinto[la+1][ca] == ' ')
		  la++;
		break;
	      case 3:
		if(ca + 1 < c && labirinto[la][ca+1] == ' ')
		  ca++;
		break;

	      }
	    break;
	  default:
	    break;
	  }
      }while(temp != 'Q');

      printf("%d %d %c\n", la+1, ca+1, direcoes[da]);
      if(n > 0)
	putchar('\n');
    }

  return 0;
}
