#include <stdio.h>

const char nomes[6][6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

int main()
{
  int b1, b2, b3;
  int g1, g2, g3;
  int c1, c2, c3;
  int min, smin;
  int at;

  while(scanf(" %d %d %d %d %d %d %d %d %d",
	      &b1, &g1, &c1,
	      &b2, &g2, &c2,
	      &b3, &g3, &c3) > 0)
    {
      min = 0;
      smin = g1 + c1 + b2 + g2 + b3 + c3;

      at = g1 + c1 + b2 + c2 + b3 + g3;
      if(at < smin){
	min = 1;
	smin = at;
      }


      at = b1 + g1 + g2 + c2 + b3 + c3;
      if(at < smin){
	min = 2;
	smin = at;
      }

      at = b1 + g1 + b2 + c2 + c3 + g3;
      if(at < smin){
	min = 3;
	smin = at;
      }


      at = b1 + c1 + c2 + g2 + b3 + g3;
      if(at < smin){
	min = 4;
	smin = at;
      }


      at = b1 + c1 + b2 + g2 + c3 + g3;
      if(at < smin){
	min = 5;
	smin = at;
      }

      printf("%s %d\n", nomes[min], smin);
    }
  return 0;
}
