/* Steps */
/* UVA 846 */
/* Accepted */

#include<stdio.h>

int calcula(int n)
{
  int resp, vezes;
  char soma;

  resp = 1; vezes = 1;
  soma = 0;
  while(42){
    n -= vezes;
    if(n <= 0){
      return resp;
    }
    resp++;
    if(soma){
      vezes++;
      soma = 0;
    }
    else
      soma = 1;
  }
  return resp;
}


int main()
{
  int casos;
  int x, y;
  scanf(" %d", &casos);
  while(casos--)
    {
      scanf(" %d %d", &x, &y);
      /*printf("%d\n", calcula(x, y, 0));*/
      if(x == y)
	printf("0\n");
      else
	printf("%d\n", calcula(y - x));
    }
  return 0;
}
