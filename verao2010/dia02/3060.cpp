#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1010

int conta[MAX][MAX];
int cx[MAX], cy[MAX];
int n, d;

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d", &d, &n);
    memset(conta, 0, sizeof conta);
    memset(cx, 0, sizeof cx);
    memset(cy, 0, sizeof cy);

    for(int i = 0; i < n; i++){
      int x, y;
      scanf(" %d %d", &x, &y);
      x = (((x%d) + d)%d);
      y = (((y%d) + d)%d);
      conta[x][y]++;
      cx[x]++;
      cy[y]++;
    }

    int resp = (1 << 30);
    for(int i = 0; i < d; i++)
      for(int j = 0; j < d; j++)
	resp = min(resp, cx[i] + cy[j] - conta[i][j]);
    printf("%d\n", resp);
  }
  return 0;
}
