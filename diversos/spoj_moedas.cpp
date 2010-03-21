#include <cstdio>
#include <algorithm>

using namespace std;

#define INF (1<<30)

int dp[50010];
int v[110];

int main()
{
  int n, m;
  while(scanf(" %d", &m) && m){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", v+i);

    dp[0] = 0;
    for(int x = 1; x <= m; x++){
      dp[x] = INF;
      for(int i = 0; i < n; i++){
	if(v[i] > x)
	  break;
	dp[x] = min(dp[x], 1+dp[x-v[i]]);
      }
    }
    if(dp[m] == INF)
      printf("Impossivel\n");
    else
      printf("%d\n", dp[m]);
  }
  return 0;
}
