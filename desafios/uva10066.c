/* UVA 10066 - The Twin Towers
   Accepted */

#include <stdio.h>

#define MAX 110

int seq1[MAX], seq2[MAX];
int maior[MAX][MAX];

int main()
{
  int h;
  int n1, n2;
  int i, j;

  for(h = 1; ; h++){
    scanf("%d %d", &n1, &n2);
    if(n1 == n2 && n2 == 0)
      break;

    for(i = 0; i < n1; i++)
      scanf(" %d", seq1+i);

    for(i = 0; i < n2; i++)
      scanf(" %d", seq2+i);

    for(i = 0; i <= n1; i++)
      for(j = 0; j <= n2; j++)
	maior[i][j] = 0;

    for(i = n1 - 1; i >= 0; i--)
      for(j = n2 - 1; j >= 0; j--){
	if(seq1[i] == seq2[j])
	  maior[i][j] = maior[i+1][j+1] + 1;
	if(maior[i][j] < maior[i+1][j])
	  maior[i][j] = maior[i+1][j];
	if(maior[i][j] < maior[i][j+1])
	  maior[i][j] = maior[i][j+1];
      }

    printf("Twin Towers #%d\n", h);
    printf("Number of Tiles : %d\n\n", maior[0][0]);
  }
  return 0;
}
