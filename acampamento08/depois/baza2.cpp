#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

struct letra{
  int v;
  struct letra *prox[30];
};

#define MAX 30010

letra temp[40*MAX];
int atual;

letra *novo()
{
  for(int i = 0; i < 30; i++)
    temp[atual].prox[i] = NULL;
  temp[atual].v = 0;
  return &temp[atual++];
}


void insere(char *s, letra *arv)
{
  if(*s == '\0')
    return;

  int j = *s - 'a';
  if(arv->prox[j] == NULL)
    arv->prox[j] = novo();
  arv->prox[j]->v++;
  insere(s+1, arv->prox[j]);
  
}


int consulta(char *s, letra *arv)
{
  int r = 0;
  while(*s != '\0'){
    int j = *s - 'a';
    arv = arv->prox[j];
    if(arv == NULL) return r;
    r += arv->v;
    s++;
  }
  return r;
}


void imprime(letra *arv, char *s, int p)
{
  if(arv == NULL)
    return;
  for(int i = 0; i < p; i++)
    printf("%c", s[i]);
  printf(" %d\n", arv->v);
  for(int i = 0; i < 29; i++){
    if(arv->prox[i] != NULL){
      s[p] = i + 'a';
      imprime(arv->prox[i], s, p+1);
    }
  }
}


void imprime2(letra *arv, char *s, int p)
{
  if(arv == NULL)
    return;
  
  if(arv->prox[29] != NULL){
    for(int i = 0; i < p; i++)
      printf("%c", s[i]);
    printf(" %d\n", arv->prox[29]->v);
  }
  
  for(int i = 0; i < 29; i++){
    s[p] = i + 'a';
    imprime2(arv->prox[i], s, p+1);
  }
}


int main()
{
  int n, q;
  char buf[40];

  while(scanf(" %d", &n) == 1){
    atual = 0;
    map<string, int> M;
    letra *arv = novo();
    for(int i = 1; i <= n; i++){
      scanf(" %s", buf);
      insere(buf, arv);
      M[buf] = consulta(buf, arv) + i;
    }
    scanf(" %d", &q);
    for(int i = 0; i < q; i++){
      scanf(" %s", buf);
      if(M.find(buf) == M.end())
	printf("%d\n", consulta(buf, arv) + n);
      else
	printf("%d\n", M[buf]);
    }
  }
  return 0;
}
