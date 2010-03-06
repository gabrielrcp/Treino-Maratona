#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX (110)

int dist[MAX];
int n;
vector<int> G[MAX];
typedef pair<int, int> pii;

int main()
{
  int a, b;
  scanf(" %d %d %d", &n, &a, &b);
  a--; b--;

  for(int i = 0; i < n; i++){
    int m;
    scanf(" %d", &m);
    G[i].clear();
    while(m--){
      int x;
      scanf(" %d", &x);
      x--;
      G[i].push_back(x);
    }
  }

  memset(dist, 0x3f, sizeof dist);
  dist[a] = 0;

  priority_queue <pii, vector<pii>, greater<pii> > Q;
  Q.push(make_pair(0, a));

  while(!Q.empty()){
    int i = Q.top().second;
    int dd = Q.top().first;
    Q.pop();
    if(dist[i] != dd) continue;

    for(int k = 0; k < (int)G[i].size(); k++){
      int j = G[i][k];
      int d = dist[i] + ((k == 0) ? 0 : 1);
      if(dist[j] > d){
	dist[j] = d;
	Q.push(make_pair(d,j));
      }
    }
  }
  printf("%d\n", (dist[b] > n ? -1 : dist[b]));

  return 0;
}
