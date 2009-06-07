/*
ID: gabriel9
LANG: C
TASK: ttwo
*/

#include <stdio.h>

char mapa[10][10];
char passou[10][10][10][10][3][3][3][3];
int fx, fy;
int dfx, dfy;
int cx, cy;
int dcx, dcy;


int main()
{
  int i, j;
  char c;
  unsigned int conta;

  FILE *fin = fopen("ttwo.in", "r");
  FILE *fout = fopen("ttwo.out", "w");
 
  
  for(i=9; i>=0; i--){
    for(j=0; j<10; j++){
  
      do{
	c = getc(fin);
      }while(c != '*' && c != 'F' && c != '.' && c != 'C');
  
      if(c == '*')
	mapa[j][i] = 1;
      else if(c == 'F'){
	fx = j;
	fy = i;
      }
      else if(c == 'C'){
	cx = j;
	cy = i;
      }
      
    }
  }

  dfx = dcx = 0;
  dfy = dcy = 1;

  conta = 0;
  
  /*
  for(i=0; i<10; i++){
    for(j=0; j<10; j++)
      if(mapa[i][j])
	putc('*', stderr);
      else
	putc('.', stderr);
    putc('\n', stderr);
  }
  */  


  while(42){
    if(passou[fx][fy][cx][cy][dfx+1][dfy+1][dcx+1][dcy+1]){
      fprintf(fout, "0\n");
      /*fprintf(stderr, "%u\n", conta);*/
      return 0;
    }
    passou[fx][fy][cx][cy][dfx+1][dfy+1][dcx+1][dcy+1] = 1;
  

    if(fx + dfx < 10 && fx + dfx >= 0 && fy + dfy < 10 && fy + dfy >= 0
       && mapa[fx + dfx][fy + dfy] == 0){
      fx += dfx;
      fy += dfy;
    }
    else{
      int t = dfx;
      dfx = dfy;
      dfy = -t;
    }

    if(cx + dcx < 10 && cx + dcx >= 0 && cy + dcy < 10 && cy + dcy >= 0
       && mapa[cx + dcx][cy + dcy] == 0){
      cx += dcx;
      cy += dcy;
    }
    else{
      int t = dcx;
      dcx = dcy;
      dcy = -t;
    }
    conta++;

    if(fx == cx && fy == cy){
      fprintf(fout, "%u\n", conta);
      return 0;
    }
  }
  
  return 0;
}
