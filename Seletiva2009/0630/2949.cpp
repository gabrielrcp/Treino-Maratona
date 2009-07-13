#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define MAX 676
#define MAX2 5000000

struct node{
  int c;
  int v;
};

node G[MAX][MAX];
int num[MAX];
int mat[MAX][MAX];
int numpos;

inline int numera(char a, char b)
{
  return 26*(int)(a-'a') + (int)(b-'a');
}

char buf[1010];
int maximo;
double resposta;

void nova_aresta()
{
  scanf(" %s", buf);
  int n = strlen(buf);
  if(n < 2) return;

  int i = numera(buf[0], buf[1]);
  int j = numera(buf[n-2], buf[n-1]);

  if(i == j){
    if((double)n > resposta)
      resposta = (double) n;
    return;
  }
  if(mat[i][j] < n)
    mat[i][j] = n;
}

int examinado[MAX];
double dist[MAX];

int FILA[MAX2];
int pe, pd;

inline void libera()
{
  pe = pd = 0;
}

inline bool vazia()
{
  return (pe == pd);
}

inline void insere(int x)
{
  FILA[pd++] = x;
  if(pd == MAX2)
    pd = 0;
}

inline int retira()
{
  int x = FILA[pe++];
  if(pe == MAX2)
    pe = 0;
  return x;
}


bool ciclo_negativo(double adic)
{
  libera();

  for(int i = 0; i < MAX; i++){
    dist[i] = 0.0;
    examinado[i] = 0;
    if(num[i] > 0)
      insere(i);
  }

  while(!vazia()){
    int i = retira();
    if(examinado[i] >= numpos)
      return true;
    examinado[i]++;
    for(int k = 0; k < num[i]; k++){
      int j = G[i][k].v;
      double c = G[i][k].c + adic;
      if(dist[j] > dist[i] + c){
	dist[j] = dist[i] + c;
	insere(j);
      }
    }
  }
  
  return false;
}

double vai()
{
  double e = 2.0, d = (double)maximo;

  while(d - e > 1.0e-2){
    double m = 0.5*(e+d);
    if(ciclo_negativo(m))
      e = m;
    else
      d = m;
  }
  return 0.5*(e+d);
}

int main()
{
  int n;
  while(1){
    scanf(" %d", &n);
    if(n == 0)
      break;

    for(int i = 0; i < MAX; i++)
      for(int j = 0; j < MAX; j++)
	mat[i][j] = 0;
    maximo = 0;
    resposta = 0;

    while(n--)
      nova_aresta();
    numpos = 0;
    for(int i = 0; i < MAX; i++){
      num[i] = 0;
      for(int j = 0; j < MAX; j++)
	if(mat[i][j] != 0){
	  G[i][num[i]].v = j;
	  G[i][num[i]].c = -mat[i][j];
	  if(mat[i][j] > maximo)
	    maximo = mat[i][j];
	  num[i]++;
	}
      if(num[i] > 0)
	numpos++;
    }

    if(resposta < 1.0 && (!ciclo_negativo(0.0)))
      printf("No solution.\n");
    else{
      double t = vai();
      if(t > resposta)
	resposta = t;
      printf("%.2lf\n", resposta);
    }
  }
  return 0;
}
