#include <cstdio>

#define MAX 300010

struct node{
  bool final;
  struct node *f[26];
};

node _nos[400100];
int conta_no;


node *novo()
{
  node *n;
  n = &_nos[conta_no++];
  n->final = false;
  for(int i = 0; i < 26; i++)
    n->f[i] = NULL;
  return n;
}


node *inicia()
{
  node *arv;
  conta_no = 0;
  return(novo());
}

void adiciona(node *arv, char *str)
{
  if(*str == '\0'){
    arv->final = true;
    return;
  }
  if(arv->f[*str - 'a'] == NULL)
    arv->f[*str - 'a'] = novo();
  adiciona(arv->f[*str - 'a'], str+1);
}

char pal[MAX];
char buf[110];
node *tree;
#define MOD 1337377

int memo[MAX];

int vai(int i)
{
  if(pal[i] == '\0')
    return 1;

  int &r = memo[i];
  if(r != -1)
    return r;

  r = 0;
  node *arv = tree, *temp;
  for(int j = i; pal[j] != '\0';j++){
    temp = arv->f[pal[j]-'a'];
    if(temp == NULL)
      return r;
    if(temp->final){
      r += vai(j+1);
      r %= MOD;
    }
    arv = temp;
  }
  return r;
}



void imprime(node *arv, int k)
{
  if(arv->final){
    buf[k] = '\0';
    printf("%s\n", buf);
  }
  for(int i = 0; i < 26; i++)
    if(arv->f[i] != NULL){
      buf[k] = i+'a';
      imprime(arv->f[i], k+1);
    }
}

int main()
{
  int n;
  scanf(" %s", pal);

  for(int i = 0; pal[i] != '\0'; i++){
    if('A' <= pal[i] && pal[i] <= 'Z')
      pal[i] = pal[i] - 'A' + 'a';
    memo[i] = -1;
  }

  scanf(" %d", &n);
  tree = inicia();
  while(n--){
    scanf(" %s", buf);
    adiciona(tree, buf);
  }

  //imprime(tree, 0);  
  /*
  printf("%s\n", pal);
  for(int i = 0; pal[i] != '\0'; i++)
    printf("%d", vai(i));
  printf("\n");
  */
  printf("%d\n", vai(0));

  return 0;
}
