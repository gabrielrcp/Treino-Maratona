/* UVA 424 - Integer Inquiry */
/* Accepted */

#include <stdio.h>
#include <string.h>


#define MAX 110

int memoria[MAX][MAX];
char buffer[MAX];

int saida[MAX];


int main()
{
  int n;
  int tam;
  int i, j;
  int soma, resto;

  n = 0;
  while(42)
    {
      scanf(" %s", buffer);
      if(strcmp(buffer, "0") == 0)
	break;

      tam = strlen(buffer);
      tam--;
      i = 0;
      while(tam >= 0){
	memoria[n][i] = buffer[tam] - '0';
	i++;
	tam--;
      }
      for(;i < MAX; i++)
	memoria[n][i] = 0;
      n++;
    }

  resto = 0;
  for(i = 0; i < MAX - 1; i++){ /*i percorre os caracteres*/
    soma = resto;
    for(j = 0; j < n; j++)
      soma += memoria[j][i];
    saida[i] = soma % 10;
    resto = soma / 10;
  }
  saida[MAX - 1] = resto;


  i = MAX;
  do{
    i--;
  }while(saida[i] == 0);

  for(; i >= 0; i--)
    printf("%d", saida[i]);
  putchar('\n');
  

  return 0;
}
