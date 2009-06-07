/*
ID: gabriel9
LANG: C
TASK: fact4
*/

#include <stdio.h>


int main()
{
  int n;
  int i, r;
  
  FILE *fin = fopen("fact4.in", "r");
  FILE *fout = fopen("fact4.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  fscanf(fin, " %d", &n);

  r = 1;
  for(i = n; i > 0; i--){
    r *= i;
    while(r % 10 == 0)
      r /= 10;
    r %= 100000;
  }

  fprintf(fout, "%d\n", r%10);

  return 0;
}
