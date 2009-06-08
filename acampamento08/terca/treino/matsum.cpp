#include <cstdio>

#define MAX 1030

int tree[MAX][MAX];
int mat[MAX][MAX];


int n;

int read(int i, int j){
  int r = 0;
  for(int x = i; x > 0; x -= x & (-x))
    for(int y = j; y > 0; y -= y & (-y))
      r += tree[x][y];
  return r;
}

void update(int i, int j, int val)
{
  for(int x = i; x <= n; x += x & (-x))
    for(int y = j; y <= n; y += y & (-y))
      tree[x][y] += val;
}

int consulta(int x1, int y1, int x2, int y2)
{
  return read(x2, y2) + read(x1-1, y1-1) - read(x2, y1-1) - read(x1-1, y2);
}

int main()
{
  char buf[20];
  int h;
  scanf(" %d", &h);
  while(h--){

    scanf(" %d", &n);
    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= n; j++){
	tree[i][j] = 0;
	mat[i][j] = 0;
      }
    while(1){
      scanf(" %s", buf);
      if(buf[0] == 'E')
	break;
      if(buf[1] == 'E'){
	int x, y, val;
	scanf(" %d %d %d", &x, &y, &val);
	x++; y++;
	update(x, y, val - mat[x][y]);
	mat[x][y] = val;
      }
      else{
	int x1, y1, x2, y2;
	scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
	x1++; x2++; y1++; y2++;
	printf("%d\n", consulta(x1, y1, x2, y2));
      }
    }
    printf("\n");
  }
  return 0;
}
