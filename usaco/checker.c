/*
ID: gabriel9
LANG: C
TASK: checker
*/

#include <stdio.h>

FILE *fin, *fout;

int n;

char colliv[13];
char diag1t[50];
char *diag1l;
char diag2l[50];

int colus[13];
unsigned int conta;

void imprime(int l)
{
  int c;

  if(conta > 2)
    return;

  if(l == n){
    fprintf(fout, "%d", colus[0]+1);
    for(c=1; c<n; c++)
      fprintf(fout, " %d", colus[c]+1);
    fprintf(fout, "\n");
    conta++;
    return;
  }

  for(c=0; c<n; c++){
    if(colliv[c] && diag1l[l-c] && diag2l[l+c]){
      colliv[c] = 0;
      diag1l[l-c] = 0;
      diag2l[l+c] = 0;
      colus[l] = c;
      
      imprime(l+1);
      
      colliv[c] = 1;
      diag1l[l-c] = 1;
      diag2l[l+c] = 1;
    }
  }
}

void resolve(int l)
{
  int c;

  if(l == n){
    conta++;
    return;
  }

  for(c=0; c < n; c++){
    if(colliv[c] && diag1l[l-c] && diag2l[l+c]){
      colliv[c] = 0;
      diag1l[l-c] = 0;
      diag2l[l+c] = 0;
      colus[l] = c;
      
      resolve(l+1);
      
      colliv[c] = 1;
      diag1l[l-c] = 1;
      diag2l[l+c] = 1;
    }
  }
}

unsigned int contar()
{
  int c;
  unsigned int total = 0;

  for(c=0; c < (n+1)/2; c++){

    conta = 0;
    colliv[c] = 0;
    diag1l[-c] = 0;
    diag2l[c] = 0;
    colus[0] = c;
    
    resolve(1);
    
    colliv[c] = 1;
    diag1l[-c] = 1;
    diag2l[c] = 1;
    
    if(c == n/2)
      total += conta;
    else
      total += 2*conta;
  }
  return total;
}


int main()
{
  int i;

  fin = fopen("checker.in", "r");
  fout = fopen("checker.out", "w");

  /*
  fin = stdin;
  fout = stdout;
  */

  fscanf(fin, " %d", &n);
  for(i=0; i<n; i++)
    colliv[i] = 1;
  for(i=0; i<50; i++){
    diag1t[i] = 1;
    diag2l[i] = 1;
  }
  diag1l = diag1t + 15;


  conta = 0;
  imprime(0);
  fprintf(fout, "%d\n", contar());
  return 0;
}
