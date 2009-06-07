/*
 * http://acm.uva.es/p/v1/141.html
 */

#include <stdio.h>

int n;
char tab[101][50][50];
char temp[50][50];

int compara(int k, int l)
{
  int i, j;
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      if(tab[k][i][j] != tab[l][i][j])
	return 0;
  return 1;

}

int acha(int k)
{
  int i;
  for(i=1; i<k; i++)
    if(compara(i, k))
      return 1;
  return 0;
}

void roda(int k)
{
  int i, j;
  for(i = 0; i < n; i++)
    for(j=0; j < n; j++)
      temp[i][j] = tab[k][j][n-1-i];

  for(i = 0; i < n; i++)
    for(j=0; j < n; j++)
      tab[k][i][j] = temp[i][j];
}


void novolance(int k)
{
  int i, j;
  char c;
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      tab[k][i][j] = tab[k-1][i][j];

  scanf(" %d %d %c", &i, &j, &c);
  i--; j--;
  if(c == '+')
    tab[k][i][j] = 1;
  else if(c == '-')
    tab[k][i][j] = 0;
  else
    fprintf(stderr, "Opa!\n");
}

int main()
{
  int i, j, k;
  while(42)
    {
      scanf(" %d", &n);
      if(n == 0)
	break;

      for(k = 1; k <= 2*n; k++)
	for(i=0; i<n; i++)
	  for(j=0; j<n; j++)
	    tab[k][i][j] = 0;

      for(k = 1; k <= 2*n; k++){
	novolance(k);
	for(i = 0; i < 4; i++){
	  roda(k);
	  if(acha(k)){
	    printf("Player %d wins on move %d\n", (k%2)+1, k);
	    for(j=k+1; j<=2*n; j++)
	      novolance(j);
	    goto proximo;
	  }
	}
      }
      printf("Draw\n");

    proximo:
      continue;
      
    }
  return 0;

}
