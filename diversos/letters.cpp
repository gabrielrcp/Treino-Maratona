#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;

char mat[25][25];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char vai(int i, int j, int msk)
{
  if(msk & (1<<mat[i][j]))
    return 0;

  msk |= (1<<mat[i][j]);

  char r = 1;
  for(int k = 0; k < 4; k++){
    int x = i+dx[k];
    int y = j+dy[k];
    if(x < 0 || x >= n) continue;
    if(y < 0 || y >= m) continue;
    r = max((int)r, vai(x, y, msk)+1);
  }
  return r;
}

int main()
{
  scanf(" %d %d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf(" %s", mat[i]);
    for(int j = 0; j < m; j++)
      mat[i][j] -= 'A';
  }

  printf("%d\n", vai(0, 0, 0));

  return 0;
}
