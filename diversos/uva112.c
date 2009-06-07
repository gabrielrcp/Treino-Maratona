#include <stdio.h>
#include <stdlib.h>


typedef struct _cel {
  struct _cel *dir;
  struct _cel *esq;
  int val;
} Celula;


Celula *leArvore()
{
  int v;
  Celula *nova;
  while(getchar() != '(');
  if(scanf(" %d", &v) > 0){
    nova = (Celula *)malloc(sizeof(Celula));
    nova->val = v;
    nova->dir = leArvore();
    nova->esq = leArvore();
  }
  else
    nova = NULL;
  while(getchar() != ')');
  return nova;
}

void destroi(Celula *c)
{
  if(c == NULL)
    return;
  destroi(c->dir);
  destroi(c->esq);
  free(c);
}

int verifica(Celula *c, int soma)
{
  if(c == NULL)
    return 0;
  if(c->dir == NULL && c->esq == NULL)
    return (soma == c->val);
  soma -= c->val;
  if(verifica(c->dir, soma))
    return 1;
  return verifica(c->esq, soma);
}

/*
void imprime(Celula *c)
{
  if(c == NULL)
    return;
  printf("%d ", c->val);
  imprime(c->dir);
  imprime(c->esq);
}
*/

int main()
{
  int soma;
  Celula *raiz;
  while(scanf(" %d", &soma) != EOF)
    {
      raiz = leArvore();
      /*
      imprime(raiz);
      putchar('\n');
      */
      if(raiz != NULL && verifica(raiz, soma))
	printf("yes\n");
      else
	printf("no\n");
      destroi(raiz);      
    }
  return 0;
}
