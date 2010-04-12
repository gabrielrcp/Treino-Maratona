// AC

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 110

int n;
int mat[MAX][MAX];

int v[MAX];
int memo[MAX];

int resolve()
{
  int r = -2000;
  memo[n] = 0;
  for(int i = n-1; i >= 0; i--){
    memo[i] =  v[i] + max(0, memo[i+1]);
    r = max(r, memo[i]);
  }
  return r;
}

int main()
{
  scanf(" %d", &n);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf(" %d", &mat[i][j]);

  int resp = -20000;
  for(int i = 0; i < n; i++){
    for(int k = 0; k < n; k++)
      v[k] = 0;
    for(int j = i; j < n; j++){
      for(int k = 0; k < n; k++)
	v[k] += mat[j][k];
      resp = max(resp, resolve());
    }
  }

  printf("%d\n", resp);
  return 0;
}
