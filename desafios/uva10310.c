/* UVA 10310 - Dog and Gopher */
/* Accepted */

#include <stdio.h>

int main()
{
  int n;
  double gx, gy, dx, dy;
  double x, y;
  double dg, dd;
  char achei;

  while(!feof(stdin) && scanf(" %d", &n) > 0)
    {
      scanf(" %lf %lf %lf %lf", &gx, &gy, &dx, &dy);
      achei = 0;
      while(n-- > 0){
	scanf(" %lf %lf", &x, &y);
	dg = (x - gx) * (x - gx) + (y - gy) * (y - gy);
	dd = (x - dx) * (x - dx) + (y - dy) * (y - dy);
	if(dd >= 4.0 * dg){
	  printf("The gopher can escape through the hole at (%.3f,%.3f).\n"
		 , x, y);
	  achei = 1;
	  break;
	}
      }
      while(n-- > 0)
	scanf(" %lf %lf", &x, &y);
      if(!achei)
	printf("The gopher cannot escape.\n");
    }
  return 0;
}
