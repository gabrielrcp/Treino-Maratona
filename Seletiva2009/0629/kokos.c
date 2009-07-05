#include <stdio.h>
#include <ctype.h>

typedef struct _node{
  struct _node *f[26];
} node;

node _nos[2000100];
int conta_nos;

node *novo_no()
{
  int i;
  node *novo = &_nos[conta_nos];
  conta_nos++;
  for(i = 0; i < 26; i++)
    novo->f[i] = NULL;
  return novo;
}

void insere(node *arv, char *s)
{
  int i;
  if(*s == '\0')
    return;
  i = *s - 'A';
  if(arv->f[i] == NULL)
    arv->f[i] = novo_no();
  insere(arv->f[i], s+1);
}

int conta(node *arv)
{
  int r, i;
  if(arv == NULL)
    return 0;
  r = 1;
  for(i = 0; i < 26; i++)
    r += conta(arv->f[i]);
  return r;
}

char buf[500];

int main()
{
  int n, k;
  node *arv1, *arv2;
  int i, j;
  char c;
  scanf(" %d %d", &n, &k);

  conta_nos = 0;
  arv1 = novo_no();
  arv2 = novo_no();

  buf[k] = '\0';
  for(i = 0; i < n; i++){
    while(isspace(c = getchar()));
    buf[0] = c;

    for(j = 1; j < k; j++)
      buf[j] = getchar();
    insere(arv1, buf);


    for(j = k-1; j >= 0; j--)
      buf[j] = getchar();
    insere(arv2, buf);

  }
  printf("%d\n", conta(arv1) + conta(arv2) - 2);

  return 0;
}
