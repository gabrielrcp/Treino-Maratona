/*
ID: gabriel9
LANG: C
TASK: dualpal
*/

#include <stdio.h>

int epalindromo(int a, int b)
{
  int saida[50];
  int i=0, j;
  int n = a;
  while(n > 0){
    saida[i++] = n % b;
    n /= b;
  }
  j = 0;
  i--;
  /*
  printf("n=%d i=%d j=%d\n", a, i, j);
  */
  while(j < i){
    if(saida[i] != saida[j])
      return 0;
    i--; j++;
  }
  /*
  printf("n=%d eh palindromo na base %d!\n", a, b);
  */
  return 1;
}

int verifica(int n)
{
  int b, c=0;
  for(b = 2; b <= 10; b++){
    if(epalindromo(n, b))
      c++;
    if(c >= 2)
      return 1;
  }
  return 0;
}


int main()
{
  
  FILE *fin = fopen("dualpal.in", "r");
  FILE *fout = fopen("dualpal.out", "w");
  
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  int n, s;
  int i, c=0;
  fscanf(fin," %d %d", &n, &s);
  for(i=s+1; c < n; i++){
    if(verifica(i)){
      fprintf(fout, "%d\n", i);
      c++;
    }
  }
  return 0;
}
