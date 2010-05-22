#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <cstring>

using namespace std;

struct no{
  map<string, no*> filhos;
};

no _nos[10000000];
int contano;

no *novo()
{
  no *nv = &_nos[contano++];
  nv->filhos.clear();
  return nv;
}

char buf[200];

int insere(no *arv, char *s)
{
  if(*s == '\0')
    return 0;
  //printf("%s\n", s);

  char *t = s;
  while(*t != '\0' && *t != '/')
    t++;
  *t = '\0';

  //printf("%s\n", s);

  if(arv->filhos.find(s) != arv->filhos.end())
    return insere(arv->filhos[s], t+1);
  else{
    arv->filhos[s] = novo();
    return 1 + insere(arv->filhos[s], t+1);
  }
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int N, M;
    scanf(" %d %d", &N, &M);
    contano = 0;
    no *arv = novo();
    while(N--){
      scanf(" %s", buf);
      buf[strlen(buf)+1] = '\0';
      insere(arv, buf+1);
    }
    int resp = 0;
    while(M--){
      scanf(" %s", buf);
      buf[strlen(buf)+1] = '\0';
      resp += insere(arv, buf+1);
    }
    printf("Case #%d: %d\n", h, resp);
  }
  
  return 0;
}
