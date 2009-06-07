#include <stdio.h>

typedef struct {
  int numpre;
  int prec[100];
} Tarefa;


int n;
Tarefa tarefa[100];
int ordem[100];


int acha(int i, int j)
{
  int k;
  for(k=0; k < tarefa[i].numpre; k++)
    if(tarefa[i].prec[k] == j)
      return 1;
  return 0;
}

void retira(int i)
{
  int j, k;
  tarefa[i].numpre = -1;
  for(j=0; j < n; j++){
    for(k=0; k < tarefa[j].numpre; k++)
      if(tarefa[j].prec[k] == i){
	tarefa[j].numpre--;
	tarefa[j].prec[k] = tarefa[j].prec[tarefa[j].numpre];
	break;
      }
  }
}

int main()
{
  int m;
  int i, j, k;
  int conta;

  while(1)
    {
      scanf(" %d %d", &n, &m);
      if(n == m && m == 0)
	break;
      
      for(i=0; i<n; i++)
	tarefa[i].numpre = 0;
      
      for(i=0; i<m; i++){
	scanf(" %d %d", &j, &k);
	j--; k--;
	if(!acha(k, j)){
	  tarefa[k].prec[tarefa[k].numpre] = j;
	  tarefa[k].numpre++;
	}
      }
      
      conta = 0;
      while(conta < n){
	for(i=0; i<n; i++)
	  if(tarefa[i].numpre == 0){
	    ordem[conta] = i;
	    retira(i);
	    conta++;
	    break;
	  }
	if(i == n){
	  /*printf("Nao eh possivel executar\n");*/
	  break;
	}
      }
      if(conta < n)
	continue;

      printf("%d", (*ordem)+1);
      for(i=1; i<n; i++)
	printf(" %d", ordem[i]+1);
      putchar('\n');
    }
  return 0;
}
