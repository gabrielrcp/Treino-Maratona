/* Childrens Game */
/* UVA 10905 */
/* Accepted */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **numeros;


int compara(const void *p1, const void *p2)
{
  char *a = *(char **)p1;
  char *b = *(char **)p2;
  int i;

  for(i=0; a[i] != '\0' && b[i] != '\0'; i++)
    {
      if(a[i] < b[i])
	return 1;
      else if(a[i] > b[i])
	return -1;
    }
  if(a[i] == b[i])
    return 0;

  if(a[i] == '\0'){
    b += i;
    return compara(&a, &b);
  }
  else{
    a += i;
    return compara(&a, &b);
  }
}

int main()
{
  int n;
  int i;

  numeros = (char **)malloc(50*sizeof(char *));
  for(i=0; i<50; i++)
    numeros[i] = (char *)malloc(500*sizeof(char));

  while(42)
    {
      scanf(" %d", &n);
      if(n == 0)
	break;
      for(i=0; i<n; i++)
	scanf(" %s", numeros[i]);

      qsort(numeros, n, sizeof(char **), compara);

      for(i=0; i<n; i++)
	printf("%s", numeros[i]);
      printf("\n");
    }
  
  for(i=0; i<50; i++)
    free(numeros[i]);
  free(numeros);
  
  return 0;
}
