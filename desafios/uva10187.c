/* UVA 10187 - From Dusk to Down
   Accepted */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INFI 99999999
#define TAML 1010

typedef struct _r_{
  int d;
  int sai, demora;
  struct _r_ *prox;
} Rota;

typedef struct {
  char nome[40];
  char visitado;
  int min;
  Rota *prox;
} Cidade;

Cidade cidade[100];
Rota *livre;
int n;


void inicializa()
{
  Rota *l, *t;
  int i;
  l = malloc(TAML*sizeof(Rota));
  t = livre = l;
  for(i = 1; i < TAML; i++){
    t->prox = l+i;
    t = t->prox;
  }
  t->prox = NULL;
    
}

Rota *aloca()
{
  Rota *t;
  t = livre;
  livre = livre->prox;
  return t;
}

void destroi(Rota *t)
{
  
  if(t == NULL)
    return;
  destroi(t->prox);
  t->prox = livre;
  livre = t;
}

int acha(char *s)
{
  int i;
  for(i = 0; i < n; i++)
    if(strcmp(s, cidade[i].nome) == 0)
      break;
  return i;
}


int minimo()
{
  int i, r = 0;
  while(cidade[r].visitado)
    r++;
  for(i = r + 1; i<n; i++)
    if(cidade[i].visitado == 0 && cidade[i].min < cidade[r].min)
      r = i;
  return r;
}

int main()
{
  int casos, h;
  int m;
  int i, j;
  int o, d;
  int sai, demora, chega;
  char buf[40];
  Rota *r;
  int novo, espera;

  scanf(" %d", &casos);

  inicializa();

  for(h = 1; h <= casos; h++){

    n = 0;
    scanf(" %d", &m);
    while(m--){
      scanf(" %s", buf);
      i = acha(buf);
      if(i == n){
	strcpy(cidade[i].nome, buf);
	cidade[i].visitado = 0;
	cidade[i].min = INFI;
	cidade[i].prox = NULL;
	n++;
      }
      scanf(" %s", buf);
      j = acha(buf);
      if(j == n){
	strcpy(cidade[j].nome, buf);
	cidade[j].visitado = 0;
	cidade[j].min = INFI;
	cidade[j].prox = NULL;
	n++;
      }

      scanf(" %d %d", &sai, &demora);
      chega = (sai + demora) % 24;
      
      if((6 <= sai && sai < 18) || demora > 12 ||(6 < chega && chega <= 18))
	continue;

      r = aloca();
      r->d = j;
      r->sai = sai % 24;
      r->demora = demora;
      r->prox = cidade[i].prox;
      cidade[i].prox = r;
    }

    /*
    for(i = 0; i< n; i++){
      printf("%s | ", cidade[i].nome);
      for(r = cidade[i].prox; r != NULL; r = r->prox){
	printf("%s  ", cidade[r->d].nome);
      }
      printf("\n");
    }
    */

    scanf(" %s", buf);
    o = acha(buf);
    scanf(" %s", buf);
    d = acha(buf);

    cidade[o].min = 18;
    while(1){
      i = minimo();
      if(i == n || i == d)
	break;
      cidade[i].visitado = 1;
      for(r = cidade[i].prox; r != NULL; r = r->prox){
	espera = r->sai - (cidade[i].min % 24);
	if(espera < 0)
	  espera += 24;
	espera %= 24;
	novo = cidade[i].min + espera + r->demora;
	if(novo < cidade[r->d].min)
	  cidade[r->d].min = novo;
      }
    }
    /*
    for(i = 0; i< n; i++)
      printf("%s  - %d\n", cidade[i].nome, cidade[i].min);
    printf("\n");
    */
    printf("Test Case %d.\n", h);
    if(cidade[d].min == INFI)
      printf("There is no route Vladimir can take.\n");
    else
      printf("Vladimir needs %d litre(s) of blood.\n", (cidade[d].min - 12)/24);

    for(i = 0 ; i < n; i++)
      destroi(cidade[i].prox);
    
  }
  return 0;
}
