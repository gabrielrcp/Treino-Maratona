#include <cstdio>

#define MAX 1010

int n;
int v[MAX];
int dp[MAX];

int main()
{
  scanf(" %d", &n);
  for(int i = 0; i < n; i++)
    scanf(" %d", v+i);

  int r = 0;
  for(int i = n-1; i >= 0; i--){
    dp[i] = 1;
    for(int j = i+1; j < n; j++)
      if(v[i] < v[j] && dp[j] + 1 > dp[i])
	dp[i] = dp[j] + 1;
    if(dp[i] > r)
      r = dp[i];
  }
  printf("%d\n", r);

  return 0;
}
