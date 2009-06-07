/*
ID: gabriel9
LANG: C
TASK: spin
*/

#include <stdio.h>

typedef struct{
  int ini, tam;
} Corte;

typedef struct{
  int pos;
  int vel;
  int ncortes;
  Corte corte[5];
} Roda;

Roda roda[5];


int poslivre(int p, int k)
{
  int i;
  int ini, fim;

  if(k == 5)
    return 1;

  for(i=0; i < roda[k].ncortes; i++){
    ini = (roda[k].pos + roda[k].corte[i].ini) % 360;
    fim = (ini + roda[k].corte[i].tam);
    if(fim >= 360){
      if(ini <= p  || p <= (fim % 360))
	return poslivre(p, k+1);
    }
    else if(ini <= p && p <= fim)
      return poslivre(p, k+1);
  }
  return 0;
}


int alinhadas()
{
  int i;
  for(i=1; i < 5; i++)
    if(roda[i].pos != roda[i-1].pos)
      return 0;
  return 1;
}

int main()
{
  int i, j, p;
  int t;
  FILE *fin = fopen("spin.in", "r");
  FILE *fout = fopen("spin.out", "w");

  for(i=0; i<5; i++){
    roda[i].pos = 0;
    fscanf(fin, " %d %d", &(roda[i].vel), &(roda[i].ncortes));
    for(j=0; j < roda[i].ncortes; j++)
      fscanf(fin, " %d %d", &(roda[i].corte[j].ini), &(roda[i].corte[j].tam));
  }

  t = 0;
  while(42){
    for(p = 0; p < 360; p++)
      if(poslivre(p, 0)){
	fprintf(fout, "%d\n", t);
	return 0;
      }

    if(t > 0 && alinhadas()){
      fprintf(fout, "none\n");
      return 0;
    }

    for(i=0; i<5; i++){
      roda[i].pos += roda[i].vel;
      roda[i].pos %= 360;
    }
    t++;
  }


  return 0;
}
