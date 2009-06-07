/* Heads / Tails Probability */
/* UVA 474 */
/* Accepted */

#include <stdio.h>

#define MAX 1000001


double b[MAX];
int p[MAX];


int main()
{
  int i;

  b[0] = 1.0;
  p[0] = 0;

  for(i=1; i<MAX; i++){
    p[i] = p[i-1];
    b[i] = b[i-1] / 2.0;
    while(b[i] < 1.0){
      b[i] *= 10;
      p[i]++;
    }
  }
  
  while(scanf(" %d", &i) != EOF)
    {
      printf("2^-%d = %.3fe-%d\n", i, b[i], p[i]);
    }
  return 0;
}
