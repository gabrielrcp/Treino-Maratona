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

    for(i=1; i<=t; i++){ /* i: tempo */
      for(j=0; j<n; j++){ /* j: brinquedo  */
	for(k=1; brinq[j].d * k <= i; k++){
	  if((k * brinq[j].p) + pont[i-(k * brinq[j].d)] > pont[i])
	    pont[i] = (k * brinq[j].p) + pont[i - (k * brinq[j].d)];
	}
      }
    }
    printf("Instancia %d\n%d\n\n", h++, pont[t]);
    scanf("%d", &n);
  }
  return 0;
}
