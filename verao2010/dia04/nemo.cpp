// PKU: 2049

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 250

int mapa[MAX][MAX][2];
int dist[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
  int m, n;
  while(scanf(" %d %d", &m, &n) && (n != -1 || m != -1)){

    memset(mapa, 0, sizeof mapa);
    while(m--){
      int x, y, d, t;
      scanf(" %d %d %d %d", &x, &y, &d, &t);
      for(int i = 0; i < t; i++)
	mapa[x+(1-d)*i][y+d*i][d] = 1;
    }
    while(n--){
      int x, y, d;
      scanf(" %d %d %d", &x, &y, &d);
      mapa[x][y][d] = 2;
    }
    double ff1, ff2;
    scanf(" %lf %lf", &ff1, &ff2);
    
    int fx = (int)(ff1+1.0e-9), fy = (int)(ff2+1.0e-9);

    if(fx >= MAX || fy >= MAX){
      printf("0\n");
      continue;
    }

    queue<pair <int, int> > Q;
    Q.push(make_pair(0, 0));
    memset(dist, 0x3f, sizeof dist);
    dist[0][0] = 0;

    while(!Q.empty()){
      int x = Q.front().first;
      int y = Q.front().second;
      Q.pop();
      int d = dist[x][y];

      for(int k = 0; k < 4; k++){
	int nx = x + dx[k];
	int ny = y + dy[k];
	if(nx <  0 || nx >= MAX || ny < 0 || ny >= MAX)
	  continue;
	int px = x, py = y;
	if(dx[k] == 1) px++;
	if(dy[k] == 1) py++;
	int dd = ((dx[k] == 0) ? 0 : 1);
	if(px <  0 || px >= MAX || py < 0 || py >= MAX)
	  continue;
	if(mapa[px][py][dd] == 1) continue;
	int c = ((mapa[px][py][dd] == 2) ? 1 : 0);
	if(dist[nx][ny] > d + c){
	  dist[nx][ny] = d + c;
	  Q.push(make_pair(nx, ny));
	}
      }
    }

    int r = dist[fx][fy];
    if(r == 0x3f3f3f3f) r = -1;
    printf("%d\n", r);
  }
  return 0;
}
