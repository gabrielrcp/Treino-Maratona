#include <cstdio>
#include <vector>

using namespace std;

#define MAX 100010
#define INF (1<<29)

struct node{
  int dest;
  int at, melhor;
};

vector< vector<node> > G;
vector<int> pai;
int n;

int minimo[MAX];
int atual[MAX];


void monta(int i)
{
  minimo[i] = atual[i] = 0;
  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k].dest;
    if(pai[i] != j && pai[j] == -1){
      pai[j] = i;
      monta(j);
      minimo[i] = max(minimo[i], minimo[j] + G[i][k].melhor);
      atual[i]  = max(atual[i],  atual[j]  + G[i][k].at);
    }
  }
}

int gasta(int i, int target)
{
  if(minimo[i] > target)
    return INF;
  if(atual[i] <= target)
    return 0;
  
  int r = 0;
  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k].dest;
    if(pai[i] == j) continue;

    int x = G[i][k].at + atual[j];
    if(x <= target)
      continue;
    int t = G[i][k].at - G[i][k].melhor;
    if(atual[j] <= target - G[i][k].melhor)
      r += x - target;
    else
      r += t + gasta(j, target-G[i][k].melhor);
  }
  return r;
}


int main()
{
  int k;
  scanf(" %d %d", &n, &k);
  G = vector< vector<node> > (n);
  pai = vector<int> (n, -1);

  for(int k = 1; k < n; k++){
    int i, j, o, a;
    scanf(" %d %d %d %d", &i, &j, &a, &o);
    i--; j--;

    node novo;
    novo.at = a;
    novo.melhor = o;
    
    novo.dest = j;
    G[i].push_back(novo);

    novo.dest = i;
    G[j].push_back(novo);
  }

  monta(0);

  int e = 0, d = INF;
  while(e < d){
    int m = (e+d)/2;
    if(gasta(0, m) <= k)
      d = m;
    else
      e = m + 1;
  }
  printf("%d\n", e);
  return 0;
}
