#include <stdio.h>

typedef struct{
  int d;
  int p;
}BRINQUEDO;

int main()
{
  int n, t;
  int i, j, k;
  BRINQUEDO brinq[100];
  int pont[601];
  int h=1;

  scanf(" %d", &n);
  while(n > 0){
    scanf(" %d", &t);
    for(i=0; i<n; i++)
      scanf(" %d %d", &(brinq[i].d), &(brinq[i].p));
    for(i=0; i<=t; i++)
      pont[i] = 0;

    for(i=0; i<n; i++){ /* percorre os brinquedos */
      for(j=1; j <= t; j++){ /* tempo */
	for(k=1; k*brinq[i].d <= j; k++){ /* quantas vezes aquele brinquedo */
	  if( pont[j] < (brinq[i].p * k) + (pont[j - (brinq[i].d * k)]))
	    pont[j] = (brinq[i].p * k) + (pont[j - (brinq[i].d * k)]);
	}
      }
    }
    printf("Instancia %d\n%d\n\n", h++, pont[t]);
    scanf("%d", &n);
  }
  return 0;
}
