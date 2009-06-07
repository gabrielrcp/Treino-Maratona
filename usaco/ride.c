/*
ID: gabriel9
LANG: C
TASK: ride
*/

#include <stdio.h>

int main()
{
  FILE *fin = fopen("ride.in", "r");
  FILE *fout = fopen("ride.out", "w");
  char cometa[10], grupo[10];
  int sc=1, sg=1, i;
  fscanf(fin, "%s %s", cometa, grupo);

  for(i=0; cometa[i] != '\0'; i++)
    sc *= (cometa[i] - 'A' + 1);
  for(i=0; grupo[i] != '\0'; i++)
    sg *= (grupo[i] - 'A' + 1);

  if(sc%47 == sg%47)
    fprintf(fout, "GO\n");
  else
    fprintf(fout, "STAY\n");
  fclose(fin);
  fclose(fout);
  return 0;
}
