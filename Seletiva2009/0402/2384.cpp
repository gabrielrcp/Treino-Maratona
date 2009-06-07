#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

#define MAX 30

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

char mapa[MAX][MAX];
int dist[MAX][MAX][MAX][MAX];
int n;

inline bool adjacente(pair<int, int> a, pair<int, int> b)
{
  return ((abs(a.first - b.first) + abs(a.second - b.second)) == 1);
}


int main()
{
  scanf(" %d", &n);
  for(int i = 0; i <= n+1; i++)
    mapa[i][0] = mapa[i][n+1] = mapa[0][i] = mapa[n+1][i] = '#';
  int destx, desty;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      char c;
      scanf(" %c", &c);
      if(c == '*'){
	destx = i;
	desty = j;
	c = '.';
      }
      mapa[i][j] = c;
    }
  }
  /*
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++)
      printf("%c", mapa[i][j]);
    printf("\n");
  }
  */
  
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      for(int k = 1; k <= n; k++)
	for(int l = 1; l <= n; l++)
	  dist[i][j][k][l] = -1;

  queue< pair< pair<int, int> , pair<int, int> > > Q;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(mapa[i][j] == '.' && (i != destx || j != desty)){
	Q.push(make_pair(make_pair(i,j), make_pair(destx, desty)));
	dist[i][j][destx][desty] = 0;
      }

  int resp = 0;

  while(!Q.empty()){
    int px, py, bx, by;
    pair< pair<int, int> , pair<int, int> > PP;
    PP = Q.front();
    Q.pop();

    px = PP.first.first;
    py = PP.first.second;
    bx = PP.second.first;
    by = PP.second.second;
    int d = dist[px][py][bx][by];
    //printf("%d %d %d %d - %d\n", px, py, bx, by, d);
    resp = max(resp, d);
    //printf("--%d %d %d %d\n", px, py, bx, by);

    for(int k = 0; k < 4; k++){
      int nx = px+dx[k];
      int ny = py+dy[k];
      if(mapa[nx][ny] == '.' && (nx != bx || ny != by) &&
	 dist[nx][ny][bx][by] == -1){
	dist[nx][ny][bx][by] = d+1;
	Q.push(make_pair(make_pair(nx, ny), make_pair(bx, by)));
      }
    }

    if(adjacente(make_pair(px, py), make_pair(bx, by))){
      int ix = px - bx;
      int iy = py - by;

      int nx = px + ix;
      int ny = py + iy;
      if(mapa[nx][ny] == '.' && dist[nx][ny][px][py] == -1){
	//printf("%d\n", d);
	dist[nx][ny][px][py] = d + 1;
	Q.push(make_pair(make_pair(nx, ny), make_pair(px, py)));
      }
    }
  }
  printf("%d\n", resp);



  return 0;
}
