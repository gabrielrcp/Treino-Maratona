#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char buf[55];

int lernum()
{
  int r = 0;
  gets(buf);
  sscanf(buf, " %d", &r);
  return r;  
}

char letra[55];
string cod[55];
int n;

char msg[2600];
int conta = 0;
string resp = "";

struct node{
  char id;
  node *f[2];
};

node _nos[50000];
int nume;

node *novo_no()
{
  node *r = &_nos[nume++];
  r->f[0] = r->f[1] = NULL;
  r->id = -1;
  return r;
}

node *adiciona(string &s, int i, node *arv)
{
  if(i == (int)s.size())
    return ((arv->id == -1) ? arv : NULL);
  if(arv->id != -1)
    return NULL;

  int j = s[i] - '0';
  if(arv->f[j] == NULL)
    arv->f[j] = novo_no();
  return adiciona(s, i+1, arv->f[j]);
}

int busca(char *s, node *arv)
{
  if(arv->f[0] == NULL && arv->f[1] == NULL)
    return arv->id;
  if(*s == '\0')
      return -1;

  int i = *s - '0';
  if(arv->f[i] == NULL)
    return -1;
  return busca(s+1, arv->f[i]);  
}

bool verifica()
{
  nume = 0;
  node *arv = novo_no();
  for(int i = 0; i < n; i++){
    node *at;
    at = adiciona(cod[i], 0, arv);
    if(at == NULL)
      return false;
    at->id = i;
  }
  string at = "";
  int i = 0;
  while(msg[i]){
    int id = busca(msg+i, arv);
    if(id == -1) return false;
    at += letra[id];
    i += cod[id].size();
  }
  if(conta == 0){
    conta++;
    resp = at;
  } else if(conta == 1){
    if(resp != at)
      conta++;
  }
  return true;
}

void forca_bruta(int i, int j)
{
  if(conta > 1) return;
  if(i == n){
    verifica();
    return;
  }
  if(j == (int)cod[i].size()){
    forca_bruta(i+1, 0);
    return;
  }
  if(cod[i][j] != '?'){
    forca_bruta(i, j+1);
    return;
  }
  cod[i][j] = '0';
  forca_bruta(i, j+1);
  cod[i][j] = '1';
  forca_bruta(i, j+1);
  cod[i][j] = '?';
}

int main()
{
  int casos = lernum();
  while(casos--){
    n = lernum();
    for(int i = 0; i < n; i++){
      gets(buf);
      letra[i] = buf[0];
      cod[i] = buf+2;
    }
    int tt = lernum();
    int m = 0;
    while(tt--){
      gets(msg+m);
      m += strlen(msg+m);
    }
    conta = 0;
    forca_bruta(0, 0);
    if(conta == 1)
      printf("%s\n", resp.c_str());
    else
      printf("\n");
    //printf("%d\n", conta);
  }
  return 0;
}
