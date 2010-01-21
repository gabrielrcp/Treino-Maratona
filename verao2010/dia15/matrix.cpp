#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

#define INF (1<<30)

int mat[110][110];
int dist[110][110][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
  freopen("matrix.in", "r", stdin);
  freopen("matrix.out", "w", stdout);

  int n, k;
  scanf(" %d %d", &n, &k);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf(" %d", &mat[i][j]);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      dist[i][j][0] = dist[i][j][1] = -INF;

  dist[0][0][0] = 0;
  for(int a = 1; a <= k; a++){
    int t = (a&1);
    int s = 1 - t;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	dist[i][k][t] = -INF;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
    	for(int m = 0; m < 4; m++){
	  int x = i + dx[m];
	  int y = j + dy[m];
	  if(x < 0 || x >= n || y < 0 || y >= n)
	    continue;
	  dist[x][y][t] = max(dist[x][y][t],
			      dist[i][j][s] + mat[i][j]);
	}
  }

  int r = 0;
  k &= 1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      r = max(r, dist[i][j][k]);
  printf("%d\n", r);

  return 0;
}
