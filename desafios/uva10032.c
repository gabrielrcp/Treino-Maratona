/* Tug of War */
/* UVA 10032 */
/* Accepted */

#include <stdio.h>
#include<stdlib.h>
#include <strings.h>

#define MAX 22501

int  peso[100];
char possivel[52][MAX];
int parcial[101];

void quicksort(int *v, int ll, int rr)
{
 int i, j, key;
 int tmp;
 while (ll < rr) {
   key = v[ll];
   i = ll+1;
   j = rr;
   while (1) {
     while (i <= rr && v[i] <= key) ++i;
     while (key < v[j]) --j;
     if (i >= j) break;
     tmp = v[i]; v[i] = v[j]; v[j] = tmp;
     ++i; --j;
   }
   tmp = v[ll]; v[ll] = v[j]; v[j] = tmp;
   if (j - ll < rr - j) {
      quicksort(v, ll, j-1);
      ll = j + 1;
   } else {
      quicksort(v, j+1, rr);
      rr = j - 1;
   }
 }
}

int compara(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int main()
{
  int casos, n, n2;
  int i, j;
  int total, metade;
  int at, novo;
  int saida;
  int impar;

  scanf(" %d", &casos);
  while(casos--)
    {
      scanf(" %d", &n);
      impar = n % 2;
      n2 = n / 2;


      total = 0;
      for(i = 0; i < n; i++){
	scanf(" %d", peso+i);
	total += peso[i];
      }

      metade = total / 2;

      for(j=0; j <= n2+impar; j++)
	bzero(possivel[j], (metade+1)*sizeof(char));
      possivel[0][0] = 1;
      
      quicksort(peso, 0, n-1);
      /*qsort(peso, n, sizeof(int), compara);*/


      parcial[0] = 0;
       for(i = 0; i < n; i++)
	parcial[i+1] = parcial[i] + peso[i];	


      saida = 0;
      
      for(i = 1; i <= n; i++){
	at = peso[i-1];
	j = i;
	if(j > n2)
	  j = n2 + impar;

	while(j > 0 && j >= i + n2 - n){
	  novo = saida - (total - parcial[n - (n2+impar-j)]);
	  if(novo < at)
	    novo = at;
	  while(novo <= metade - (parcial[i+n2-j] - parcial[i])
		&& novo <= metade){
	    if(possivel[j-1][novo - at]){
	      possivel[j][novo] = 1;
	      if(j >= n2 && novo > saida)
		saida = novo;
	    }
	    novo++;
	  }
	  j--;    
	}
      }
      

      printf("%d %d\n", saida, total - saida);

      if(casos)
	putchar('\n');
    }
  return 0;
}
