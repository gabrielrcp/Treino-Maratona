#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100010

int a[MAX], b[MAX];
int memo[MAX];

int resolve(int *v, int n)
{

  memo[n] = 0;
  memo[n-1] = v[n-1];
  for(int i = n-2; i >= 0; i--)
    memo[i] = max(memo[i+1], memo[i+2] + v[i]);
  return memo[0];
}

int main()
{
  int n, m;
  while(1){
    scanf(" %d %d", &n, &m);
    if(n == m && m == 0)
      break;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++)
	scanf(" %d", a+j);
      b[i] = resolve(a, m);
    }
    printf("%d\n", resolve(b, n));
  }
  return 0;
}
