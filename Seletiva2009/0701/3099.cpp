#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1010
#define INF (1<<30)

struct planeta{
  int id;
  int x, y, z;
};

planeta v[MAX];
vector<int> G[MAX];
int dist[MAX];
int maislonge[MAX];
int n;


inline int distancia(int i, int j)
{
  return ((v[i].x - v[j].x)*(v[i].x - v[j].x)+
	  (v[i].y - v[j].y)*(v[i].y - v[j].y)+
	  (v[i].z - v[j].z)*(v[i].z - v[j].z));
}

int maisprox(int i)
{
  int r = 0;
  int at = INF;
  for(int k = 0; k < i; k++){
    int t = distancia(k, i);
    if(t < at){
      r = k;
      at = t;
    }
  }
  return r;
}


void calculadists()
{
  queue<int> Q;
  for(int i = 0; i < n; i++){
    
    for(int j = 0; j < n; j++)
      dist[j] = -1;
    dist[i] = 0;
    Q.push(i);

    while(!Q.empty()){
      int j = Q.front(); Q.pop();
      int d = dist[j];
      maislonge[i] = d;

      for(int k = 0; k < G[j].size(); k++){
	int l = G[j][k];
	if(dist[l] == -1){
	  dist[l] = d + 1;
	  Q.push(l);
	}
      }
    }
  }
}

int main()
{
  while(1){
    scanf(" %d", &n);
    if(n == 0)
      break;
    for(int i = 0; i < n; i++)
      G[i].clear();

    for(int i = 0; i < n; i++){
      scanf(" %d %d %d %d", &v[i].id,&v[i].x, &v[i].y, &v[i].z);
      if(i != 0){
	int j = maisprox(i);
	G[i].push_back(j);
	G[j].push_back(i);
      }
    }
    
    calculadists();
    int minima = INF;
    for(int i = 0; i < n; i++)
      minima = min(minima, maislonge[i]);

    /*
    for(int i = 0; i < n; i++)
      for(int j = 0; j < G[i].size(); j++){
      }
    */
    /*
    for(int i = 0; i < n; i++)
      printf("%d\n", maislonge[i]);
    */

    vector<int> resp;
    for(int i = 0; i < n; i++)
      if(maislonge[i] == minima)
	resp.push_back(v[i].id);

    sort(resp.begin(), resp.end());   
    printf("%d", resp[0]);
    for(int i = 1; i < resp.size(); i++)
      printf(" %d", resp[i]);
    printf("\n");
    
  }
  return 0;
}
