/* DNA Sorting */
/* UVA 612 */
/* Accepted */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int ind;
  int ord;
} DNA;

char seq[100][50];
DNA dna[100];


int compara(const void *a, const void *b)
{
  if(((DNA *)a)->ord == ((DNA *)b)->ord)
    return (((DNA *)a)->ind - ((DNA *)b)->ind);
  return (((DNA *)a)->ord - ((DNA *)b)->ord);
}

int main()
{
  int casos;
  int n, m;
  int i, j, k;

  scanf(" %d", &casos);

  while(casos--)
    {
      scanf(" %d %d", &n, &m);
      for(i=0; i<m; i++)
	for(j=0; j<n; j++)
	  do{
	    seq[i][j] = getchar();
	  }while(seq[i][j] != 'A' && seq[i][j] != 'T' &&
		 seq[i][j] != 'C' && seq[i][j] != 'G');
      for(i=0; i<m; i++){
	dna[i].ind = i;
	dna[i].ord = 0;
	for(j=0; j<n; j++)
	  for(k=j+1; k<n; k++)
	    if(seq[i][j] > seq[i][k])
	      dna[i].ord++;
      }
      qsort(dna, m, sizeof(DNA), compara);
      for(i=0; i<m; i++){
	for(j=0; j<n; j++)
	  putchar(seq[dna[i].ind][j]);
	putchar('\n');
      }
      if(casos != 0)
	putchar('\n');
    }
  return 0;
}
