#include <stdio.h>
#include <string.h>

int main()
{
  int s, m, at;
  int conta;

  while(scanf(" %d %d", &s, &m) != EOF)
    {
      printf("%10d%10d", s, m);
      printf("    ");

      conta = 0;
      at = 0;
      do{
	at += s;
	at %= m;
	conta++;
      }while(at != 0);
      if(conta == m)
	printf("Good Choice\n\n");
      else
	printf("Bad Choice\n\n");
    }
  return 0;
}
