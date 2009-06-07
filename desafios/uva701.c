/* The Archaeologist's Dilemma */
/* UVA 701 */
/* Accepted */

#include <stdio.h>
#include <math.h>

#define DEBUG 0
#if DEBUG
#define D(x) x
#else
#define D(x)
#endif

int ndigi(unsigned int n)
{
  int conta = 1;
  while(n >= 10){
    conta++;
    n /= 10;
  }
  return conta;
}

int main()
{
  unsigned int N;
  double l2 = log(2.0);
  double l10 = log(10.0) / l2;
  double aux = l10 - 3.0;
  double lN, lN1;
  double li, ls;
  int digi;

  unsigned long long E;

  
  while(scanf(" %u", &N) != EOF)
    {
      lN = log(N) / l2;
      lN1 = log(N+1) / l2;

      digi = ndigi(N);
      D(printf("%u - %d dígitos\n", N, digi);)
      li = lN  + l10*digi;
      ls = lN1 + l10*digi;

      E = 0;
      /*zera();*/

      while(li > 1.0){
	li -= 1.0;
	ls -= 1.0;
	/*soma(1);*/
	E++;
      }


      while(1)
	{

	  li += aux;
	  ls += aux;
	  E += 3;
#if DEBUG
	  if(E < 3)
	    printf("Estourou!!\n");
#endif
	  if(li > 1.0){
	    li -= 1.0;
	    ls -= 1.0;
	    /*soma(1);*/
	    E++;
#if DEBUG
	    if(E == 0)
	      printf("Estourou!!\n");
#endif

	  }

	  if(ls > 1.0){
	    /*soma((int)ls);*/
	    E += (int)li + 1;
	    /*imprime();*/
	    printf("%llu\n", E);
	    break;
	  }
	}
    }
  return 0;
}
