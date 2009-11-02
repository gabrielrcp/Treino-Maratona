#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 10010

int n;
vector<int> notas[MAX];
int pt[MAX];

int vai(int t)
{
  int r = 0;
  for(int i = 0; i < n; i++){
    int m = notas[i].size();
    while(pt[i] < m && notas[i][pt[i]] < t)
      pt[i]++;
    r += abs(m - 2*pt[i]);
  }
  //printf("%d %d\n", t, r);
  return r;
}

int main()
{
  while(scanf(" %d", &n) && n){
    for(int i = 0; i < n; i++){
      int m;
      scanf(" %d", &m);
      notas[i].clear();
      pt[i] = 0;
      while(m--){
	int x;
	scanf(" %d", &x);
	notas[i].push_back(x);
      }
      sort(notas[i].begin(), notas[i].end());
    }

    int r = (1 << 30);
    for(int t = 0; t <= 1000; t++)
      r = min(r, vai(t));
    printf("%d\n", r);
  }
  return 0;
}
