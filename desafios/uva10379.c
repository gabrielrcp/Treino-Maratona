/* UVA 10379 - Pit Stop Strategy
   Accepted */

#include <stdio.h>

#define MAX 110
#define EPS 1.0e-9

double t0, tad;
double c0, cad;
double p0, pad;

double memoriza[MAX];

double necessario[MAX];
double abastece[MAX];
int pits[MAX];
int prox[MAX];

int voltas;


int igual(double a, double b)
{
  a -= b;
  return (-EPS <= a && a <= EPS);
}

/* Xn = c/cad * [ (1 / (1 - cad)) - 1] */
void inicializa()
{
  double r;
  int i;

  necessario[0] = 0.0;
  if(igual(cad, 0.0)){
    for(i = 1; i <= voltas; i++)
      necessario[i] = necessario[i-1] + c0;
    return;
  }
  r = 1.0;
  for(i = 1; i <= voltas; i++){
    r /= 1 - cad;
    necessario[i] = c0/cad * (r - 1.0);
  }
}

double demora(int v)
{
  double comb = necessario[v];
  double r = 0.0;
  while(v--){
    r += t0 + comb * tad;
    comb -= c0 + comb*cad;
  }
  /*  printf("****%f****\n", comb);*/
  return r;
}

double minimo(int v)
{
  double rt, tt; /*resposta tempo, tempo temp*/
  double ra; /* resposta abastece */
  int rp; /*resposta pits*/
  int i;

  if(pits[v] != -1)
    return memoriza[v];

  rt = demora(v);
  if(v != voltas)
    rt += p0 + pad*necessario[v];
  ra = necessario[v];
  rp = 0;
  prox[v] = -1;
  for(i = 1; i < v; i++){
    tt = demora(i) + minimo(v - i);
    if(v != voltas)
      tt += p0 + pad*necessario[i];
    if(tt < rt){
      rt = tt;
      ra = necessario[i];
      rp = pits[v - i] + 1;
      prox[v] = v - i;
    }
  }

  memoriza[v] = rt;
  abastece[v] = ra;
  pits[v] = rp;
  return rt;
}



int main()
{
  int i, j;


  while((!feof(stdin)) && scanf(" %d", &voltas) > 0)
    {
      scanf(" %lf %lf", &t0, &tad);
      scanf(" %lf %lf", &c0, &cad);
      scanf(" %lf %lf", &p0, &pad);
      
      printf("%d %.3f %.3f %.3f %.3f %.3f %.3f\n",
	     voltas, t0, tad, c0, cad, p0, pad);

      for(i = 1; i <= voltas; i++)
	pits[i] = -1;

      memoriza[0] = 0.0;
      abastece[0] = 0.0;
      pits[0] = 0;

      inicializa(voltas);
      minimo(voltas);
      printf("%.3f %.3f %d\n",memoriza[voltas],abastece[voltas],pits[voltas]);
      j = prox[voltas];
      while(j != -1){
	printf("%d %.3f\n", voltas - j, abastece[j]);
	j = prox[j];
      }

    }
  return 0;
}
