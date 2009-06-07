/* UVA 10131 - Is Bigger Smarter ? */
/* Accepted */


#include <stdio.h>
#include <stdlib.h>


#define MAX 1010

typedef struct{
  int ind;
  int qi;
  int peso;
}Elefante;

Elefante elef[MAX];
int maior[MAX];

int compara(const void *a, const void *b)
{
  Elefante *e1, *e2;
  e1 = (Elefante *)a;
  e2 = (Elefante *)b;
  if(e1->peso == e2->peso)
    return (e2->qi - e1->qi);
  return e1->peso - e2->peso;
}

int main()
{
  int i, j, n;
  int m;

  n = 0;
  while((!feof(stdin)) && scanf(" %d %d", &elef[n].peso, &elef[n].qi) > 0){
    elef[n].ind = n + 1;
    n++;
  }

  qsort(elef, n, sizeof(Elefante), compara);

  for(i = n - 1; i >= 0; i--){
    maior[i] = 1;
    for(j = i + 1; j < n; j++)
      if(elef[j].peso > elef[i].peso && elef[j].qi < elef[i].qi 
	 && maior[j] >= maior[i])
	maior[i] = maior[j] + 1;
  }

  m = 0;
  for(i = 1; i < n; i++)
    if(maior[i] > maior[m])
      m = i;
  
  printf("%d\n%d\n", maior[m], elef[m].ind);
  for(i = m + 1; i < n && maior[m] > 1; i++){
    if(elef[i].peso > elef[m].peso && elef[i].qi < elef[m].qi 
       && maior[i] == maior[m] - 1){
      printf("%d\n", elef[i].ind);
      m = i;
    }
  }
  return 0;
}
