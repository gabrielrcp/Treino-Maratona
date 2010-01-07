//PKU: 2057

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1010

vector<int> G[MAX];
int n;
bool sabe[MAX];
int folhas[MAX];
int falha[MAX];


void dfs(int i)
{
  falha[i] = folhas[i] = 0;
  for(int k = 0; k < (int)G[i].size(); k++){
    dfs(G[i][k]);
    folhas[i] += folhas[G[i][k]];
  }
  if(!sabe[i]){
    for(int k = 0; k < G[i].size(); k++){
      falha[i] += (falha[G[i][k]] + 2);
    }
  }
  if(G[i].size() == 0)
    folhas[i] = 1;
}

double tenta(int i, int falta);
double resolve(int i);

double memo2[MAX][1<<10];


inline int todos(int i)
{
  int k = G[i].size();
  return ((1<<k)-1);
}

double vai(int i, int falta)
{
  double &resp = memo2[i][falta];
  if(resp > -0.5) return resp;
  if(falta == 0) return 0.0;

  resp = 1.0e100;
  int nr = G[i].size();

  int total = 0;
  for(int k = 0; k < nr; k++)
    if((1<<k) & falta)
      total += folhas[G[i][k]];

  for(int k = 0; k < nr; k++){
    if(!((1<<k) & falta)) continue;
    int j = G[i][k];
    double p = (double)folhas[j] / total;
    double t = p * (vai(j, todos(j))+1);
    t += (1.0 - p) * (falha[j]+2.0+vai(i, falta^(1<<k)));
    resp = min(resp, t);
  }
  return resp;
}

int main()
{
  while(scanf(" %d", &n) && (n > 0)){
    for(int i = 0; i < n; i++)
      G[i].clear();
    for(int i = 0; i < n; i++){
      int j; char c;
      scanf(" %d %c", &j, &c);
      j--;
      G[j].push_back(i);
      sabe[i] = (c == 'Y');
      for(int k = 0; k < (1<<8); k++)
	memo2[i][k] = -1.0;
    }
    dfs(0);
    printf("%.4f\n", vai(0, todos(0)));
  }
}
