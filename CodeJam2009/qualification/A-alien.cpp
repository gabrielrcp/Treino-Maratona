#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXND 100100

struct no{
  bool folha;
  struct no *f[26];
};

no _nos[MAXND];
int contano;
no *tree;

no *novo_no()
{
  no *nv = &_nos[contano++];
  nv->folha = true;
  for(int i = 0; i < 26; i++)
    nv->f[i] = NULL;
  return nv;
}

void insere(char *s, no *arv)
{
  if(*s == '\0') return;
  int i = *s - 'a';
  if(arv->f[i] == NULL){
    arv->folha = false;
    arv->f[i] = novo_no();
  }
  insere(s+1, arv->f[i]);
}


int resolve(char *s, no *arv)
{

  if(arv == NULL)
    return 0;
  if(arv->folha)
    return 1;

  if(*s != '(')
    return resolve(s+1, arv->f[*s-'a']);

  char *pt = s+1;
  while(*pt != ')')
    pt++;
  pt++;
  int r = 0;
  for(int i = 1; s[i] != ')'; i++)
    r += resolve(pt, arv->f[s[i]-'a']);

  //printf("%s %d\n", s, r);
  return r;  
}

char buf[1000];

void imprime(no *arv, int k)
{
  for(int i = 0; i < 26; i++){
    if(arv->f[i] != NULL){
      buf[k] = i+'a';
      imprime(arv->f[i], k+1);
    } 
  }
}


int main()
{
  int l, d, n;
  scanf(" %d %d %d", &l, &d, &n);
  contano = 0;
  tree = novo_no();

  while(d--){
    scanf(" %s", buf);
    insere(buf, tree);
  }
  
  for(int h = 1; h <= n; h++){
    scanf(" %s", buf);
    printf("Case #%d: %d\n", h, resolve(buf, tree));
  }
  

  return 0;
}
