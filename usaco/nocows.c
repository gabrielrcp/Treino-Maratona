/*
ID: gabriel9
LANG: C
TASK: nocows
*/
#include <stdio.h>

/*conta[n][k]*/
int conta[201][101];

int ng, kg;

void calcula(int n, int k)
{
  int soma;
  int i;

  if(n == 1){
    conta[n][k] = 1;
    return;
  }
  else if(k == 1){
    conta[n][k] = 0;
    return;
  }

  soma = 0;
  for(i=1; i < n - 1; i += 2){
    soma += conta[i][k-1] * conta[n-1-i][k-1];
    soma %= 9901;

    if(soma < 0)
      fprintf(stderr, "Naaaooo!!!\n");
  }
  
  conta[n][k] = soma;
  
  return;
}

int mod(int n)
{
  while(n >= 9901)
    n -= 9901;
  while(n < 0)
    n += 9901;
  return n;
}

int main () 
{
  int i, j;
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  FILE *fin  = fopen ("nocows.in", "r");
  FILE *fout = fopen ("nocows.out", "w");
  
  fscanf(fin, " %d %d", &ng, &kg);
  

  for(i=1;i<=ng; i++)
    for(j=1; j<=kg; j++)
      calcula(i, j);

  fprintf(fout, "%d\n", mod(conta[ng][kg] - conta[ng][kg-1]));

  return 0;
}
