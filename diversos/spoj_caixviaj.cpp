#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX (110)

int n;
char fim[MAX];

int mat[MAX][MAX];

int memo[MAX][1010];

int vai(int i, int t)
{
  int &r = memo[i][t];
  if(r != -1) return r;

  if(t == 0){
    r = (fim[i] ? 0 : (-(1<<30)));
    return r;
  }

  r = 0;
  for(int j = 0; j < n; j++)
    r = max(r, mat[i][j] + vai(j, t-1));

  return r;
}

int main()
{
  while(scanf(" %d", &n) && n){
    int s, e, t;
    scanf(" %d %d %d", &s, &e, &t);
    s--;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	scanf(" %d", &mat[i][j]);
    memset(fim, 0, sizeof fim);
    while(e--){
      int x;
      scanf(" %d", &x);
      fim[x-1] = 1;
    }
    memset(memo, -1, sizeof memo);
    printf("%d\n", vai(s, t));
  }
  return 0;
}
