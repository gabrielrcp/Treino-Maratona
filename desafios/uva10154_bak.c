#include <stdio.h>
#include <stdlib.h>

#define MAX 6000

typedef struct {
  int peso;
  int forca;
} Tart;

Tart tart[MAX];



int compara(const void *a, const void *b)
{
  if(((Tart *)a)->forca == ((Tart *)b)->forca)
    return(((Tart *)a)->peso - ((Tart *)b)->peso);
  return(((Tart *)b)->forca - ((Tart *)a)->forca);
}

int main()
{
  int n;
  int i;

  n = 0;
  while(!feof(stdin)){
    if(scanf(" %d %d", &tart[n].peso, &tart[n].forca) != 2)
      break;
    if(tart[n].forca >= tart[n].peso)
      n++;
  }

  n++;
  qsort(tart, n, sizeof(Tart), compara);


  return 0;
}
