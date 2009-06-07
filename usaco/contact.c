/*
ID: gabriel9
LANG: C
TASK: contact
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct{
  int num;
  int tam;
  int numoc;
} OC;


char sequencia[200001];
OC ocorre[13][4096];
OC ordenar[8190];
int a, b, n;


int hash(char *s, int t)
{
  int k = 0;
  while(t > 0){
    k += *s;
    s++;
    k = (k << 1);
    t--;
  }
  return (k >> 1);
}


int compara(const void *p1, const void *p2)
{
  OC *a = (OC *)p1;
  OC *b = (OC *)p2;
  if(a->numoc == b->numoc){
    if(a->tam == b->tam)
      return(a->num - b->num);
    return (a->tam - b->tam);
  } 
  return (b->numoc - a->numoc);
}

void hash_inv(char *buf, int num, int tam)
{

  *(buf+tam) = '\0';
  tam--;
  while(tam >= 0){
    *(buf+tam) = num % 2;
    *(buf+tam) += '0';
    tam--;
    num /= 2;
  }
}


int main()
{
  int tam;
  char *c;
  char buf[13];
  int k, t, f, ultf, numimp;
  int numord;
  FILE *fin = fopen("contact.in", "r");
  FILE *fout = fopen("contact.out", "w");
  fscanf(fin, " %d %d %d", &a, &b, &n);

  c = sequencia;
  while(fscanf(fin, "%s", c) > 0)
    c += 80;
  tam = 0;
  for(c=sequencia; *c != '\0'; c++){
    *c -= '0';
    tam++;
  }

  for(t=a; t<=b; t++)
    for(k=0; k<4096; k++){
      ocorre[t][k].tam = t;
      ocorre[t][k].num = k;
      ocorre[t][k].numoc = 0;
    }


  for(t=a; t<=b; t++)
    for(k=0; k+t<=tam; k++)
      ocorre[t][hash(sequencia+k, t)].numoc++;

  numord = 0;
  for(t=a; t<=b; t++)
    for(k=0; k<4096; k++)
      if(ocorre[t][k].numoc > 0){
	ordenar[numord].num = ocorre[t][k].num;
	ordenar[numord].tam = ocorre[t][k].tam;
	ordenar[numord].numoc = ocorre[t][k].numoc;
	numord++;
      }
  qsort(ordenar, numord, sizeof(OC), compara);
  /*
  ultf = -1;
  k = f = 0;
  imp = 0;

  while(k < numord){
    if(ordenar[k].numoc != ultf){
      ultf = ordenar[k].numoc;
      f++;
      if(f > n){
	putc('\n', fout);
	return 0;
      }
      if(f > 1)
	putc('\n', fout);
      fprintf(fout, "%d\n", ultf);
      imp = 0;
    }
    hash_inv(buf, ordenar[k].num, ordenar[k].tam);
    if(imp)
      putc(' ', fout);
    imp = 1;
    fprintf(fout, "%s", buf);
    k++;
  }
  putc('\n', fout);
  */

  k = 0;
  for(f=0; f < n; f++){
    ultf = ordenar[k].numoc;
    fprintf(fout, "%d", ultf);
    numimp = 0;
    while(k < numord && ordenar[k].numoc == ultf){
      if(numimp % 6 == 0)
	putc('\n', fout);
      else
	putc(' ', fout);
      hash_inv(buf, ordenar[k].num, ordenar[k].tam);
      fprintf(fout, "%s", buf);
      numimp++;
      k++;
    }
    putc('\n', fout);
    if(k == numord)
      return 0;
  }

  return 0;
}
