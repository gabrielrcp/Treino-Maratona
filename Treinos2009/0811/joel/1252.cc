#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m;
int dp[10010];

int main() {
	int t;

	for (scanf("%d", &t); t--;) {
		memset(dp,0x3f,sizeof dp);
		dp[0] = 0;
		for (int i = 0; i < 6; ++i) {
			scanf("%d", &m);
			for (int i = m; i <= 10000; ++i)
				dp[i] = min(dp[i], dp[i-m]+1);
		}
		
		double media = 0;
		int maxi = 0;
		for (int i = 1; i <= 100; ++i) {
			int tmp = 110;
			for (int j = i; j <= 10000; ++j) {
				tmp = min(dp[j]+dp[j-i], tmp);
			}
			media += tmp;
			maxi = max(tmp, maxi);
		}
		media /= 100.0;
		printf("%.2f %d\n", media, maxi);
	}

	return 0;
}
