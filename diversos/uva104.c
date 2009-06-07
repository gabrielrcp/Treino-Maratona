/*
 * http://acm.uva.es/p/v1/104.html
 */

#include <stdio.h>

double compra[20][20];
double melhor[20][20][21];
/* melhor[i][j][t] eh quanto eu consigo comprar da moeda j a partir de uma 
unidade da moeda i, usando t transacoes */
char ant[20][20][21];


void imprime(int i, int j, int t)
{
  if(t == 0){
    printf("%d", i+1);
    return;
  }
  imprime(i, ant[i][j][t], t-1);
  printf(" %d", j+1);
}

int main()
{
  int n;
  int i, j, k, t;

  while(scanf(" %d", &n) > 0){
    for(i=0; i<n; i++)
      for(j=0; j<n; j++){
	if(i == j)
	  compra[i][j] = 1.0;
	else
	  scanf(" %lf", &(compra[i][j]));
	melhor[i][j][0] = 0.0;
	for(t = 1; t <= n; t++){
	  melhor[i][j][t] = compra[i][j];
	  ant[i][j][t] = i;
	}

      }

    for(t = 2; t <= n; t++){
      for(i = 0; i < n; i++){
	for(j = 0; j < n; j++){
	  for(k = 0; k < n; k++){
	    if(melhor[i][k][t-1] * compra[k][j] > melhor[i][j][t]){
	      melhor[i][j][t] = melhor[i][k][t-1] * compra[k][j];
	      ant[i][j][t] = k;
	      if(i == j && melhor[i][j][t] > 1.01){
		/*printf("%f\n", melhor[i][j][t]);*/
		imprime(i, ant[i][i][t], t-1);
		printf(" %d\n", i+1);
		/*printf(" %d\n", j+1);*/
		goto saida;
	      }
	    }
	  }
	}
      }
    }
    printf("no arbitrage sequence exists\n");    
  saida:
    continue;
  }

  return 0;


}
