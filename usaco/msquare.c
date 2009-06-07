/*
ID: gabriel9
LANG: C
TASK: msquare
*/

#include <stdio.h>

#define MAX 40320 /* 8! */

int dist[MAX];
int fat[9];
int atual[9];
int dest[9];

int FILA[MAX];
int ini, fim;

char tranf[MAX];
int ant[MAX];

FILE *fin, *fout;
int conta;

void insere(int r)
{
  FILA[fim] = r;
  fim++;
  if(fim == MAX)
    fim = 0;
}

int retira()
{
  int r = FILA[ini];
  ini++;
  if(ini == MAX)
    ini = 0;
  return r;
}

int vazia()
{
  return (ini == fim);
}


int hash(int *seq)
{
  int temp[9];
  int i,j,r;

  r = 0;
  for(j = 1; j <= 8; j++)
    temp[j] = seq[j];

  for(j = 1; j <= 8; j++){
    r += (temp[j] - 1) * fat[8-j];
    for(i = j+1; i <= 8 ; i++){
      if (temp[i] > temp[j])
	temp[i] = temp[i] - 1;
    }
  }
  return(r);
}


void hash_inv(int r)
{
  int i,j,d;
  atual[8] = 1;
  for(j=1 ; j < 8 ;j++){
    d = (r % fat[j+1])/fat[j];
    r = r - d * fat[j];
    atual[8-j] = d+1;
    for(i = 9-j; i <= 8; i++){
      if(atual[i] > d)
        atual[i]++;
    }
  }
}

void transA(int *seq, int *d)
{
  int i;
  for(i=1; i<=8; i++)
    d[i] = seq[9-i];
}

void transB(int *seq, int *d)
{
  int i;
  for(i = 4; i > 1; i--)
    d[i] = seq[i-1];
  d[1] = seq[4];

  for(i = 5; i < 8 ; i++)
    d[i] = seq[i+1];
  d[8] = seq[5];
}

void transC(int *seq, int *d)
{
  d[3] = seq[2];
  d[2] = seq[7];
  d[7] = seq[6];
  d[6] = seq[3];

  d[1] = seq[1];
  d[4] = seq[4];
  d[5] = seq[5];
  d[8] = seq[8];
}


void imprime(int r)
{
  if(r == 0)
    return;
  imprime(ant[r]);
  if(conta == 60){
    conta = 0;
    putc('\n', fout);
  }
  putc(tranf[r], fout);
  conta++;
}

int main()
{
  int i;
  int r, t;
  int d[9];

  fin = fopen("msquare.in", "r");
  fout = fopen("msquare.out", "w");

  fat[0] = 1;
  for(i=1; i<9; i++)
    fat[i] = i*fat[i-1];

  for(i=1; i<=8; i++){
    fscanf(fin, " %d", &dest[i]);
  }

  dist[0] = 0;
  for(i=1; i<MAX; i++)
    dist[i] = -1;
  
  ini = fim = 0;
  insere(0);
  while(!vazia()){
    r = retira();
    hash_inv(r);

    transA(atual, d);
    t = hash(d);
    if(dist[t] == -1){
      dist[t] = dist[r] + 1;
      insere(t);
      ant[t] = r;
      tranf[t] = 'A';
    }

    transB(atual, d);
    t = hash(d);
    if(dist[t] == -1){
      dist[t] = dist[r] + 1;
      insere(t);
      ant[t] = r;
      tranf[t] = 'B';
    }

    transC(atual, d);
    t = hash(d);
    if(dist[t] == -1){
      dist[t] = dist[r] + 1;
      insere(t);
      ant[t] = r;
      tranf[t] = 'C';
    }
  }
  r = hash(dest);
  fprintf(fout, "%d\n", dist[r]);
  conta = 0;
  imprime(r);
  fprintf(fout, "\n");  
  return 0;
}
