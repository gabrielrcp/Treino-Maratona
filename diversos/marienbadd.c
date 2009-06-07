#include <stdio.h>
#include <stdlib.h>

int r[2][4][6][8][10][12];

void inicia()
{
  int i, j;
  int p[6];
  int term;

  for(p[0]=0; p[0]<2; p[0]++){
    for(p[1]=0; p[1]<4; p[1]++){
      for(p[2]=0; p[2]<6; p[2]++){
	for(p[3]=0; p[3]<8; p[3]++){
	  for(p[4]=0; p[4]<10; p[4]++){
	    for(p[5]=0; p[5]<12; p[5]++){
	      if(p[5] == 0 && p[4] == 0 && p[3] == 0  &&
		 p[2] == 0 && p[1] == 0 && p[0] == 0)
		term = 1;
	      else
		term = 0;
	      for(i=0; term == 0 && i < 6; i++){
		for(j=1; term == 0 && j <= p[i]; j++){
		  p[i] -= j;
		  if(r[p[0]][p[1]][p[2]][p[3]][p[4]][p[5]] == 0)
		    term = 1;
		  p[i] += j;
		}
	      }
	      r[p[0]][p[1]][p[2]][p[3]][p[4]][p[5]] = term;
	    }
	  }
	}
      }
    }
  }

}

int jogaGanha(int *p)
{
  return r[p[0]][p[1]][p[2]][p[3]][p[4]][p[5]];
}

int main()
{
  int n, h, i;
  int p[6];
  scanf(" %d", &n);
  inicia();
  for(h=1; h<=n; h++){
    for(i=0; i<6; i++)
      scanf(" %d", &p[i]);
    printf("Instancia %d\n%s\n\n", h, (jogaGanha(p) ? "sim" : "nao"));
  }
  return 0;
}
