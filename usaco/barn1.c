/*
ID: gabriel9
LANG: C
TASK: barn1
*/

#include <stdio.h>

char sta[200];
int s, m, c;

int resolve()
{
  int i, j, k;
  int li, ls;
  int e, d;
  int conta;

  if(m >= c)
    return c;

  li = 0;
  while(li < s  && sta[li] == 0)
    li++;
  
  j = li+1;
  ls = li;
  while(j < s){
    if(sta[j] == 1)
      ls = j;
    j++;
  }
  conta = ls - li + 1;

  for(i=li; i<=ls; i++)
    sta[i] += 2;
  /*
  printf("s=%d m=%d\n",s, m);
  printf("placa 1: %d a %d\n", li, ls);
  */

  for(k=1; k<m; k++){
    e = 0;
    d = -1;
    i = j = li;
    while(i < ls && j < ls){
      while(i < ls && sta[i] != 2)
	i++;
      j = i+1;
      while(j < ls && sta[j] != 3)
	j++;
      j--;
      if(d - e < j - i){
	e = i;
	d = j;
      }
      i = j+1;
    }
    for(i=e; i<=d; i++){
      sta[i] -= 2;
      conta--;
    }
  }
  return conta;
}

int main()
{
  
  FILE *fin = fopen("barn1.in", "r");
  FILE *fout = fopen("barn1.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  int i, j;

  fscanf(fin, " %d %d %d", &m, &s, &c);

  for(i=0; i<s; i++)
    sta[i] = 0;

  for(i=0; i<c; i++){
    fscanf(fin, " %d", &j);
    sta[--j] = 1;
  }

  fprintf(fout, "%d\n", resolve());

  return 0;
}
