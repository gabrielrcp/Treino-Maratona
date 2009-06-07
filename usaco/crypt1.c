/*
ID: your_id_here
LANG: C
TASK: crypt1
*/
#include <stdio.h>
#include <stdlib.h>

FILE *fin, *fout;
int n;
int possiveis[10]; 
char sn1[5], sn2[5];


int valido(int m, int nd)
{
  int conta=0;
  int d, i;
  while(m > 0){
    d = m%10;
    for(i=0; i<n; i++)
      if(d == possiveis[i])
	break;
    if(i == n)
      return 0;
    conta++;
    m /= 10;
  }
  return (conta == nd);
}

int tdbem()
{
  int n1, n2, n3, n4;
  n1 = atoi(sn1);
  n2 = atoi(sn2);
  n3 = sn2[1] - '0';
  n4 = sn2[0] - '0';

  if(!valido(n1*n3, 3))
    return 0;
  if(!valido(n1*n4, 3))
    return 0;
  if(!valido(n1*n2, 4))
    return 0;
  return 1;
}

int main () {
  
  int i;
  int a, b, c, d, e;
  int conta;

  
  fin  = fopen ("crypt1.in", "r");
  fout = fopen ("crypt1.out", "w");
  /*
  fin = stdin;
  fout = stdout;
  */

  sn1[3] = '\0';
  sn2[2] = '\0';
  while(fscanf(fin, " %d", &n) > 0){
    for(i=0; i<n; i++)
      fscanf(fin, " %d", &possiveis[i]);

    conta = 0;
    for(a=0; a<n; a++)
      for(b=0; b<n; b++)
	for(c=0; c<n; c++)
	  for(d=0; d<n; d++)
	    for(e=0; e<n; e++){
	      sn1[0] = possiveis[a] + '0';
	      sn1[1] = possiveis[b] + '0';
	      sn1[2] = possiveis[c] + '0';

	      sn2[0] = possiveis[d] + '0';
	      sn2[1] = possiveis[e] + '0';
	      if(tdbem())
		conta++;
	    }
    fprintf(fout, "%d\n", conta);
  }
  return 0;
}
