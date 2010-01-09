#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int r[24];
int c[24];

vector< pair<int, int> > G[25];

int dist[25];

bool tenta(int total)
{
  for(int i = 0; i < 25; i++)
    G[i].clear();
  
  for(int i = 1; i < 25; i++)
    G[i].push_back(make_pair(i-1, 0));
  for(int i = 0; i < 24; i++)
    G[i].push_back(make_pair(i+1, c[i]));

  
  for(int i = 0; i + 7 < 24; i++)
    G[i+8].push_back(make_pair(i, -r[i+7]));
  for(int i = 17; i < 24; i++)
    G[(i+8)%24].push_back(make_pair(i, total - r[(i+7)%24]));


  G[0].push_back(make_pair(24, total));
  G[24].push_back(make_pair(0, -total));


  bool achei = true;
  memset(dist, 0, sizeof dist);
  for(int it = 0; it <= 25 && achei; it++){
    achei = false;
    for(int i = 0; i <= 24; i++){
      for(int k = 0; k < (int)G[i].size(); k++){
	int j = G[i][k].first;
	int cc = G[i][k].second;
	if(dist[j] > dist[i] + cc){
	  dist[j] = dist[i] + cc;
	  achei = true;
	}
      }
    }
  }
  return (!achei);
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    for(int i = 0; i < 24; i++)
      scanf(" %d", r+i);
    memset(c, 0, sizeof c);
  
    int n;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      int x;
      scanf(" %d", &x);
      c[x]++;
    }

    if(!tenta(n)){
      printf("No Solution\n");
      continue;
    }

    int resp = 0;
    while(!tenta(resp))
      resp++;
    printf("%d\n", resp);
  }
  return 0;
}
