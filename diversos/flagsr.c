#include <stdio.h>

typedef struct{
  int d;
  int p;
}BRINQUEDO;


BRINQUEDO brinq[100];
int pontos[601];
int n;

int maxpont(int t)
{
  int max=0;
  int atual, i;
  if(pontos[t] >= 0) return pontos[t];
  for(i=0; i<n; i++){
    if(brinq[i].d <= t){
      atual = brinq[i].p + maxpont(t - brinq[i].d);
      if(atual > max)
	max = atual;
    }
  }
  pontos[t] = max;
  return max;
}

int main()
{
  int t, i;
  int h=1;

  scanf(" %d", &n);
  while(n > 0){
    scanf(" %d", &t);
    for(i=0; i<n; i++)
      scanf(" %d %d", &(brinq[i].d), &(brinq[i].p));
    for(i=0; i<601; i++)
      pontos[i] = -1;

    printf("Instancia %d\n%d\n\n", h++, maxpont(t));
    scanf("%d", &n);
  }
  return 0;
}
