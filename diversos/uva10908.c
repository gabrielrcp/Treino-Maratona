#include <stdio.h>


char matriz[101][101];

int main()
{
  int t;
  int m, n, q;
  int r, c;
  int i, j;
  char tipo;
  int tam;

  scanf(" %d", &t);

  while(t--)
    {
      scanf(" %d %d %d", &m, &n, &q);
      for(i=0; i<m; i++)
	for(j=0; j<n; j++)
	  scanf(" %c", &matriz[i][j]);

      printf("%d %d %d\n", m, n, q);

      while(q--)
	{
	  scanf(" %d %d", &r, &c);
	  tipo = matriz[r][c];
	  tam = 0;
	  while(1){
	    tam++;
	    if(r - tam < 0 || c - tam < 0 || r + tam >= m || c + tam >= n){
	      tam--;
	      goto saida;
	    }


	    i = r - tam;
	    for(j = c - tam; j <= c + tam; j++)
	      if(matriz[i][j] != tipo){
		tam--;
		goto saida;
	      }
	    i = r + tam;
	    for(j = c - tam; j <= c + tam; j++)
	      if(matriz[i][j] != tipo){
		tam--;
		goto saida;
	      }


	    j = c - tam;
	    for(i = r - tam; i <= r + tam; i++)
	      if(matriz[i][j] != tipo){
		tam--;
		goto saida;
	      }
	    j = c + tam;
	    for(i = r - tam; i <= r + tam; i++)
	      if(matriz[i][j] != tipo){
		tam--;
		goto saida;
	      }
	  }
	
	saida:
	  printf("%d\n", 2*tam+1);
	}
    }
  return 0;
}
