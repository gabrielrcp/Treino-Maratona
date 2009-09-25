#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[50];
char memo[50][5000];

char go(int x, int y) {
	if (x == -1) return 1;

	char &ref = memo[x][y];

	if (ref == -1) {
		ref = 0;
		if (y>1) ref |= !go(x,1);
		ref |= !go(x-1,x-1>0?0:a[x-1]);
	}

	return ref;
}

int main() {
	int t;

	for (scanf("%d", &t); t--; ) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a,a+n);
		memset(memo, -1, sizeof memo);
		printf("%s\n", go(n-1, a[n-1])==1 ? "John" : "Brother");
	}

	return 0;
}
