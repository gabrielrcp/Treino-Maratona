#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define MAX 1010
#define INF (1 << 30)

vector< pair<int, int> > G[MAX];
vector< pair<int, int> > inv[MAX];

int n;
int dist[MAX];
int s, f;
int mini[MAX], qmini[MAX];

void calcula_distancias()
{
  for(int i = 0; i < n; i++)
    dist[i] = INF;
  dist[f] = 0;
  queue<int> Q;
  Q.push(f);
  while(!Q.empty()){
    int i = Q.front(); Q.pop();
    int d = dist[i];
    for(int k = 0; k < inv[i].size(); k++){
      int j = inv[i][k].first;
      int c = inv[i][k].second;
      if(dist[j] > dist[i] + c){
	dist[j] = dist[i]+c;
	Q.push(j);
      }
    }
  }
}

int vai(int i)
{
  if(i == f) return 1;

  int &r = mini[i];
  if(r != -1)
    return r;
  
  r = 0;
  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k].first;
    int c = G[i][k].second;
    if(dist[i] == dist[j] + c)
      r += vai(j);
  }
  return r;
}

int vaiquase(int i)
{
  if(i == f) return 1;

  int &r = qmini[i];
  if(r != -1)
    return r;
  
  r = 0;
  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k].first;
    int c = G[i][k].second;
    if(dist[i] == dist[j] + c)
      r += vaiquase(j);
    else if(dist[i]+1 == dist[j] + c)
      r += vai(j);
  }
  return r;
}


int resolve()
{
  for(int i = 0; i < n; i++)
    mini[i] = qmini[i] = -1;

  return vaiquase(s);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int m;
    scanf(" %d %d", &n, &m);
    for(int i = 0; i < n; i++){
      G[i].clear();
      inv[i].clear();
    }
    while(m--){
      int i, j, c;
      scanf(" %d %d %d", &i, &j, &c);
      i--; j--;
      G[i].push_back(make_pair(j, c));
      inv[j].push_back(make_pair(i, c));

    }


    scanf(" %d %d", &s, &f);
    s--; f--;
    calcula_distancias();
    
    printf("%d\n", resolve());
  }
}
