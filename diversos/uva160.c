#include <stdio.h>

int primos[100];
int nprimos;
int qtd[100];

int eprimo(int num)
{
  int i;
  if(num % 2 == 0 && num != 2)
    return 0;
  for(i=3; i <= num / 2; i++)
    if(num % i == 0)
      return 0;
  return 1;
}


void geraprimos()
{
  int i;
  nprimos = 0;
  for(i=2; i<100; i++)
    if(eprimo(i))
      primos[nprimos++] = i;
}

int main()
{
  int n, i, j, num, ult;

  geraprimos();

  while(1)
    {
      scanf(" %d", &n);
      if(n == 0)
	break;
      for(i=0; i<nprimos; i++)
	qtd[i] = 0;
      ult = 0;

      for(i=2; i<=n; i++){
	num = i;
	j = 0;
	while(num != 1){
	  while(num % primos[j] == 0){
	    num /= primos[j];
	    qtd[j]++;
	    if(j > ult)
	      ult = j;
	  }
	  j++;
	}	
      }
      printf("%3d! =", n);
      for(i=0; i<=ult; i++){
	if(i % 15 == 0 && i != 0)
	  printf("\n      ");
	printf("%3d", qtd[i]);
      }
      printf("\n");
    }
  return 0;
}
