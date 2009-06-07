/*
ID: gabriel9
LANG: C
TASK: stamps
*/

#include <stdio.h>

int selos[50];
unsigned char minselos[2000001];

int main()
{
  int n, k;
  int i;
  int num;
  unsigned char min;
  FILE *fin = fopen("stamps.in", "r");
  FILE *fout = fopen("stamps.out", "w");


  fscanf(fin, " %d %d", &k, &n);
  for(i=0; i<n; i++)
    fscanf(fin, " %d", selos+i);

  minselos[0] = 0;
  num = 1;
  while(42){
    min = k+1;
    for(i=0; i<n; i++)
      if(selos[i] <= num && minselos[num-selos[i]] + 1 < min)
	min = minselos[num-selos[i]] + 1;
    if(min > k){
      fprintf(fout, "%d\n", num-1);
      return 0;
    }
    minselos[num] = min;
    num++;
  }
  return 0;
}
