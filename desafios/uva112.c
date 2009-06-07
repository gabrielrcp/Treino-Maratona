/* Tree Summing */
/* UVA 112 */
/* Accepted */

#include <stdio.h>
#include <stdlib.h>

typedef struct _cel
{
  int v;
  struct _cel *e;
  struct _cel *d;
} Celula;


Celula *ler()
{
  char c;
  Celula *cel;
  int v;

  do{
    c = getchar();
  }while(c != '(');


  if(scanf(" %d", &v) == 0)
    cel = NULL;
  else{
    cel = malloc(sizeof(Celula));
    cel->v = v;
    cel->e = ler();
    cel->d = ler();
  }
  do{
    c = getchar();
  }while(c != ')');

  return cel;
}

void destroi(Celula *cel)
{
  if(cel != NULL){
    destroi(cel->e);
    destroi(cel->d);
  }
  free(cel);
}



int consigosomar(Celula *cel, int soma)
{

  if(cel == NULL)
    return 0;
  soma -= cel->v;

  if(cel->d == NULL && cel->e == NULL && soma == 0)
    return 1;

  if(consigosomar(cel->d, soma))
    return 1;
  
  if(consigosomar(cel->e, soma))
    return 1;

  return 0;
}

int main()
{
  int soma;
  Celula *cel;

  while(scanf(" %d", &soma) != EOF)
    {
      cel = ler();
      
      if(consigosomar(cel, soma))
	printf("yes\n");
      else
	printf("no\n");
      
      destroi(cel);
    }
  return 1;
}
