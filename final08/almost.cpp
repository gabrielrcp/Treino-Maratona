#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define MAX 500
#define INF 1 << 29

/*
BELLMAN-FORD
void vai(int s, vector< vector< pair<int, int> > > &G, int *dist)
{
     queue<int> Q;
     for(int i = 0; i < n; i++)
             dist[i] = INF;
     dist[s] = 0;
     Q.push(s);
     while(!Q.empty()){
                       int i = Q.front();
                       Q.pop();
                       int d = dist[i];
                       for(int k = 0; k < G[i].size(); k++){
                               int j = G[i][k].first;
                               int c = G[i][k].second;
                               if(dist[j] > d + c){
                                          dist[j] = d + c;
                                          Q.push(j);
                               }
                       }
     }
}
*/


/*
DIJSTKA QUADRATICO
bool foi[MAX];
int minimo(int *dist)
{
    int i = 0;
    while(i < n && foi[i]) i++;
    for(int j = i + 1; j < n; j++){
            if(!foi[j] && dist[j] < dist[i])
                       i = j;
    }
    return i;
}

void vai(int s, vector< vector< pair<int, int> > > &G, int *dist)
{
     for(int i = 0; i < n; i++){
             dist[i] = INF;
             foi[i] = false;
     }
     dist[s] = 0;
     for(int h = 0; h < n; h++){
             int i = minimo(dist);
             int d = dist[i];
             foi[i] = true;
             for(int k = 0; k < G[i].size(); k++){
                     int j = G[i][k].first;
                     int c = G[i][k].second;
                     if(dist[j] > d + c)
                                dist[j] = d + c;
             }
     }
}
*/

int y[MAX], z[MAX];
vector< vector< pair<int, int> > > Gdir;
vector< vector< pair<int, int> > > Ginv;
int n;

//DIJSTKA fila de prioridade
void vai(int s, vector< vector< pair<int, int> > > &G, int *dist)
{
     set< pair<int,int> > Q;
     for(int i = 0; i < n; i++)
             dist[i] = INF;
     dist[s] = 0;
     Q.insert(make_pair(0, s));
     while(!Q.empty()){
          int i = Q.begin()->second;
          int d = Q.begin()->first;
          Q.erase(Q.begin());
          if(d > dist[i]) continue;
          for(int k = 0; k < G[i].size(); k++){
                  int j = G[i][k].first;
                  int c = G[i][k].second;
                  if(dist[j] > d + c){
                             dist[j] = d + c;
                             Q.insert(make_pair(d+c, j));
                  }
          }
     }
}


int main()
{
    int m;
    int s, t;
    while(1){
             scanf(" %d %d", &n, &m);
             if(n == 0 && m == 0) break;
             scanf(" %d %d", &s, &t);
             Gdir = vector< vector< pair<int, int> > > (n, vector< pair<int, int> > ());
             Ginv = vector< vector< pair<int, int> > > (n, vector< pair<int, int> > ());
             while(m--){
                        int i, j, c;
                        scanf(" %d %d %d", &i, &j, &c);
                        Gdir[i].push_back(make_pair(j, c));
                        Ginv[j].push_back(make_pair(i, c));
             }
             vai(s, Gdir, y);
             vai(t, Ginv, z);
             for(int i = 0; i < n; i++){
                     for(int k = 0; k < Gdir[i].size(); k++){
                             int j = Gdir[i][k].first;
                             int c = Gdir[i][k].second;
                             if(y[t] == y[i] + c + z[j]) Gdir[i][k].second = INF;
                     }
             }
             vai(s, Gdir, y);
             if(y[t] == INF)
                 printf("-1\n");
             else
                 printf("%d\n", y[t]);
    }
    return 0;
}
