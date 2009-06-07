#include <stdio.h>
#include <string.h>


int main()
{
  int n, tam1, tam2, tam;
  char buf[210];
  int num1[500], num2[500];
  int i;
  int sobra;


  scanf(" %d", &n);
  while(n--)
    {
      scanf(" %s", buf);
      for(i=0; buf[i] != '\0'; i++)
	num1[i] = buf[i] - '0';
      tam1 = i;
      for(; i < 500; i++)
	num1[i] = 0;

      scanf(" %s", buf);
      for(i=0; buf[i] != '\0'; i++)
	num2[i] = buf[i] - '0';
      tam2 = i;
      for(;i < 500; i++)
	num2[i] = 0;

      tam = (tam1 > tam2 ? tam1 : tam2);
      sobra = 0;
      for(i=0; i<tam; i++)
	{
	  num1[i] += num2[i] + sobra;
	  sobra = 0;
	  if(num1[i] >= 10){
	    sobra = num1[i] / 10;
	    num1[i] %= 10;
	  }
	}
      while(sobra > 0){
	num1[i] = sobra % 10;
	sobra /= 10;
	i++;
      }
      tam = --i;
      while(num1[tam] == 0)
	tam--;
      i = 0;
      while(i < tam && num1[i] == 0)
	i++;
      for(; i<=tam; i++)
	printf("%d", num1[i]);
      putchar('\n');

    }

  return 0;
}
