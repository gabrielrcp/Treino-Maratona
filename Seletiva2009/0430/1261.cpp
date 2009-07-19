#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 210

struct node{
  int numf;
  struct node *f[10];
};

node _nos[MAX];
node *ll[MAX];
int topo;

int n, z;
char codifica[MAX];

node *tree;
int tam, lim;

node *novo()
{
  node *nv = ll[topo--];
  for(int i = 0; i < n; i++)
    nv->f[i] = NULL;
  nv->numf = 0;
  return nv;
}

void devolve(node *no)
{
  ll[++topo] = no;
}

void inicializa()
{
  for(int i = 0; i < MAX; i++)
    ll[i] = _nos+i;
  topo = MAX-1;
  tree = novo();
  tam = strlen(codifica);
  lim = 12;
}

bool verifica_completa(node *arv)
{
  if(arv->numf == 0)
    return true;
  if(arv->numf < n)
    return false;
  for(int i = 0; i < n; i++)
    if(!verifica_completa(arv->f[i]))
      return false;
  return true;
}


int marcas[MAX];

bool vai(int ini, int falta)
{
  if(falta == 0 && ini == tam){
    if(!verifica_completa(tree))
      return false;
    for(int k = 0; k < z; k++){
      printf("%d->", k);
      int j = (k == 0 ? 0 : marcas[k-1]+1);
      while(j <= marcas[k]){
	putchar(codifica[j]);
	j++;
      }
      putchar('\n');
    }
    return true;
  }
  if(falta == 0 || ini == tam)
    return false;

  node *arv = tree;
  
  int i = ini;
  while(1){
    char c = codifica[i];
    if(c == '\0')
      return false;
    if(arv->numf == 0 && arv != tree)
      return false;
    if(arv->f[c-'0'] == NULL)
      break;
    arv = arv->f[c-'0'];
    i++;
  }

  if(i - ini > lim)
    return false;

  if(falta == 1){
    if(i + 1 < tam)
      return false;
    arv->numf++;
    arv->f[codifica[i]-'0'] = novo();
    marcas[z-1] = tam - 1;

    if(vai(tam, 0))
      return true;

    devolve(arv->f[codifica[i]-'0']);
    arv->f[codifica[i]-'0'] = NULL;
    arv->numf--;
    return false;
  }

  int j = i;
  node *atual = arv, *nv;
  while(j + falta < tam && j - ini <= lim){
    int k = codifica[j] - '0';
      
    nv = novo();
    atual->f[k] = nv;
    atual->numf++;
    marcas[z-falta] = j;

    if(falta + atual->numf < n)
      break;
    if(vai(j+1, falta-1))
      return true;

    atual = nv;
    j++;
  }

  atual = arv->f[codifica[i]-'0'];
  arv->f[codifica[i]-'0'] = NULL;
  arv->numf--;
  i++;
  while(1){
    if(atual == NULL)
      break;
    devolve(atual);
    atual = atual->f[codifica[i]-'0'];
    i++;
  }

  return false;

}


void resolve()
{
  inicializa();
  vai(0, z);
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d %s", &z,&n, codifica);
    resolve();
  }
  return 0;
}
