#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100010

vector<int> G[MAX];
int T;
int n;

int memo[MAX];

int tmp[MAX];

int vai(int i)
{
  int nf = G[i].size();
  if(nf == 0) return 1;

  int k = nf * T;
  if(k % 100 != 0)
    k = k/100 + 1;
  else
    k /= 100;

  for(int j = 0; j < nf; j++)
    tmp[j] = memo[G[i][j]];

  sort(tmp, tmp+nf);
  int r = 0;
  for(int j = 0; j < k; j++)
    r += tmp[j];
  return r;
}

int main()
{
  while(scanf(" %d %d", &n, &T) && n > 0){

    G[0].clear();
    for(int i = 1; i <= n; i++){
      G[i].clear();      
      int j;
      scanf(" %d", &j);
      G[j].push_back(i);
    }

    for(int i = n; i >= 0; i--)
      memo[i] = vai(i);
    printf("%d\n", memo[0]);
  }
  return 0;
}
