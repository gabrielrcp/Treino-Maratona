#include <cstdio>

struct node{
  struct node *f[26];
};

node _nos[2000100];
int conta_nos;

node *novo_no()
{
  node *novo = &_nos[conta_nos];
  conta_nos++;
  for(int i = 0; i < 26; i++)
    novo->f[i] = NULL;
  return novo;
}

void insere(node *arv, char *s, int inc)
{
  if(*s == '\0')
    return;
  int i = *s - 'A';
  if(arv->f[i] == NULL)
    arv->f[i] = novo_no();
  insere(arv->f[i], s+inc, inc);
}

int conta(node *arv)
{
  if(arv == NULL)
    return 0;
  int r = 1;
  for(int i = 0; i < 26; i++)
    r += conta(arv->f[i]);
  return r;
}

char buf[500];

int main()
{
  int n, k;
  node *arv1, *arv2;
  scanf(" %d %d", &n, &k);

  conta_nos = 0;
  arv1 = novo_no();
  arv2 = novo_no();

  for(int i = 0; i < n; i++){
    scanf(" %s", buf);
    char c = buf[k];
    buf[k] = '\0';
    insere(arv1, buf, 1);

    buf[k] = c;
    buf[k-1] = '\0';
    insere(arv2, buf+2*k-1, -1);
  }
  printf("%d\n", conta(arv1) + conta(arv2) - 2);

  return 0;
}
