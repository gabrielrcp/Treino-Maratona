#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define MAX 676

struct node{
  int c;
  int v;
};

node G[MAX][MAX];
int num[MAX];
int mat[MAX][MAX];

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
    resposta = max(resposta, (double) n);
    return;
  }
  mat[i][j] = min(mat[i][j], -n);
}

int examinado[MAX];
double dist[MAX];

bool ciclo_negativo(double adic)
{
  queue<int> Q;
  //set<int> S;
  for(int i = 0; i < MAX; i++){
    dist[i] = 0.0;
    examinado[i] = 0;
    if(num[i] > 0){
      Q.push(i);
      //S.insert(i);
    }
  }

  while(!Q.empty()){
    int i = Q.front();
    Q.pop(); //S.erase(i);
    if(examinado[i] >= MAX)
      return true;
    examinado[i]++;
    for(int k = 0; k < num[i]; k++){
      int j = G[i][k].v;
      double c = G[i][k].c + adic;
      if(dist[j] > dist[i] + c){
	dist[j] = dist[i] + c;
	//if(S.find(j) == S.end()){
	Q.push(j);
	  //S.insert(j);
	  //}
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
  //e = floor(100.0 * e + 1.0e-9)*0.01;
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
    for(int i = 0; i < MAX; i++){
      num[i] = 0;
      for(int j = 0; j < MAX; j++)
	if(mat[i][j] != 0){
	  G[i][num[i]].v = j;
	  G[i][num[i]].c = mat[i][j];
	  maximo = max(-mat[i][j], maximo);
	  num[i]++;
	}
    }

    if(resposta < 1.0 && (!ciclo_negativo(0.0)))
      printf("No solution.\n");
    else
      printf("%.2lf\n", max(resposta, vai()));    
  }
  return 0;
}
