/*
ID: gabriel9
LANG: C
TASK: humble
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef int tipo;


tipo nums[100];
tipo gerados[MAX+1];
int ultt[100];
int n, k;

int min()
{
  int i, j;
  j = 0;
  for(i=1; i<k; i++)
    if(nums[i]*gerados[ultt[i]] < nums[j]*gerados[ultt[j]])
      j = i;
  return j;
}

int main()
{
  int i;
  tipo ult;
  FILE *fin = fopen("humble.in", "r");
  FILE *fout = fopen("humble.out", "w");

  
  fscanf(fin, " %d %d", &k, &n);
  for(i=0; i<k; i++)
    fscanf(fin, " %d", &nums[i]);

  gerados[0] = 1;

  ult = 0;
  while(ult < n){
    ult++;
    do{
      i = min();
      gerados[ult] = gerados[ultt[i]] * nums[i];
      ultt[i]++;
    }while(gerados[ult] <= gerados[ult-1]);
  }
  fprintf(fout, "%d\n", gerados[n]);
  return 0;
}
