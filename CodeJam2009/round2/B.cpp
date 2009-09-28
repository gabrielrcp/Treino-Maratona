#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;


int n, m, f;
char mapa[60][60];
int dist[60][60][(1<<6)];

struct estado{
  int i, j, c;
};

int dmin;

int cair(int i, int j)
{
  int k = i+1;
  while(k < n && mapa[k+1][j] == '.')
    k++;
  return k - i;
}


void resolve()
{
  dmin = -1;
  int inii = cair(0, 0);
  if(inii > f) return;

  dist[inii][0][0] = 0;
  queue< estado > Q;
  Q.push((estado){inii, 0, 0});

  while(!Q.empty()){
    int i = Q.front().i;
    int j = Q.front().j;
    int c = Q.front().c;
    int d = dist[i][j][c];
    Q.pop();
    for(int dx = -1; dx <= 1; dx += 2){
      if(j+dx < 0 || j+dx >= m) continue;

      if(mapa[i][j+dx] == '#' && j+dx != c) continue;

      if(mapa[i+1][j+dx] == '#'){
	if(dist[i][j+dx][c] == -1 || dist[i][j+dx][c] > d){
	  dist[i][j+dx][c] = d;
	  Q.push((estado){i, j+dx, c});
	}
      }

      int ad = (mapa[i+1][j+dx] == '#' ? 1 : 0);
      int l = cair(i, j+dx);
      if(l > f) continue;
      if(i+l == n)
	dmin = d+ad;
      if(dist[i+l][j+dx][j+dx] == -1 || dist[i-1][j+dx][j+dx] > d+ad){
	dist[i+l][j+dx][j+dx] = d+ad;
	if(i+l < n)
	  Q.push((estado){i+l, j+dx, j+dx});
      }
    }
  }
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d %d %d", &n, &m, &f);
    for(int j = 0; j < m; j++){
      for(int c = 0; c < m; c++){
	dist[0][j][c] = -1;
      }
      mapa[0][j] = '.';
    }
    for(int i = 1; i <= n; i++)
      for(int j = 0; j < m; j++){
	scanf(" %c", &mapa[i][j]);
	for(int c = 0; c < (1<<m); c++)
	  dist[i][j][c] = -1;
      }

    resolve();
    printf("Case #%d: ", h);
    if(dmin >= 0)
      printf("Yes %d\n", dmin);
    else
      printf("No\n");
  }
  return 0;
}
