#include <cstdio>
#include <queue>

using namespace std;

int dist[105][105][1<<4];
int n, m;
char mapa[105][105];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

struct estado{
  int x, y, c;
};

inline void vai(int x, int y, int c, int d, queue<estado> &Q){
  estado e;
  if(dist[x][y][c] == -1){
    dist[x][y][c] = d;
    e.x = x; e.y = y; e.c = c;
    Q.push(e);
  }
}

int main()
{
  while(1){
    scanf(" %d %d", &n, &m);
    if(m == n && n == 0)
      break;
    estado e;
    e.c = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
	scanf(" %c", &mapa[i][j]);
	for(int c = 0; c < (1 << 4); c++)
	  dist[i][j][c] = -1;
	if(mapa[i][j] == '*'){
	  mapa[i][j] = '.';
	  e.x = i; e.y = j;
	  dist[i][j][0] = 0;
	}
      }

    int resp = -1;

    queue<estado> Q;
    Q.push(e);
    while((!Q.empty()) && resp == -1){
      e = Q.front();
      Q.pop();
      int x = e.x;
      int y = e.y;
      int c = e.c;
      int d = dist[x][y][c];
      for(int k = 0; k < 4; k++){
	int nx = x + dx[k];
	int ny = y + dy[k];
	if(nx < 0 || nx >= n || ny < 0 || ny >= m)
	  continue;
	switch(mapa[nx][ny]){
	case '#':
	  break;
	case'b':
	  vai(nx, ny, c | (1 << 0), d+1, Q);
	  break;
	case'y':
	  vai(nx, ny, c | (1 << 1), d+1, Q);
	  break;
	case'r':
	  vai(nx, ny, c | (1 << 2), d+1, Q);
	  break;
	case'g':
	  vai(nx, ny, c | (1 << 3), d+1, Q);
	  break;
	case 'B':
	  if(c & (1 << 0))
	    vai(nx, ny, c, d+1, Q);
	  break;
	case 'Y':
	  if(c & (1 << 1))
	    vai(nx, ny, c, d+1, Q);
	  break;
	case 'R':
	  if(c & (1 << 2))
	    vai(nx, ny, c, d+1, Q);
	  break;
	case 'G':
	  if(c & (1 << 3))
	    vai(nx, ny, c, d+1, Q);
	  break;
	case '.':
	  vai(nx, ny, c, d+1, Q);
	  break;
	case 'X':
	  resp = d + 1;
	  break;
	}
      }
    }
    if(resp == -1)
      printf("The poor student is trapped!\n");
    else
      printf("Escape possible in %d steps.\n", resp);
  }
  return 0;  
}
