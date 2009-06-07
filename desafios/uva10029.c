/* UVA 10029 - Edit Step Ladders
   Accepted */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _v{
  int v;
  struct _v *prox;
} Vert;

char dict[25000][20];
Vert vert[25000];
int n;
int memoriza[25000];


void adiciona(int i, int j)
{
  Vert *novo;
  novo = malloc(sizeof(Vert));
  novo->v = j;
  novo->prox = vert[i].prox;
  vert[i].prox = novo;
}

int maior(int p)
{
  Vert *v;
  int saida, t;
  
  if(memoriza[p] != 0)
    return memoriza[p];
  saida = 0;
  for(v = vert[p].prox; v != NULL; v = v->prox){
    t = maior(v->v);
    if(t > saida)
      saida = t;
  }
  saida++;
  memoriza[p] = saida;
  
  return saida;
}

int acha(char *buf)
{
  int m, e = 0, d = n-1;
  int t;
  while(e <= d){
    m = (e + d) / 2;
    t = strcmp(dict[m], buf);
    if(t < 0)
      e = m + 1;
    else if(t > 0)
      d = m - 1;
    else
      return m;
  }
  return -1;
}


int main()
{
  int i, j, k;
  int resp;
  char c, buf[20];

  n = 0;
  while((!feof(stdin)) && scanf(" %s", dict[n]) > 0){
    vert[n].v = 0;
    vert[n].prox = NULL;
    memoriza[n] = 0;
    n++;
  }

  for(i=0; i<n; i++){

    /* Mudar letra */
    strcpy(buf, dict[i]);
    for(j = 0; buf[j] != '\0'; j++){
      for(c = buf[j] + 1; c <= 'z'; c++){
	buf[j] = c;
	k = acha(buf);
	if(k != -1)
	  adiciona(i, k);
      }
      buf[j] = dict[i][j];
    }
    
    /* Tirar Letra*/
    strcpy(buf, &dict[i][1]);
    if(strcmp(dict[i], buf) < 0){
      k = acha(buf);
      if(k != -1)
	adiciona(i, k);
    }
    for(j = 1; buf[j] != '\0'; j++){
      buf[j-1] = dict[i][j-1];
      if(strcmp(dict[i], buf) < 0){
	k = acha(buf);
	if(k != -1)
	  adiciona(i, k);
      }
    }

    /* Colocar letra */
    strcpy(buf+1, dict[i]);
    for(c = 'a'; c <= 'z'; c++){
      buf[0] = c;
       if(strcmp(dict[i], buf) < 0){
	 k = acha(buf);
	 if(k != -1)
	   adiciona(i, k);
       }
    }
    for(j = 1; buf[j] != '\0'; j++){
      buf[j-1] = dict[i][j-1];
      for(c = 'a'; c <= 'z'; c++){
	buf[j] = c;
	if(strcmp(dict[i], buf) < 0){
	  k = acha(buf);
	  if(k != -1)
	    adiciona(i, k);
	}
      }
    }
    
  }
  /*    
  for(i=0; i < n; i++){
    Vert *v;
    printf("%s | ", dict[i]);
    for(v = vert[i].prox; v != NULL; v = v->prox)
      printf("%s ", dict[v->v]);
    printf("\n");
  }
  */

  resp = 0;
  for(i=0; i<n; i++)
    if(maior(i) > resp)
      resp = memoriza[i];

  printf("%d\n", resp);

  return 0;
}
