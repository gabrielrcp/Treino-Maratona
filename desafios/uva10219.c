/* Find the ways! */
/* UVA 10219 */
/* Accepted */

#include <stdio.h>
#include <math.h>



unsigned int resposta(int n, int k)
{
  unsigned long long int saida=0;
  int i;
  double t = 0.0;

  for(i=0; i<k; i++){
    t += log10((double)(n-i));
    while(t >= 1.0){
      saida++;
      t -= 1.0;
    }

    t -= log10((double)i+1.0);
    while(t < 0.0){
      saida--;
      t += 1.0;
    }
  }
  return (unsigned int)saida;
}


int main()
{
  int n, k;

  while(scanf(" %d %d", &n, &k) != EOF)
    printf("%u\n", resposta(n, k)+1);
    
  return 0;
}
