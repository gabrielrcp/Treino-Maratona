/* UVA 10044 - Erdös numbers
   Accepted */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXNOM 10000
#define INFI 2147483647 /*2^31 - 1*/


typedef struct __v{
  int v;
  struct __v *prox;
}Vert;

Vert vert[MAXNOM];


char nomes[MAXNOM][100];
int nnom;

int ladd[MAXNOM];
int nadd;


int dist[MAXNOM];
int FILA[MAXNOM];
int ini, fim;



void adiciona(int i, int j)
{
  Vert *novo;
  novo = malloc(sizeof(Vert));
  novo->v = j;
  novo->prox = vert[i].prox;
  vert[i].prox = novo;
}

int acha(char *s)
{
  int i;
  for(i=0; i<nnom; i++)
    if(strcmp(s, nomes[i]) == 0)
      break;
  return i;
}

int jahfoi(int i){
  int j;
  for(j = 0; j < nadd; j++)
    if(ladd[j] == i)
      return 1;
  return 0;
}

int main()
{
  int casos, h;
  int p, n;
  char buf[200];
  char flag;
  int i, j;
  Vert *v;

  scanf(" %d", &casos);
  for(h = 1; h <= casos; h++){
    scanf(" %d %d ", &p, &n);
    nnom = 0;

    while(p--){
      nadd = 0;
      i = 0; flag = 0;
      while(42){
	if((buf[i] = getchar()) == '\n')
	  break;
	
	if(buf[i] != ',' && buf[i] != ':'){
	  if(buf[i] != ' ' || i != 0)
	    i++;
	  continue;
	}
	
	if(buf[i] == ',' && flag == 0){
	  flag = 1;
	  i++;
	  continue;
	}

	if(buf[i] == ':' && flag == 0){
	  while(getchar() != '\n');
	  break;
	}

	while(i > 0 && isspace(buf[i-1]))
	  i--;
	buf[i] = '\0';

	j = acha(buf);
	if(j == nnom){
	  strcpy(nomes[nnom], buf);
	  vert[nnom].prox = NULL;
	  nnom++;
	}
	if(jahfoi(j) == 0){
	  ladd[nadd] = j;
	  nadd++;
	}
	if(buf[i] == ':'){
	  while(getchar() != '\n');
	  break;
	}

	flag = 0;
	i = 0;
      }
      /*printf("p=%d nadd=%d\n", p, nadd);*/
      for(i = 0; i < nadd; i++)
	for(j = 0; j < nadd; j++)
	  if(i != j){
	    adiciona(ladd[i], ladd[j]);
	    /*printf("%s -> %s\n", nomes[i], nomes[j]);*/
	  }
    }

    ini = fim = 0;
    for(i = 0; i < nnom; i++){
      if(strcmp(nomes[i], "Erdos, P.") == 0){
	dist[i] = 0;
	FILA[fim] = i;
	fim++;
      }
      else
	dist[i] = INFI;
    }
    
    while(ini < fim){
      i = FILA[ini];
      ini++;
      for(v = vert[i].prox; v != NULL; v = v->prox){
	j = v->v;
	if(dist[j] > dist[i] + 1){
	  dist[j] = dist[i] + 1;
	  FILA[fim] = j;
	  fim++;
	}
      }
    }
    /*    
    printf("-------\n");
    for(i = 0; i<nnom; i++){
      printf("%s %d\n", nomes[i], dist[i]);
    }
    printf("-------\n");
    */
    /*
    printf("-------\n");
    for(i = 0; i < nnom; i++){
      printf("%s ", nomes[i]);
      for(v = vert[i].prox; v != NULL; v = v->prox)
	printf("|%s ", nomes[v->v]);
      printf("\n");
    }
    printf("-------\n");
    */


    printf("Scenario %d\n", h);

    while(n--){
      scanf(" %[^\n]", buf);
      i = acha(buf);
      /*
      if(i == nnom){
	printf("aaaaaaaa!!!\n");
	continue;
      }
      */
      printf("%s ", buf);
      if(i == nnom || dist[i] == INFI)
	printf("infinity");
      else
	printf("%d", dist[i]);
      putchar('\n');
      
    }

  }
  return 0;
}
