#include <cstdio>
#include <map>

using namespace std;

#define MAX 610
#define MAXN 310

struct node{
  int numf;
  map<int, double> comp;
  int esq, dir;
};

node corridas[MAX];
double vence[MAXN][MAXN];
int n;
bool ehraiz[MAX];

void vai(int r)
{
  int e = corridas[r].esq;
  int d = corridas[r].dir;

  map<int, double> &cp = corridas[r].comp;
  cp.clear();

  if(r < n){
    cp[r] = 1.0;
    return;
  }

  vai(e);
  vai(d);

  map<int, double>::iterator it, jt;
  map<int, double> &S = corridas[e].comp;
  map<int, double> &T = corridas[d].comp;


  for(it = S.begin(); it != S.end(); it++){
    double p = 0.0;
    for(jt = T.begin(); jt != T.end(); jt++)
      p += jt->second * vence[it->first][jt->first];
    p *= it->second;
    cp[it->first] = p;
  }
  for(it = T.begin(); it != T.end(); it++){
    double p = 0.0;
    for(jt = S.begin(); jt != S.end(); jt++)
      p += jt->second * vence[it->first][jt->first];
    p *= it->second;
    cp[it->first] = p;
  }
}

int main()
{
  while(1){
    scanf(" %d", &n);
    if(n == 0) break;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	scanf(" %lf", &vence[i][j]);

    for(int k = n; k < 2*n-1; k++)
      ehraiz[k] = true;

    for(int k = n; k < 2*n-1; k++){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      ehraiz[i] = ehraiz[j] = false;
      corridas[k].esq = i;
      corridas[k].dir = j;
    }

    int r = n;
    while(!ehraiz[r]) r++;

    vai(r);
    printf("%f\n", corridas[r].comp[0]);
      
  }
  return 0;
}
