/*
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=3436
 * USER: 6414
 */

#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int predios[10][10];

double x0, y0, z0;

int estavendo(double xp, double yp, double zp)
{
  int i, j;
  double x, y, z;
  double max, min;

  /* Se nao estao na mesma linha , verifico*/
  if(xp != x0){
    if(xp > x0){
      max = xp;
      min = x0;
    }
    else{
      max = x0;
      min = xp;
    }
    for(x = floor(min + EPS) + 1; x < max; x += 1){
      i = floor(x + EPS);
      
      y = (x - x0)*(yp - y0)/(xp - x0) + y0;
      j = floor(y + EPS);

      z = (x - x0)*(zp - z0)/(xp - x0) + z0;
      /*
      if(i == 0 || i == 10)
	fprintf(stderr, "Naaaaoooo!!\n");
      */
      if((double)predios[i][j] > z)
	return 0;
      if((double)predios[i-1][j] > z)
	return 0;
    }
  }
    

  /* Se nao estao na mesma coluna , verifico*/
  if(yp != y0){
    if(yp > y0){
      max = yp;
      min = y0;
    }
    else{
      max = y0;
      min = yp;
    }

    for(y = floor(min + EPS) + 1; y < max; y += 1){
      j = floor(y + EPS);
      
      x = (y - y0)*(xp - x0)/(yp - y0) + x0;
      i = floor(x + EPS);

      z = (y - y0)*(zp - z0)/(yp - y0) + z0;
      /*
      if(j == 0 || j == 10)
	fprintf(stderr, "Naaaaoooo!!\n");
      */
      if((double)predios[i][j] > z)
	return 0;
      if((double)predios[i][j-1] > z)
	return 0;
    }
  }


  return 1;
}

int main()
{
  int n, h;
  int i, j;
  char c;
  double posx[3], posy[3], posz[3];


  scanf(" %d", &n);
  for(h=1; h<=n; h++){
    for(i=0; i<10; i++){
      for(j=0; j<10; j++){
	scanf(" %c", &c);
	predios[j][i] = c - '0';
      }
    }

    while(getchar() != '(');
    scanf(" %lf", &x0);
    while(getchar() != ',');
    scanf(" %lf", &y0);
    while(getchar() != ',');
    scanf(" %lf", &z0);
    while(getchar() != ')');

    for(i=0; i<3; i++){
      while(getchar() != '(');
      scanf(" %lf", &posx[i]);
      while(getchar() != ',');
      scanf(" %lf", &posy[i]);
      while(getchar() != ',');
      scanf(" %lf", &posz[i]);
      while(getchar() != ')');
    }

    /*
    for(i=0; i<10; i++){
      for(j=0; j<10; j++){
	printf("%d", predios[i][j]);
      }
      putchar('\n');
    }
    putchar('\n');
    for(i=0; i<4; i++){
      printf("(%.1f, %.1f, %.1f) ", posx[i], posy[i], posz[i]);
    }
    putchar('\n');
    */

    printf("Fragfest City #%d\n", h);
    for(i=0; i<3; i++){
      if(estavendo(posx[i], posy[i], posz[i]))
	printf("Player %c is in sight\n", i+'A');
      else
	printf("Player %c is hiding\n", i+'A');
    }

  }
  return 0;
}
