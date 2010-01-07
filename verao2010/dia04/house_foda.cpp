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

double memo[MAX];

struct frac{
  int n, d, v;
};

bool compara(const frac &a, const frac &b)
{
  return a.n * b.d < a.d * b.n;
}


double vai(int i)
{
  double &resp = memo[i];
  if(resp > -0.5) return resp;

  int nr = G[i].size();
  vector<frac> v (nr);

  for(int k = 0; k < nr; k++){
    v[k].n = falha[G[i][k]]+2;
    v[k].d = folhas[G[i][k]];
    v[k].v = G[i][k];
  }
  
  sort(v.begin(), v.end(), compara);

  resp = 0.0;
  int t = 0;
  for(int k = 0; k < nr; k++){
    int j = v[k].v;    
    double p = (double) folhas[j] / folhas[i];
    resp += p * (t + vai(j) + 1);
    t += falha[j] + 2 ;
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
      memo[i] = -1.0;
    }
    dfs(0);
    printf("%.4f\n", vai(0));
  }
}
