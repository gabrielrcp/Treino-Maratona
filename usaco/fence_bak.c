/*
ID: gabriel9
LANG: C
TASK: fence
*/

#include <stdio.h>
#include <stdlib.h>

/*
typedef struct _no {
  struct _no *prox;
  int vert;
} No;

No al[500];
*/
int grau[500];
char grafo[500][500];
FILE *fin, *fout;

void circuito(int v)
{
  int u, min = 1;
  
  while(grau[v] > 0){
    for(u=0; u < 500; u++)
      if(grafo[u][v] && grau[u] > min)
	break;

    if(u == 500 && min == 1){
      min = 0;
      continue;
    }
    fprintf(fout, "%d\n", v+1);

    grafo[u][v] = grafo[v][u] = 0;
    grau[u]--;
    grau[v]--;
    v = u;
  }
  
  fprintf(fout, "%d\n", v + 1);
}


int main()
{
  int n = 500, f;
  int i, j, k;
  /*No *temp, *novo;*/

  fin = fopen("fence.in", "r");
  fout = fopen("fence.out", "w");
  
  fscanf(fin, " %d", &f);

  for(k = 0; k < f; k++){
    fscanf(fin, " %d %d", &i, &j);
    i--; j--;
    grafo[i][j] = grafo[j][i] = 1;
    grau[i]++;
    grau[j]++;
  }
  /*
  for(i=0; i < n; i++)
    al[i].prox = NULL;

  for(k = 0; k < f; k++){
    fscanf(fin, " %d %d", &i, &j);
    i--; j--;
    grau[i]++;
    grau[j]++;
    if(al[i].prox == NULL || (al[i].prox)->vert < j){
      novo = (No *)malloc(sizeof(No));
      novo->vert = j;
      novo->prox = al[i].prox;
      al[i].prox = novo;
    }
    else{
      novo = NULL;
      for(temp = al[i].prox; temp->prox != NULL; temp = temp->prox){
	if(temp->prox->vert < j){
	  novo = (No *)malloc(sizeof(No));
	  novo->vert = j;
	  novo->prox = temp->prox;
	  temp->prox = novo;
	}
      }
      if(novo == NULL){
	novo = (No *)malloc(sizeof(No));
	novo->vert = j;
	novo->prox = temp->prox;
	temp->prox = novo;
      }
    }


    if(al[j].prox == NULL || (al[j].prox)->vert < i){
      novo = (No *)malloc(sizeof(No));
      novo->vert = i;
      novo->prox = al[j].prox;
      al[j].prox = novo;
    }
    else{
      novo = NULL;
      for(temp = al[j].prox; temp->prox != NULL; temp = temp->prox){
	if(temp->prox->vert < i){
	  novo = (No *)malloc(sizeof(No));
	  novo->vert = i;
	  novo->prox = temp->prox;
	  temp->prox = novo;
	}
      }
      if(novo == NULL){
	novo = (No *)malloc(sizeof(No));
	novo->vert = i;
	novo->prox = temp->prox;
	temp->prox = novo;
      }
    }
  }
  */

  
  for(i=0; i<500; i++)
    if(grau[i] % 2 == 1){
      circuito(i);
      break;
    }
  if(i == 500)
    for(i=0; i<n; i++)
      if(grau[i] > 0){
	circuito(i);
	break;
      }
  
  /*
  for(i=0; i<n; i++){
    if(al[i].prox == NULL)
      continue;
    printf("%d: ", i+1);
    for(temp = al[i].prox; temp != NULL; temp = temp->prox)
      printf("%d ", temp->vert+1);
    printf("\n");
  }
  */
  return 0;
}
