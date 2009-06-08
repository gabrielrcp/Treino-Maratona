#include <cstdio>

#define MAX 1030

long long tree[MAX][MAX];

int n;

long long read(int i, int j){
  long long r = 0;
  
  for(int x = i; x > 0; x -= x & (-x))
    for(int y = j; y > 0; y -= y & (-y))
      r += tree[x][y];

  //printf("**%d %d %lld\n", i, j, r);
  return r;
}

void update(int i, int j, long long val)
{
  for(int x = i; x <= n; x += x & (-x))
    for(int y = j; y <= n; y += y & (-y))
      tree[x][y] += val;
}

long long consulta(int x1, int y1, int x2, int y2)
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
      for(int j = 0; j <= n; j++)
	tree[i][j] = 0;
    while(1){
      scanf(" %s", buf);
      if(buf[0] == 'E')
	break;
      if(buf[1] == 'E'){
	int x, y;
	long long val, at;
	scanf(" %d %d %lld", &x, &y, &val);
	x++; y++;
	at = consulta(x, y, x, y);
	val -= at;
	//printf("-- %d %d %lld\n", x, y, at);
	update(x, y, val);

      }
      else{
	int x1, y1, x2, y2;
	scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
	x1++; x2++; y1++; y2++;
	printf("%lld\n", consulta(x1, y1, x2, y2));
      }
      /*     
      for(int i = 1; i <= n; i++){
	for(int j = 1; j <= n; j++)
	  printf(" %lld",tree[i][j]);
	printf("\n");
      } 
      printf("\n");
      */
    }
    printf("\n");
  }
  return 0;
}
