/*
ID: gabriel9
LANG: C
TASK: preface
*/

#include <stdio.h>



#define I 0
#define V 1
#define X 2
#define L 3
#define C 4
#define D 5
#define M 6

int conta[7];
char letras[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void soma(int n)
{
  while(n >= 1000){
    n -= 1000;
    conta[M]++;
  }
  if(n >= 900){
    n -= 900;
    conta[C]++;
    conta[M]++;
  }
  if(n >= 500){
    n -= 500;
    conta[D]++;
    
  }
  if(n >= 400){
    n -= 400;
    conta[C]++;
    conta[D]++;
  }
  while(n >= 100){
    n -= 100;
    conta[C]++;
  }


  if(n >= 90){
    n -= 90;
    conta[X]++;
    conta[C]++;
  }
  if(n >= 50){
    n -= 50;
    conta[L]++;
    
  }
  if(n >= 40){
    n -= 40;
    conta[X]++;
    conta[L]++;
  }
  while(n >= 10){
    n -= 10;
    conta[X]++;
  }


  if(n >= 9){
    n -= 9;
    conta[I]++;
    conta[X]++;
  }
  if(n >= 5){
    n -= 5;
    conta[V]++;
    
  }
  if(n >= 4){
    n -= 4;
    conta[I]++;
    conta[V]++;
  }
  while(n >= 1){
    n--;
    conta[I]++;
  }

}

int main()
{
  int i, n;
  /*
  FILE *fin = fopen("preface.in", "r");
  FILE *fout = fopen("preface.out", "w");
  */
  FILE *fin = stdin;
  FILE *fout = stdout;
  

  fscanf(fin, " %d", &n);

  for(i=0; i<7; i++)
    conta[i] = 0;

  for(i=0; i<=n; i++)
    soma(i);

  for(i=0; i<7; i++)
    if(conta[i] > 0)
      fprintf(fout, "%c %d\n", letras[i], conta[i]);
  return 0;
}
