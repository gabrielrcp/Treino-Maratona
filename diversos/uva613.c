#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*char iteracoes[20][100];*/
char **iteracoes;
int contadigi[10];


void geraiteracao(int i)
{
  int j;
  int tam;

  for(j = 0; j < 10; j++)
    contadigi[j] = 0;

  i--;
  for(j = 0; iteracoes[i][j] != '\0'; j++)
    contadigi[iteracoes[i][j] - '0']++;
  i++;

  tam = 0;
  for(j=0; j < 10; j++){
    if(contadigi[j] > 0){
      sprintf(iteracoes[i]+tam, "%d%d", contadigi[j], j);
      tam = strlen(iteracoes[i]);
    }
  }
}

int main()
{
  int i, j;

  iteracoes = (char **)malloc(20*sizeof(char *));
  for(i=0; i<20; i++)
    iteracoes[i] = (char *)malloc(100*sizeof(char));

  while(42){
    scanf(" %s", iteracoes[0]);
    if(strcmp(iteracoes[0], "-1") == 0)
      break;

    geraiteracao(1);
    if(strcmp(iteracoes[0], iteracoes[1]) == 0){
      printf("%s is self-inventorying\n", iteracoes[0]);
      continue;
    }

    for(i=2; i <= 15; i++){
      geraiteracao(i);
      if(strcmp(iteracoes[i], iteracoes[i-1]) == 0){
	printf("%s is self-inventorying after %d steps\n", 
	       iteracoes[0], i - 1);
	goto prox;
      }

      for(j=i-2; j >= 0; j--){
	if(strcmp(iteracoes[i], iteracoes[j]) == 0){
	  printf("%s enters an inventory loop of length %d\n", 
		 iteracoes[0], i-j);
	  goto prox; 
	}
      }
    }
    printf("%s can not be classified after 15 iterations\n", iteracoes[0]);
  prox:
    continue;
  }
  return 0;
}
