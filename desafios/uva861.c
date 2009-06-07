/* Little Bishops */
/* UVA 861 */
/* Accepted */

#include <stdio.h>
#include <stdlib.h>

int n;

char buf[20];
char *diag2;

int guarda[8][65];
int parcial[2][8][65];


int resposta(int d1, int k)
{
  int d2, l;
  int r = 0;

  if(k == 0)
    return 1;
  if(d1 >= n)
    return 0;

  for(; d1 <= n - k; d1+=2){
    if(d1 <= 0)
      l = n + d1;
    else
      l = n - d1;

    for(d2 = -l + 1; d2 < l; d2 += 2){
      if(diag2[d2]){
	diag2[d2] = 0;
	r += resposta(d1+2, k-1);
	diag2[d2] = 1;
      }
    }
  }
  return r;
}
int main()
{
  int i, j, k;

  for(i=0; i<8; i++)
    for(j=0; j <= (i+1)*(i+1); j++){
      parcial[0][i][j] = parcial[1][i][j] = guarda[i][j] = -1;
    }
  for(i=0; i<20; i++)
    buf[i] = 1;


  diag2 = buf + 10;

  while(scanf(" %d %d", &n, &k) && (n || k))
    {
      if(guarda[n-1][k] == -1){
	for(i=0; i <= k; i++){
	  if(parcial[0][n-1][i] == -1){
	    parcial[0][n-1][i] = resposta(-n + 1, i);
	    parcial[1][n-1][i] = resposta(-n + 2, i);
	  }
	}
	guarda[n-1][k] = 0;
	for(i=0; i <= k; i++)
	  guarda[n-1][k] += parcial[0][n-1][i] * parcial[1][n-1][k-i];
      }
      printf("%d\n", guarda[n-1][k]);
    }
  return 0;
}
