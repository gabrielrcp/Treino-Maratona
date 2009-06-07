#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int num;
  int ordem;
} Evento;

Evento correta[20];
Evento aluno[20];

int maior[20][20];


int compara(const void *a, const void *b)
{
  return ((Evento *)a)->ordem - ((Evento *)b)->ordem;
}


int main()
{
  int n;
  int i, j;

  scanf(" %d", &n);

  for(i=0; i<n; i++){
    scanf(" %d", &j);
    correta[i].num = i+1;
    correta[i].ordem = j;
  }
  qsort(correta, n, sizeof(Evento), compara);

  while(42)
    {
      if(!(scanf(" %d", &j) > 0))
	break;
      aluno[0].num = 1;
      aluno[0].ordem = j;
      for(i=1; i<n; i++){
	scanf(" %d", &j);
	aluno[i].num = i+1;
	aluno[i].ordem = j;
      }
      qsort(aluno, n, sizeof(Evento), compara);

      for(i=0; i<n; i++){
	maior[i][0] = (
		       (correta[i].num == aluno[0].num || maior[i-1][0] == 1)
		       ? 1 : 0
		       );
	maior[0][i] = (
		       (correta[0].num == aluno[i].num || maior[0][i-1] == 1)
		       ? 1 : 0
		       );
      }
      for(i=1; i<n; i++)
	for(j=1; j<n; j++){
	  if(maior[i-1][j] < maior[i][j-1])
	    maior[i][j] = maior[i][j-1];
	  else
	    maior[i][j] = maior[i-1][j];
	  if(correta[i].num == aluno[j].num && maior[i-1][j-1] >= maior[i][j])
	    maior[i][j] = maior[i-1][j-1] + 1;
	}
      printf("%d\n", maior[n-1][n-1]);
    }
  return 0;
}
