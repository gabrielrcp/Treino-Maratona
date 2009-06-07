/* Mischievous Children */
/* UVA 10338 */
/* Accepted */

#include <stdio.h>
#include <string.h>

typedef unsigned long long int tipo;

tipo f[21];


int main()
{
  int h, casos;
  int i, j, tam;
  char buf[22], contei[22];
  int conta;
  tipo saida;


  f[0] = 1;
  for(i=1; i<21; i++)
    f[i] = i * f[i-1];

  scanf(" %d", &casos);
  
  for(h=1; h <= casos; h++)
    {
      scanf(" %s", buf);
      tam = strlen(buf);
      saida = f[tam];
      for(i=0; i < tam; i++)
	contei[i] = 0;
      for(i=0; i < tam; i++){
	if(contei[i])
	  continue;
	conta = 1;
	for(j=i+1; j<tam; j++)
	  if(buf[j] == buf[i]){
	    contei[j] = 1;
	    conta++;
	  }
	saida /= f[conta];
      }
      printf("Data set %d: %lld\n", h, saida);
    }
  return 0;
}
