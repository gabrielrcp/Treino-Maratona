#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100010

vector<int> G[MAX];
int n;


struct cam{
  int d;
  int a, b;
  bool operator<(const cam &o) const{
    if(d == o.d){
      if(a == o.a)
	return (b > o.b);
      return a > o.a;
    }
    return d < o.d;
  }
};

pair<int, int> dist[MAX];
cam resp[MAX];
char foi[MAX];


void dfs(int i, int p)
{
  if(foi[i])
    return;
  foi[i] = 1;
    
  dist[i] = make_pair(0, i);
  int a = -1, b = -1;
  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k];
    if(j == p) continue;
    dfs(j, i);
    if(dist[j].first+1 > dist[i].first)
      dist[i] = make_pair(dist[j].first+1, dist[j].second);
    if(a == -1)
      a = j;
    else if(b == -1 || dist[b].first < dist[j].first){
      b = j;
      if(dist[a].first < dist[b].first)
	swap(a, b);
    }
  }

  if(a == -1){
    resp[i].a = resp[i].b = i;
    resp[i].d = 0;
  } else if(b == -1){
    resp[i].a = i;
    resp[i].b = dist[a].second;
    resp[i].d = dist[i].first;
  } else{
    resp[i].a = dist[a].second;
    resp[i].b = dist[b].second;
    resp[i].d = dist[a].first + dist[b].first + 2;
  }
}

int main()
{
  freopen("island.in", "r", stdin);
  freopen("island.out", "w", stdout);

  for(int h = 1;; h++){
    int m;
    scanf(" %d %d", &n, &m);
    if(n == 0 && m == 0)
      break;
    for(int i = 0; i <= n; i++)
      G[i].clear();
    for(int i = 1; i <= n; i++)
      G[0].push_back(i);

    while(m--){
      int a, b;
      scanf("%d %d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }

    memset(foi, 0, sizeof foi);
    dfs(0, -1);

    cam r = resp[1];
    int s = 1;
    for(int i = 2; i <= n; i++){
      r = max(r, resp[i]);
      if(G[i].size() > G[s].size())
	s = i;
    }
    
    printf("Island %d: %d roads from %d to %d; square %d has %d roads\n",
	   h, r.d, r.a, r.b, s, (int)G[s].size());

  }

  return 0;
}
