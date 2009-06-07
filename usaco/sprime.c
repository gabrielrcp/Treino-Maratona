/*
ID: gabriel9
LANG: C
TASK: sprime
*/

#include <stdio.h>

#define MAX 10000

int sprimo[8][MAX];
int num[8] = {0, 0, 0, 0, 0, 0, 0, 0};


int ehprimo(int n)
{
  int i;
  if(n == 2)
    return 1;
  if(n % 2 == 0)
    return 0;
  for(i=3; i*i <= n; i+=2)
    if(n % i == 0)
      return 0;
  return 1;
}


void encontrasprimos(int tam)
{
  int i, j;
  int at;

  for(i=0; i < num[tam-1]; i++){
    for(j=0; j<10; j++){
      at = 10*sprimo[tam-1][i] + j;
      if(ehprimo(at)){
	sprimo[tam][num[tam]] = at;
	num[tam]++;
      }
    }
  }
}

int main()
{
  int n, i;
  
  FILE *fin = fopen("sprime.in", "r");
  FILE *fout = fopen("sprime.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  fscanf(fin, " %d", &n);

  sprimo[0][0] = 2;
  sprimo[0][1] = 3;
  sprimo[0][2] = 5;
  sprimo[0][3] = 7;
  num[0] = 4;

  for(i=1;i<n; i++)
    encontrasprimos(i);

  for(i=0; i < num[n-1]; i++)
    fprintf(fout, "%d\n", sprimo[n-1][i]);

  return 0;
}
