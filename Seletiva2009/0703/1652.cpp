
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define MAX 110

char matriz[MAX][MAX];
int numera[MAX][MAX];
int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool vis[MAX][MAX];

int floodfill(int i, int j, int cp)
{
  if(numera[i][j] != -1 || matriz[i][j] == '.')
    return 0;

  numera[i][j] = cp;
  int r = 1;
  for(int k = 0; k < 4; k++)
    r += floodfill(i+dx[k], j+dy[k], cp);
  return r;
}


void vai(int i, int j, int cp)
{
  if(i < 0 || i > n+1 || j < 0 || j > m+1)
    return;
  if(vis[i][j] || numera[i][j] == cp)
    return;
  
  vis[i][j] = true;
  for(int k = 0; k < 4; k++)
    vai(i+dx[k], j+dy[k], cp);
}

int contaburacos(int cp)
{
  for(int i = 0; i <= n+1; i++)
    for(int j = 0; j <= m+1; j++)
      vis[i][j] = false;

  vai(0, 0, cp);
  int r = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      if(numera[i][j] != cp && (!vis[i][j])){
	vai(i, j, cp);
	r++;
      }
  return r;
}


int main()
{
  scanf(" %d %d", &m, &n);
  for(int i = 0; i <= n; i++){
    matriz[i][0] = matriz[i][m+1] = '.';
    numera[i][0] = numera[i][m+1] = -1;
  }
  for(int j = 0; j <= m; j++){
    matriz[0][j] = matriz[n+1][j] = '.';
    numera[0][j] = numera[n+1][j] = -1;
  }

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
      scanf(" %c", &matriz[i][j]);
      numera[i][j] = -1;
    }

  int cp = 0;
  int mbur = 0, marea = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      if(matriz[i][j] == '*' && numera[i][j] == -1){
	int area = floodfill(i, j, cp);
	int bur = contaburacos(cp);

	if(bur > mbur || (bur == mbur && area < marea)){
	  marea = area;
	  mbur = bur;
	}
	cp++;
      }

  printf("%d\n", marea); 
  return 0;
}
