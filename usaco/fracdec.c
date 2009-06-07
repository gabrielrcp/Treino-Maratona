/*
ID: gabriel9
LANG: C
TASK: fracdec
*/

#include <stdio.h>
#include <string.h>

#define MAXDIG 100000

FILE *fin, *fout;
char buf[MAXDIG+10];
int tam;
int calculado[MAXDIG];
int d;
int p;


void calcula(int n)
{
  while(1){
    if(n == 0)
      return;

    if(calculado[n]){
      p = calculado[n];
      return;
    }
    calculado[n] = tam;

    n *= 10;
    sprintf(buf+tam, "%d", n/d);
    tam++;
    n %= d;
  }
}


int main()
{
  int n, i, c;

  fin = fopen("fracdec.in", "r");
  fout = fopen("fracdec.out", "w");
  /*
  fin = stdin;
  fout = stdout;
  */
  fscanf(fin, "%d %d", &n, &d);

  if(n % d == 0){
    fprintf(fout, "%d.0\n", n/d);
    return 0;
  }


  sprintf(buf, "%d.", n/d);
  tam = strlen(buf);
  n %= d;
  calcula(n);

  
  if(p == 0){
    for(i=0; i<tam; i++){
      if(i != 0 && i %  76 == 0)
	putc('\n', fout);
      putc(buf[i], fout);
    }
    putc('\n', fout);
  }
  else{
    for(i=0; i<p; i++){
      if(i != 0 && i %  76 == 0)
	putc('\n', fout);
      putc(buf[i], fout);
    }
    putc('(', fout);
    c = p+1;
    for(i=p; i<tam; i++){
      if(c %  76 == 0)
	putc('\n', fout);
      putc(buf[i], fout);
      c++;
    }
    if(c % 76 == 0)
      putc('\n', fout);
    putc(')', fout);
    putc('\n', fout);
  }
  
  return 0;
}
