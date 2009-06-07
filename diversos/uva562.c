#include <stdio.h>

int valor[100];
char consigo[50*500+1][101];


int absoluto(int x)
{
  if(x < 0)
    return -x;
  else
  return x;
}

int main()
{
  int n, m;
  int i, j, k;
  int soma, metade;
  int maior;

  scanf(" %d", &n);
  while(n--)
    {
      scanf(" %d", &m);
      soma = 0;
      for(i=0; i<m; i++){
	scanf(" %d", valor+i);
	soma += valor[i];
      }
      metade = soma/2;
      maior = 0;

      for(j = 0; j <= m; j++)
	consigo[0][j] = 1;

      for(i=1; i <= metade; i++)
	for(j=0; j <= m; j++)
	  consigo[i][j] = 0;

      for(j = 0; j < m; j++){
	for(i = valor[j]; i <= metade; i++){
	  if(consigo[i][j+1])
	    continue;
	  if(consigo[i-valor[j]][j]){
	    for(k=j+1; k <= m; k++)
	      consigo[i][k] = 1;
	    if(i > maior)
	      maior = i;
	  }
	}
      }
      printf("%d\n", soma - 2*maior);
    }
  return 0;
}
