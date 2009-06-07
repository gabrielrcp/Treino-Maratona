/*
ID: gabriel9
LANG: C
TASK: zerosum
*/

#include <stdio.h>
#include <string.h>

FILE *fin, *fout;

char usar[12];
char expr[30];

int n;

int avalia(char *p)
{
  int i;
  int a, r;
  char *q;

  r = 0;
  q = p;

  for(i=1; p[i] != '\0'; i++){
    if(p[i] == '+' || p[i] == '-'){
      sscanf(q+1, "%d", &a);
      switch(*q)
	{
	case '+':
	  r += a;
	  break;
	case '-':
	  r -= a;
	  break;
	default:
	  fprintf(stderr, "Opa!\n");
	  break;
	}
      q = p+i;
    }
  }

  sscanf(q+1, "%d", &a);
  switch(*q)
    {
    case '+':
      r += a;
      break;
    case '-':
      r -= a;
      break;
    default:
      fprintf(stderr, "Opa!\n");
      break;
    }

  return r;
}

void testa(int p)
{
  int i;
  char tmp[4];
  if(p ==  n){
    expr[0] = '\0';
    for(i=0; i<n; i++){
      if(usar[i] == ' ')
	sprintf(tmp, "%d", i+1);
      else
	sprintf(tmp, "%c%d", usar[i], i+1);
      strcat(expr, tmp);
    }

    if(avalia(expr) == 0){
      fputc('1', fout);
      for(i=1; i<p; i++)
	fprintf(fout, "%c%d", usar[i], i+1);
      putc('\n', fout);
    }
    return;
  }
  usar[p] = ' ';
  testa(p+1);
  usar[p] = '+';
  testa(p+1);
  usar[p] = '-';
  testa(p+1);
}

int main()
{
  
  fin = fopen("zerosum.in", "r");
  fout = fopen("zerosum.out", "w");
  /*
  fin = stdin;
  fout = stdout;
  */
  fscanf(fin, " %d", &n);

  usar[0] = '+';
  testa(1);

  return 0;
}
